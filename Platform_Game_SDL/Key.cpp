#include"Key.h"
Key::Key(const Uint32& type,std::pair<int, int> position) {
	setPosition(position);
	GameObjectType = type;
	collider = new Collider(*this);
	if (type == 25) {
		loadFromFile("Sprite//map//25.png");
	}
	setSize({ 50,50 });
}
Key::~Key() {
	collider = nullptr;
	GameObjectType = 0;
	free();
}
void Key::Render() {
	if (!Delete) {
		render(false);
	}
}
Collider* Key::getColider() {
	return collider;
}