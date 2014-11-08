/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: texture.cpp
 */

#include "texture.h"

Texture::Texture()
{
}

Texture::Texture(string filePath, SDL_Renderer* renderer,
		 Uint8 r, Uint8 g, Uint8 b)
{
	load(filePath, renderer, r, g, b);
}

Texture::~Texture()
{
	release_();
}

void
Texture::load(string filePath, SDL_Renderer* renderer,
	      Uint8 r, Uint8 g, Uint8 b)
{
	targetRenderer_ = renderer;
	texture_ = loadTexture(filePath, renderer, r, g, b);

	rect_.x = 0;
	rect_.y = 0;
	SDL_QueryTexture(texture_, nullptr, nullptr, &rect_.w, &rect_.h);
}

void
Texture::rotate(double value)
{
	degree_ += value;
	if (degree_ > 360.0)
		degree_ -= 360.0;
	else if (degree_ < 0)
		degree_ = 360 - degree_;
}

void
Texture::setAlpha(Uint8 value)
{
	SDL_SetTextureAlphaMod(texture_, value);
	alpha_ = value;
}

SDL_Texture*
Texture::object() const
{
	return texture_;
}

void
Texture::setBlendMode(SDL_BlendMode mode)
{
	SDL_assert_paranoid(texture_ != nullptr);

	SDL_SetTextureBlendMode(texture_, mode);
}

void
Texture::render()
{
	if (!visable_)
		return;

	SDL_RenderCopyEx(targetRenderer_, texture_, nullptr, &rect_,
			 degree_, nullptr, SDL_FLIP_NONE);
}

void
Texture::renderFullWindow()
{
	if (!visable_)
		return;

	SDL_RenderCopy(targetRenderer_, texture_, nullptr, nullptr);
}

void
Texture::release_()
{
	if (texture_ != nullptr)
		SDL_DestroyTexture(texture_);
	texture_ = nullptr;
}
