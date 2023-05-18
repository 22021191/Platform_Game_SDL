#pragma once
#include"BaseFunc.h"
#include"Texture.h"
class Button:public Texture
{
public:
	Button(const Uint32& Id,std::string Name,std::pair<int,int>Position);
	~Button();
	void Render();
	int ButtonId;
	std::string ButtonName;
	
};
class Menu
{
public:
	Menu();
	~Menu();
	void handle(SDL_Event& ev,GameType& state,int &id);
	void Render();
private:
	Texture* BackGround;
	Button* Exit;
	Button* Play;
	Button* Option;
	Button* Next;
	Button* Previous;

};
class Gameover
{
public:
	Gameover();
	~Gameover();
	void handle(SDL_Event& ev, GameType& state);
	void Render();
	Button* Exit;
	Button* Replay;
	Button* Menu;
	Texture* Background;

};
class LevelComplete
{
public:
	LevelComplete(const Uint32& level);
	~LevelComplete();
	void handle(SDL_Event& ev, GameType& state, int& level);
	void Render();
private:
	Button* Exit;
	Button* Replay;
	Button* Menu;
	Button* NextLevel;
	Button* PreviousLevel;
	Texture* m_LevelComplete;
	Texture* Background;
};