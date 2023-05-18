#pragma once
#include"BaseFunc.h"
#include"Texture.h"

enum collider {
    top = 8, right = 6, left = 4, down = 2,
    _top = -8, _right = -6, _left = -4, _down = -2,
};

class Collider {
public:
    Collider(Texture& body);
    Collider(Texture* body);
    ~Collider() {}
    bool dotCollidion(SDL_Point other);
    int checkCollision(Collider* other);
    int Colision(Collider* other);
    std::pair<float, float> getCenterPosition();
    std::pair<int, int> getPosition();
    std::pair<int, int> getSize();
    Texture* body;
    

};
