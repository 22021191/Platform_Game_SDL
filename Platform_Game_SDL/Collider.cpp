#include"Collider.h"
Collider::Collider(Texture& body) {
    this->body = &body;
}
Collider::Collider(Texture* body) {
    this->body = body;
}
std::pair<float, float> Collider::getCenterPosition() {
    return { (float)body->getPosition().first + body->getSize().first / 2, (float)body->getPosition().second + body->getSize().second / 2 };
}
std::pair<int, int> Collider::getPosition() {
    return body->getPosition();
}
std::pair<int, int> Collider::getSize() {
    return body->getSize();
}
int Collider::checkCollision(Collider* other) {
    std::pair<float, float> otherCenterPosition = other->getCenterPosition();
    std::pair<int, int> otherSize = other->getSize();
    std::pair<float, float> thisCenterPosition = getCenterPosition();
    std::pair<int, int> thisSize = getSize();
    float deltaX = otherCenterPosition.first - thisCenterPosition.first;
    float deltaY = otherCenterPosition.second - thisCenterPosition.second;
    int intersectX = 2 * abs(deltaX) - (otherSize.first + thisSize.first);
    int intersectY = 2 * abs(deltaY) - (otherSize.second + thisSize.second);
    if (intersectX < 0 && intersectY < 0) {
       // std::cout << "ok";
        if (intersectX > intersectY) {
            if (deltaX > 0.0f) {
                return collider::right;
            }
            else {
                return collider::left;
            }
        }
        else {
            if (deltaY > 0.0f && intersectY <= -3) {
                return collider::down;
            }
            if (deltaY < 0.0f && intersectY <= -3) {
                return collider::top;
            }
        }
    }
    if (intersectX <= 0 && intersectY <= 0) {
        if (intersectX > intersectY) {
            if (deltaX > 0.0f) {
                return collider::_right;
            }
            else {
                return collider::_left;
            }
        }
        else {
            //std::cout << "ok";
            if (deltaY > 0.0f&&intersectY<=-1) {
                return collider::_down;
            }
            if(deltaY < 0.0f && intersectY <= -1){
                return collider::_top;
            }
        }
    }
    return 0;
}
int Collider::Colision(Collider* other) {
    SDL_Point top, down;
    top = { other->body->rect.x + other->body->rect.w / 2,other->body->rect.y};
    down = { other->body->rect.x + other->body->rect.w / 2 ,other->body->rect.y + other->body->rect.h };
    if (dotCollidion(top)) {
        return collider::down;
    }
    if (dotCollidion(down)) {
        return collider::top;
    }
    
    return 0;
}
bool Collider:: dotCollidion(SDL_Point other) {
    if (other.x >= body->rect.x &&
        other.x<=(body->rect.x + body->rect.w) &&
        other.y>=body->rect.y &&
        other.y <= (body->rect.y + body->rect.h)) {
        return true;
    }
    return false;
}
