#pragma once
#include"BaseFunc.h"
class Text
{
public:
	Text();
	~Text();
	bool LoadFormRenderTexture(TTF_Font* Font, SDL_Renderer* render);
	void RenderText(int Xpos, int Ypos, SDL_Renderer* render);
	int GetWidth() const { return Width_; }
	int GetHeight() const { return Height_; }
	void SetText(const std::string& m_text) { Val_string = m_text; }
	std::string GetText() { return Val_string; }
	SDL_Texture* Texture;
	SDL_Surface* TextSurface;

private:
	std::string Val_string;
	SDL_Color text_Color;
	int Width_, Height_;

};
