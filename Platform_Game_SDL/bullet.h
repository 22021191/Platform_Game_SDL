#pragma once
#include"BaseFunc.h"
#include"Collider.h"
#include"Texture.h"
class Bullet:public Texture
{
public:
	Bullet(float angle,int id,std::pair<int,int>startPos);
	~Bullet();
	void Render();
	void Update();
	Collider* getColider();

private:
	float m_angle;
	int Id;
	Collider* collider;
	int _move;
};
