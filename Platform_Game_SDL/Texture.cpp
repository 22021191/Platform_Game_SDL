#include"Texture.h"

Texture::Texture() {
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

Texture::~Texture() {
	free();
}

void Texture::setSize(std::pair<int, int> size) {
	mWidth = size.first;
	mHeight = size.second;
	rect.w = size.first;
	rect.h = size.second;
}

void Texture::setPosition(std::pair<int, int> pos) {
	rect.x = pos.first;
	rect.y = pos.second;
}

bool Texture::loadFromFile(std::string path) {
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
		std::cout << "Khong the load anh! SDL_image error: " << IMG_GetError() << std::endl;
	else {
		mTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (mTexture == NULL)
			std::cout << "Khong ve duoc anh tai " << path << "! SDL error: " << SDL_GetError() << std::endl;
		else {
			if (!mHeight && !mWidth) {
				mWidth = loadedSurface->w;
				mHeight = loadedSurface->h;
				rect.w = mWidth;
				rect.h = mHeight;
			}
		}
		SDL_FreeSurface(loadedSurface);
	}
	return mTexture != NULL;
}

void Texture::free() {
	SDL_DestroyTexture(mTexture);
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

void Texture::render(bool flip,SDL_Rect* clip,double angle, SDL_Point* center) {
	if (flip) {
		SDL_RenderCopyEx(renderer, mTexture,clip, &rect, angle, center, SDL_FLIP_HORIZONTAL);
	}
	else {
		SDL_RenderCopyEx(renderer, mTexture,clip, &rect, angle, center, SDL_FLIP_NONE);
	}
}

int Texture::getWidth() {
	return mWidth;
}

int Texture::getHeight() {
	return mHeight;
}


std::pair<int, int> Texture::getPosition() const {
	return { rect.x, rect.y };
}

std::pair<int, int> Texture::getSize() const {
	return { rect.w, rect.h };
}