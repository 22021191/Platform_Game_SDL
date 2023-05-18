#pragma once
#include"BaseFunc.h"
#include"Player.h"
#include"Map.h"
#include"Ground.h"
#include"Collider.h"
#include"Menu.h"
#include"Texture.h"
#include"Text.h"
#include"meteorite.h"

class Game
{
public:
	Game();
	~Game();
	void GameLoop();
	
private:
	int Level;
	int id; int Playerid;
	Map* map;
	Player* player;
	Menu* menu;
	Texture* Opt;
	Button* Back;
	Text* text;
	Gameover* over;
	LevelComplete* win;
	std::vector<meteorite*> meteorie;
};
