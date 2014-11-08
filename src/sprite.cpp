/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: sprite.cpp
 */

#include "sprite.h"

Sprite::Sprite()
{
}

Sprite::Sprite(string filePath, SDL_Renderer* renderer,
	       int w, int h,
	       Uint8 r, Uint8 g, Uint8 b)
{
	load(filePath, renderer, w, h, r, g, b);
}

Sprite::~Sprite()
{
	release_();
}

int
Sprite::load(string filePath, SDL_Renderer* renderer,
	     int w, int h,
	     Uint8 r, Uint8 g, Uint8 b)
{
	int sheetWidth, sheetHeight;

	targetRenderer_ = renderer;

	sheet_ = loadTexture(filePath, renderer, r, g, b);

	rect_.x = 0;
	rect_.y = 0;
	rect_.w = w;
	rect_.h = h;

	SDL_QueryTexture(sheet_, nullptr, nullptr, &sheetWidth, &sheetHeight);

	/* Setup clip for each frame and other stuffs*/
	totalFrame_= sheetWidth / w;
	SDL_Rect toBePushed;
	toBePushed.y = 0;
	toBePushed.w = w;
	toBePushed.h = h;
	for (int i = 0; i <= totalFrame_; i++) {
		toBePushed.x = i * w;
		clip_.push_back(toBePushed);
	}

	return 0;
}

void
Sprite::render()
{
	SDL_RenderCopy(targetRenderer_, sheet_, &clip_[currentFrame_], &rect_);
}

void
Sprite::renderFullWindow()
{
	SDL_RenderCopy(targetRenderer_, sheet_, &clip_[currentFrame_], nullptr);
}

void
Sprite::setAlpha(Uint8 value)
{
	SDL_SetTextureAlphaMod(sheet_, value);
}

void
Sprite::nextFrame()
{
	currentFrame_++;
	if (currentFrame_ == totalFrame_)
		currentFrame_ = 0;
}

void
Sprite::prevFrame()
{
	currentFrame_--;
	if (currentFrame_ < 0)
		currentFrame_ = totalFrame_ - 1;
}

void
Sprite::jumpTo(Uint16 where)
{
	currentFrame_ = where;
}

void
Sprite::release_()
{
	SDL_assert(sheet_ != nullptr);

	SDL_DestroyTexture(sheet_);
	sheet_ = nullptr;
}
