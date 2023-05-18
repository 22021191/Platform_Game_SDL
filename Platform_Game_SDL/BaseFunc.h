#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <utility>
#include <string>
#include<iostream>
#include<vector>
#include <fstream>
#include <math.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>

const int FPS = 60;
const int frameDelay = 1000 / FPS;
const int screenWidth=1000;
const int screenHeight=560;
const int GROUND_WIDTH = 50;
const int GROUND_HEIGHT = 50;


extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern Mix_Chunk* jump;
extern Mix_Chunk* Click;
extern Mix_Chunk* boom;
extern TTF_Font* fGame;
extern Mix_Chunk* music_Menu;
extern Mix_Chunk* music_Gameover;

enum GameType
{
	MenuGame = 1,
	PlayGame = 2,
	PauseGame = 3,
	EndGame=4,
	GameOption=0,
	WinGame=5,
	GameOver=6
	
};