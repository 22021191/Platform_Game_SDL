#include"Game.h"
Game::Game() {
	map = new Map();
	Level = 1;
	id = 1;
	Playerid = 1;
	player = new Player(id,{ 150,200 }, { 200,200 }, true);
	menu = new Menu();
	text = new Text();
	Opt = new Texture();
	Back = new Button(0, "Back", { 0,0 });

}
Game::~Game() {
	delete map;
	delete menu;
	delete player;
	delete text;
	delete Opt;
	Back=nullptr;
	delete win;
	delete over;
}
void Game::GameLoop() {

	GameType stateGame = MenuGame;
	while (true)
	{
		switch (stateGame)
		{
		case MenuGame:
			SDL_Event e;
			if (menu != nullptr) {
				menu->~Menu();
			}
			if (player != nullptr) {
				player->~Player();
				/*delete player;*/
			}
			menu = new Menu();
			player = new Player(id,{ 150,150 }, { 200,200 }, true);
			Mix_PlayChannel(1, music_Menu, -1);
			while (true)
			{
				int i = id;
				if (SDL_PollEvent(&e) == 0);
				if (e.type == SDL_QUIT) return;
				menu->Render();
				player->UpdateMove(30);
				player->Render();
				SDL_RenderPresent(renderer);
				menu->handle(e,stateGame,i);
				SDL_Delay(30);
				if (stateGame != MenuGame) {
					break;
					std::cout << "ok";
				}
				if (i != id&&i!=0&&i!=3) {
					id = i;
					break;
				}
			}
			break;
		case PlayGame:
			Mix_PlayChannel(1, music_Menu, -1);
			SDL_Event ev;
			if (map != nullptr) {
				delete map;
			}
			if (player != nullptr) {
				delete player;
			}

			player = new Player(id,{ 50,50 }, { 50,50 }, true);
			map = new Map();
			map->loadMap("Map//map0"+std::to_string(Level)+".txt");
			while (true) {
				if (player->WallCheck == true) std::cout << "ok" << std::endl;
				if (SDL_PollEvent(&ev) == 0) player->IsJump = false;
				map->Render();
				player->Render();
				map->Ground_Check_Player(player);
				SDL_RenderPresent(renderer);
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
				SDL_RenderClear(renderer);
				map->Update(30);
				if (ev.type == SDL_KEYDOWN) {
					switch (ev.key.keysym.sym)
					{
					case SDLK_RIGHT:
						player->IsMove = true;
						player->face_Right = false;
						break;
					case SDLK_LEFT:
						player->IsMove = true;
						player->face_Right = true;
						break;
					case SDLK_SPACE:
						player->IsJump = false;
					default:
						break;
					}
				}
				if (ev.type == SDL_KEYUP) {
					switch (ev.key.keysym.sym)
					{
					case SDLK_RIGHT:
						player->IsMove = false;
						break;
					case SDLK_LEFT:
						player->IsMove = false;
						break;
					case SDLK_SPACE:
						player->IsJump = true;
					default:

						break;
					}
				}
				if (!player->die) {
					player->PlayerMove();
				}
				else {

					stateGame = GameOver;
					break;
				}
				map->Meteotie_check_Player(player);
				map->Wall_check_Player(player);
				if (map->LevelUp) {
					stateGame = WinGame;
					break;
				}
				//std::cout << player->velocity.first << std::endl;
				//cout << player->getPosition().first<<endl;
				if (ev.type == SDL_QUIT) return;
				map->Bullet_check_player(player);
				SDL_Delay(10);
			}
			break;
		case GameOption:
			Back->setSize({ 75, 50 });
			SDL_DestroyTexture(Opt->mTexture);
			Opt->loadFromFile("Opt.png");
			Opt->setPosition({0, 0});
			Opt->setSize({ 1000,560 });
			SDL_Event i;
			while (true)
			{
				if (SDL_PollEvent(&i) == 0);
				if (i.type == SDL_MOUSEBUTTONDOWN) {
					int x, y;
					SDL_GetMouseState(&x, &y);
					if (Back->rect.x < x && x < Back->rect.x + Back->rect.w && Back->rect.y < y && y < Back->rect.y + Back->rect.h) {
						Mix_PlayChannel(-1, Click, 0);

					}
				}
				else {
					Back->ButtonId = 0;
				}
				if (i.type == SDL_MOUSEBUTTONUP) {
					int x, y;
					SDL_GetMouseState(&x, &y);
					if (Back->rect.x < x && x < Back->rect.x + Back->rect.w && Back->rect.y < y && y < Back->rect.y + Back->rect.h) {
						stateGame = MenuGame;

					}
				}

				SDL_RenderClear(renderer);
				Opt->render(false);
				Back->Render();
				SDL_RenderPresent(renderer);
				if (i.type == SDL_QUIT) return;
				if (stateGame != GameOption) {
					SDL_DestroyTexture(Opt->mTexture);
					break;
				}
			}
			break;
		case EndGame:
			return;
		case GameOver:
			SDL_Event even;
			if (over != nullptr) {
				delete over;
			}
			over = new Gameover();
			Mix_PlayChannel(1,music_Gameover, -1);
			while (true) {
				if (SDL_PollEvent(&even) == 0);
				if (even.type == SDL_QUIT) return;
				//player->PlayerMove();
				map->Render();
				player->Render();
				over->Render();
				SDL_RenderPresent(renderer);
				over->handle(even, stateGame);
				SDL_Delay(30);
				if (stateGame != GameOver) {
					std::cout << Level << std::endl;
					break;
				}
			}
			break;
		case WinGame:
			SDL_Event eve;
			if (win != nullptr) {
				delete win;
			}
			win = new LevelComplete(Level);
			Mix_PlayChannel(1, music_Gameover, -1);
			while (true) {
				if (SDL_PollEvent(&eve) == 0);
				if (eve.type == SDL_QUIT) return;
				//player->PlayerMove();
				map->Render();
				player->Render();
				win->Render();
				SDL_RenderPresent(renderer);
				win->handle(eve, stateGame, Level);
				SDL_Delay(30);
				if (stateGame != WinGame) {
					delete win;
					break;
				}
			}
			break;
		default:
			return;
		}

	}
}