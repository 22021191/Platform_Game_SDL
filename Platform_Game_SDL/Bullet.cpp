#include"bullet.h"
Bullet::Bullet(float angle, int id, std::pair<int, int>startPos) {
	m_angle = angle/180*3.14;
	Id = id;
	setSize({ 25,25 });
	setPosition(startPos);
	loadFromFile("Sprite//map//Bullet" + std::to_string(id) + ".png");
	_move = 5;
	collider = new Collider(*this);
}
Bullet::~Bullet() {
	delete collider;
}
void Bullet:: Render() {
	render(false);
}
void Bullet:: Update() {
	rect.x += cos(m_angle)*_move;
	rect.y += sin(m_angle)*_move;
	if (rect.x > 1000 || rect.x < 0 || rect.y>560 || rect.y < 0) {
		delete this;
	}

}
Collider* Bullet::getColider() {
	return collider;
}