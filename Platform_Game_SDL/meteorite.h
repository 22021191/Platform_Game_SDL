#pragma once
#include"BaseFunc.h"
#include"Texture.h"
#include"Collider.h"
class meteorite:public Texture
{
public:
	meteorite();
	~meteorite();
	void Render();
	void Update();
	bool Delete = false;
	Collider* getColider();
private:
	Texture* waring;
	int _Move;
	bool direction;
	std::pair<int, int>startPos;
	Collider* collider;
};
