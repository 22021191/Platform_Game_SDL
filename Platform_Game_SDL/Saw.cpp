#include"Saw.h"
Saw::Saw(const Uint32& Tile, const std::pair<int, int>& start, const std::pair<int, int>& end, const std::pair<int, int>& position) {
    collider = new Collider(*this);
    switch (Tile)
    {
        case 21:
            animation = new Animation("Sprite//map//21.png", { 8, 1 }, 130);
            loadFromFile("Sprite//map//21.png");
            frameLimit = { 8, 0 };
            break;
        case 20:
            animation = nullptr;
            loadFromFile("Sprite//map//20.png");
            break;
    default:
        break;
    }
    TileObject = Tile;
    setSize({ 50, 50 });
    setPosition(position);
    this->start = start;
    this->end = end;
    _Move = -1;
}

Saw::~Saw() {
    collider = nullptr;
    animation = nullptr;
    free();
}
void Saw::Render() {
    switch (TileObject)
    {
    case 21:
        render(false, animation->getmBox());
        break;
    case 20:
        render(false);
        break;
    default:
        break;
    }
}

Collider* Saw::getCollider() {
    return collider;
}
void Saw::Update(const Uint32& deltaTime) {
    switch (TileObject)
    {
    case 21:
        rect.x += _Move * speed;
        frameLimit = { 8,0 };
        animation->update(deltaTime, frameLimit, false);
        if (rect.x <= start.first || rect.x >= end.first) {
            _Move *= -1;
        }
        break;
    case 20:
        rect.y += _Move * speed;
        if (rect.y<start.second || rect.y>end.second) {
            _Move *= -1;
        }
    default:
        break;
    }
}