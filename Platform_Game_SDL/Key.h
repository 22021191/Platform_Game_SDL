#pragma once
#include"Collider.h"
#include"BaseFunc.h"
#include"Texture.h"
class Key:public Texture
{
public:
	Key(const Uint32& type,std::pair<int, int>Position);
	~Key();
	void Render();
	bool Delete = false;
	Collider* getColider();
private:
	int GameObjectType;
	Collider* collider;
};
