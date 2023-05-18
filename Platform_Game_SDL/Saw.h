#pragma once
#include"BaseFunc.h"
#include"Texture.h"
#include"Animation.h"
#include"Collider.h"
class Saw:public Texture
{
public:
	Saw(const Uint32& Tile,const std::pair<int, int>& start, const std::pair<int, int>& end, const std::pair<int, int>& position);
	~Saw();
	void Update(const Uint32& deltaTime);
	void Render();
	void SawRender();
	Collider* getCollider();
	int _Move;
	int TileObject;
private:
	Animation* animation;
	int speed=1;
	Collider* collider = nullptr;
	std::pair<int, int> start, end;
	std::pair<int, int> frameLimit;
};