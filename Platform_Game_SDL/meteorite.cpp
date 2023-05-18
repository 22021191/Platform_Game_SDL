#include"meteorite.h"

meteorite::meteorite() {
	srand(time(0));
	int posx = rand() % 2+1;
	int posy = rand() % 5 + 1;
	if (posx == 1) {
		posx = -200;
	}
	else
	{
		posx = 1200;
	}
	startPos = { posx,posy * 100 };
	collider = new Collider(*this);
	setPosition(startPos);
	setSize({ 50,50 });
	loadFromFile("Sprite//map//thienthach.png");
	waring = new Texture();
	waring->setSize({ 100,100 });
	waring->loadFromFile("Sprite//map//warning.png");
	if (posx==-200) {
		_Move = 5;
		waring->setPosition({ 0,posy * 100 });
	}
	else {
		_Move = -5;
		waring->setPosition({ 900,posy * 100 });

	}
	std::cout << posx << std::endl;
}
Collider* meteorite::getColider() {
	return collider;
}
void meteorite:: Render() {
	render(false);
	waring->render(false);
	/*if (waring != nullptr) {
	}*/
}
meteorite::~meteorite() {
	delete collider;
	waring->~Texture();

}
void meteorite::Update() {
	rect.x += _Move;
	if (rect.x > 1200 || rect.x < -500) {
		delete this;
	}
	if (rect.x > 0 && rect.x < 1000) {
		std::cout << rect.x<<std::endl;
		waring->~Texture();
	}
}