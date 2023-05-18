#include"Text.h"
Text::Text() {
	text_Color = { 255,0,0,255 };
	Texture = NULL;
}
Text::~Text() {

}
bool Text::LoadFormRenderTexture(TTF_Font* Font, SDL_Renderer* render) {
	TextSurface = TTF_RenderText_Solid(Font, Val_string.c_str(), text_Color);

	if (Font != NULL) {
		Texture = SDL_CreateTextureFromSurface(render, TextSurface);
		Width_ = TextSurface->w;
		Height_ = TextSurface->h;
		SDL_FreeSurface(TextSurface);
	}
	return Texture != NULL;
}
void Text::RenderText(int Xpos, int Ypos, SDL_Renderer* render) {
	SDL_Rect Render_Rect = { Xpos,Ypos,Width_,Height_ };
	SDL_RenderCopy(render, Texture, NULL, &Render_Rect);
}