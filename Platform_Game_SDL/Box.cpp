#include"Box.h"
Box::Box(const Uint32& type, const std::pair<int, int>& position) {
    setSize({ 50, 50 });
    setPosition(position);
    collider = new Collider(*this);
    if (type == 26) {
        animation = new Animation("Sprite//map//26.png", { 12,1 }, 130);
        loadFromFile("Sprite//map//26.png");
    }
    if (type == 24) {
        animation = new Animation("Sprite//map//24.png", { 6,1 }, 130);
        loadFromFile("Sprite//map//24.png");
    }
    TypeObject = type;
}
Box::~Box() {
    animation = nullptr;
    collider = nullptr;
}
Collider* Box::getCollider() {
    return collider;
}
void Box::Render() {
     render(false, animation->getmBox());
}
void Box::Update(const Uint32& deltatime) {
    if (TypeObject == 26) {
        framelimit = { 12,0 };
    }
    if (TypeObject == 24) {
        framelimit = { 6,0 };
    }
    animation->update(deltatime, framelimit);
}