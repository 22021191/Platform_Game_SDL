#pragma once
#include"Texture.h"
#include"BaseFunc.h"
#include"Collider.h"
#include"Animation.h"
class Player:public Texture
{
public:
	Player(int Id,std::pair<int, int> positionStart, std::pair<int,int>size,const bool& faceRightStart);
	~Player();
	float speed = 5.0f;
	bool IsMove = false, IsJump = false;
	bool GroundCheck=false,WallCheck=false,face_Right;
	float JumpHeight = 81.0f;
	int CanJump = 2;
	bool die = false,LevelTurn;
	std::pair<int, float>velocity;
	Collider* collider;
	void PlayerMove();
	void Render();
	Collider* getcollider();
	Texture body;
	void UpdateMove(const Uint32& deltaTime);
private:
	std::pair<int, int> oldPos;
	Animation* animation;

};

