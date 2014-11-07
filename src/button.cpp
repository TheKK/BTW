/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: button.cpp
 */

#include "button.h"

Button::Button(string normalPicPath, string hoverPicPath, string pushPicPath,
	       SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b)
{
	Load(normalPicPath, hoverPicPath, pushPicPath, renderer, r, g, b);
}

Button::~Button()
{
	Release_();
}

void
Button::Load(string normalPicPath, string hoverPicPath, string pushPicPath,
	     SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b)
{
	SetRenderer(renderer);

	pics_[BUTTON_NORMAL] = LoadTexture(normalPicPath, renderer, r, g, b);
	pics_[BUTTON_HOVERED] = LoadTexture(hoverPicPath, renderer, r, g, b);
	pics_[BUTTON_PUSHED] = LoadTexture(pushPicPath, renderer, r, g, b);

	SDL_QueryTexture(pics_[BUTTON_NORMAL], nullptr, nullptr,
			 &rect_.w, &rect_.h);

	buttonState_ = BUTTON_NORMAL;
}

void
Button::Render()
{
	SDL_RenderCopy(targetRenderer_, pics_[buttonState_], nullptr, &rect_);
}

void
Button::SetAlpha(uint8_t value)
{
	for (SDL_Texture* e : pics_)
		SDL_SetTextureAlphaMod(e, value);
}

void
Button::ChangeState(enum ButtonState newState)
{
	buttonState_ = newState;
}

void
Button::Release_()
{
	for (SDL_Texture* e : pics_) {
		if (e != nullptr)
			SDL_DestroyTexture(e);
		e = nullptr;
	}
}
