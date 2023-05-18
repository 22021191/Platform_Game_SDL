#include"Spike.h"
Spike::Spike(const Uint32& tile, std::pair<int, int>Position) {
	setPosition(Position);
	setSize({50, 50});
	collider = new Collider(*this);
	speed = 1;
	tileGameObject = tile;
	switch (tile)
	{
	case 22:
		loadFromFile("Sprite//map//22.png");
		break;
	case 23:
		loadFromFile("Sprite//map//23.png");
		break;
	default:
		break;
	}
}
Spike::~Spike() {
	collider = nullptr;
	free();
}

Collider* Spike::getColider() {
	return collider;
}
void Spike::Render() {
	render(false);
}