#include"Menu.h"
Button::Button(const Uint32& Id, std::string Name,std::pair<int,int> Position) {
	setPosition(Position);
	ButtonId = Id;
	ButtonName = Name;
	loadFromFile("Sprite//menu//"+Name + std::to_string(Id) + ".png");
	setSize({ 200,100 });
}
void Button::Render() {
	SDL_DestroyTexture(mTexture);
	loadFromFile("Sprite//menu//" + ButtonName + std::to_string(ButtonId) + ".png");
	render(false);
}
Button::~Button() {
	free();
}
Menu::Menu() {
	BackGround = new Texture();
	BackGround->loadFromFile("BackGround.png");
	BackGround->setSize({ 1000,560 });
	BackGround->setPosition({ 0,0 });
	Play = new Button(0, "Play", { 650,100 });
	Option = new Button(0, "Option", { 650,260 });
	Exit = new Button(0, "Exit", { 650,420 });
	Next = new Button(0, "next", { 400,250 });
	Next->setSize({ 75,50 });
	Previous = new Button(0, "previous", { 50,250 });
	Previous->setSize({ 75,50 });
	
}
Menu::~Menu() {
	BackGround->~Texture();
	Play->~Button();
	Option->~Button();
	Exit->~Button();
	Next->~Button();
	Previous->~Button();
}
void Menu::Render() {
	BackGround->render(false);
	Play->Render();
	Option->Render();
	Exit->Render();
	Next->Render();
	Previous->Render();
}
void Menu::handle(SDL_Event& ev, GameType& state,int& id) {
	if (ev.type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState(&x, &y);
		if (Play->rect.x < x && x < Play->rect.x + Play->rect.w && Play->rect.y < y && y < Play->rect.y + Play->rect.h) {
			Play->ButtonId = 1;
			Mix_PlayChannel(-1, Click, 0);
			
		}
		if (Exit->rect.x < x && x < Exit->rect.x + Exit->rect.w && Exit->rect.y < y && y < Exit->rect.y + Exit->rect.h) {
			Exit->ButtonId = 1;
			Mix_PlayChannel(-1, Click, 0);
			

		}
		if (Option->rect.x < x && x < Option->rect.x + Option->rect.w && Option->rect.y < y && y < Option->rect.y + Option->rect.h) {
			Mix_PlayChannel(-1, Click, 0);
			Option->ButtonId = 1;
			
		}
		if (Next->rect.x < x && x < Next->rect.x + Next->rect.w && Next->rect.y < y && y < Next->rect.y + Next->rect.h) {
			Mix_PlayChannel(-1, Click, 0);
			
		}if (Previous->rect.x < x && x < Previous->rect.x + Previous->rect.w && Previous->rect.y < y && y < Previous->rect.y + Previous->rect.h) {
			Mix_PlayChannel(-1, Click, 0);
		}
	}
	else {
		Play->ButtonId = 0;
		Exit->ButtonId = 0;
		Option->ButtonId = 0;
	}
	if (ev.type == SDL_MOUSEBUTTONUP) {
		int x, y;
		SDL_GetMouseState(&x, &y);
		if (Play->rect.x < x && x < Play->rect.x + Play->rect.w && Play->rect.y < y && y < Play->rect.y + Play->rect.h) {
			Play->ButtonId = 0;
			state = PlayGame;
		}
		if (Exit->rect.x < x && x < Exit->rect.x + Exit->rect.w && Exit->rect.y < y && y < Exit->rect.y + Exit->rect.h) {
			Exit->ButtonId = 0;
			state = EndGame;

		}
		if (Option->rect.x < x && x < Option->rect.x + Option->rect.w && Option->rect.y < y && y < Option->rect.y + Option->rect.h) {
			Option->ButtonId = 0;
			state = GameOption;
		}
		if (Next->rect.x < x && x < Next->rect.x + Next->rect.w && Next->rect.y < y && y < Next->rect.y + Next->rect.h) {
			id += 1;

		}if (Previous->rect.x < x && x < Previous->rect.x + Previous->rect.w && Previous->rect.y < y && y < Previous->rect.y + Previous->rect.h) {
			id -= 1;
		}
	}
}

LevelComplete::LevelComplete(const Uint32& level) {
	Exit = new Button(0,"Close",{640,400});
	Exit->setSize({ 75,50 });
	Replay=new Button(0,"Replay",{330,400});
	Replay->setSize({ 75,50 });
	Menu=new Button(0,"Menu",{490,380});
	Menu->setSize({ 75,50 });
	NextLevel=new Button(0,"next",{650,250});
	NextLevel->setSize({ 75,50 });
	PreviousLevel=new Button(0,"previous",{350,250});
	PreviousLevel->setSize({ 75,50 });
	m_LevelComplete = new Texture();
	m_LevelComplete->setPosition({ 480,180 });
	m_LevelComplete->setSize({ 100,100 });
	m_LevelComplete->loadFromFile("Sprite//menu//" + std::to_string(level) + ".png");
	Background = new Texture();
	Background->setPosition({ 280,30 });
	Background->setSize({ 500,500 });
	Background->loadFromFile("Sprite//menu//Win.png");
	
}
LevelComplete::~LevelComplete() {
	Exit->~Button();
	Replay->~Button();
	Menu->~Button();
	NextLevel->~Button();
	PreviousLevel->~Button();
	m_LevelComplete->~Texture();
	Background->~Texture();
}
void LevelComplete::Render() {
	Background->render();
	m_LevelComplete->render();
	Exit->Render();
	Replay->Render();
	Menu->Render();
	NextLevel->Render();
	PreviousLevel->Render();
}
void LevelComplete::handle(SDL_Event& ev, GameType& state,int& level) {
	if (ev.type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState(&x, &y);
		if (Exit->rect.x < x && x < Exit->rect.x + Exit->rect.w && Exit->rect.y < y && y < Exit->rect.y + Exit->rect.h) {
			Mix_PlayChannel(-1, Click, 0);
		}
		if (Replay->rect.x < x && x < Replay->rect.x + Replay->rect.w && Replay->rect.y < y && y < Replay->rect.y + Replay->rect.h) {
			Mix_PlayChannel(-1, Click, 0);
		}
		if (Menu->rect.x < x && x < Menu->rect.x + Menu->rect.w && Menu->rect.y < y && y <Menu->rect.y + Menu->rect.h) {
			Mix_PlayChannel(-1, Click, 0);
		}
		if (NextLevel->rect.x < x && x < NextLevel->rect.x + NextLevel->rect.w && NextLevel->rect.y < y && y <NextLevel->rect.y + NextLevel->rect.h) {
			Mix_PlayChannel(-1, Click, 0);
		}
		if (PreviousLevel->rect.x < x && x < PreviousLevel->rect.x + PreviousLevel->rect.w && PreviousLevel->rect.y < y && y < PreviousLevel->rect.y + PreviousLevel->rect.h) {
			Mix_PlayChannel(-1, Click, 0);
		}
	}if (ev.type == SDL_MOUSEBUTTONUP) {
		int x, y;
		SDL_GetMouseState(&x, &y);
		if (Exit->rect.x < x && x < Exit->rect.x + Exit->rect.w && Exit->rect.y < y && y < Exit->rect.y + Exit->rect.h) {
			state = EndGame;
		}
		if (Replay->rect.x < x && x < Replay->rect.x + Replay->rect.w && Replay->rect.y < y && y < Replay->rect.y + Replay->rect.h) {
			state = PlayGame;
		}
		if (Menu->rect.x < x && x < Menu->rect.x + Menu->rect.w && Menu->rect.y < y && y < Menu->rect.y + Menu->rect.h) {
			state = MenuGame;
		}
		if (NextLevel->rect.x < x && x < NextLevel->rect.x + NextLevel->rect.w && NextLevel->rect.y < y && y < NextLevel->rect.y + NextLevel->rect.h) {
			state = PlayGame;
			if (level + 1 <= 3) {
				level += 1;
			}
		}
		if (PreviousLevel->rect.x < x && x < PreviousLevel->rect.x + PreviousLevel->rect.w && PreviousLevel->rect.y < y && y < PreviousLevel->rect.y + PreviousLevel->rect.h) {
			state = PlayGame;
			if (level - 1 > 0) {
				level -= 1;
			}
		}
	}
}
Gameover::Gameover() {
	Exit = new Button(0, "Close", { 640,400 });
	Exit->setSize({ 75,50 });
	Replay = new Button(0, "Replay", { 330,400 });
	Replay->setSize({ 75,50 });
	Menu = new Button(0, "Menu", { 490,380 });
	Menu->setSize({ 75,50 });
	Background = new Texture();
	Background->setPosition({ 280,30 });
	Background->setSize({ 500,500 });
	Background->loadFromFile("Sprite//menu//GameOver.png");
}
Gameover::~Gameover() {
	Exit->~Button();
	Replay->~Button();
	Menu->~Button();
	Background->~Texture();
}
void Gameover::Render() {
	Background->render();
	Exit->Render();
	Replay->Render();
	Menu->Render();
}
void Gameover::handle(SDL_Event& ev, GameType& state) {
	if (ev.type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState(&x, &y);
		if (Exit->rect.x < x && x < Exit->rect.x + Exit->rect.w && Exit->rect.y < y && y < Exit->rect.y + Exit->rect.h) {
			Mix_PlayChannel(-1, Click, 0);
		}
		if (Replay->rect.x < x && x < Replay->rect.x + Replay->rect.w && Replay->rect.y < y && y < Replay->rect.y + Replay->rect.h) {
			Mix_PlayChannel(-1, Click, 0);
		}
		if (Menu->rect.x < x && x < Menu->rect.x + Menu->rect.w && Menu->rect.y < y && y < Menu->rect.y + Menu->rect.h) {
			Mix_PlayChannel(-1, Click, 0);
		}
	}if (ev.type == SDL_MOUSEBUTTONUP) {
		int x, y;
		SDL_GetMouseState(&x, &y);
		if (Exit->rect.x < x && x < Exit->rect.x + Exit->rect.w && Exit->rect.y < y && y < Exit->rect.y + Exit->rect.h) {
			state = EndGame;
		}
		if (Replay->rect.x < x && x < Replay->rect.x + Replay->rect.w && Replay->rect.y < y && y < Replay->rect.y + Replay->rect.h) {
			state = PlayGame;
		}
		if (Menu->rect.x < x && x < Menu->rect.x + Menu->rect.w && Menu->rect.y < y && y < Menu->rect.y + Menu->rect.h) {
			state = MenuGame;
		}
	}
}