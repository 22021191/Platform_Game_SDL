#pragma once
#include"Texture.h"
#include"Collider.h"
#include"BaseFunc.h"
class Spike:public Texture
{
public:
	Spike(const Uint32&tile,std::pair<int,int>Position);
	~Spike();
	void Render();
	Collider* getColider();
private:
	int speed = 5;
	Collider* collider;
	int tileGameObject;
};