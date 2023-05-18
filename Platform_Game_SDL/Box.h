#pragma once
#include"Animation.h"
#include"BaseFunc.h"
#include"Collider.h"
#include"Texture.h"
class Box:public Texture
{
public:
	Box(const Uint32& type,const std::pair<int, int>& position);
	~Box();
	void Render();
	Collider* getCollider();
	void Update(const Uint32& deltatime);
	int TypeObject;
private:
	Collider* collider=nullptr;
	Animation* animation=nullptr;
	std::pair<int, int>framelimit;
};