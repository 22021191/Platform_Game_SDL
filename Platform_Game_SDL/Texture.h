#pragma once
#include"BaseFunc.h"
class Texture {
public:
	Texture();

	~Texture();

	void setSize(std::pair<int, int> size);

	void setPosition(std::pair<int, int> pos);


	// Tải ảnh từ đường dẫn
	bool loadFromFile(std::string path);

	void free();

	// Tạo text tại vị trí bất kì
	void render(bool flip = 0,SDL_Rect*clip=NULL, double angle = 0.0, SDL_Point* center = NULL);

	// Lấy vị trí ảnh
	int getWidth();
	int getHeight();
	SDL_Rect* getRect();
	std::pair<int, int> getPosition() const;
	std::pair<int, int> getSize() const;
	SDL_Rect rect;
	SDL_Texture* mTexture;

protected:
	int mWidth;
	int mHeight;

};
