/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: texture.cpp
 */

#include "texture.h"

#include "graphics.h"

Texture::Texture()
{
}

Texture::Texture(const std::string& filePath, Graphics& graphics,
		 uint8_t r, uint8_t g, uint8_t b)
{
	load(filePath, graphics, r, g, b);
}

Texture::~Texture()
{
}

void
Texture::load(const std::string& filePath, Graphics& graphics,
	      uint8_t r, uint8_t g, uint8_t b)
{
	texture_ = graphics.loadTexture(filePath, r, g, b);
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
Texture::setAlpha(uint8_t value)
{
	SDL_SetTextureAlphaMod(texture_, value);
	alpha_ = value;
}

void
Texture::setBlendMode(SDL_BlendMode mode)
{
	SDL_assert(texture_ != nullptr);

	SDL_SetTextureBlendMode(texture_, mode);
}

void
Texture::render(Graphics& graphics, const SDL_Rect* rect)
{
	graphics.renderCopy(texture_, nullptr, rect, degree_, nullptr, flip_);
}
