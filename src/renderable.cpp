/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: renderable.cpp
 */

#include "renderable.h"

uint32_t Renderable::objectCount_ = 0;

Renderable::Renderable()
{
	objectCount_++;
	//SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION,
		     //"Renderable object cound: %d\n", objectCount_);
}

Renderable::~Renderable()
{
	objectCount_--;
	//SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION,
		     //"Renderable object cound: %d\n", objectCount_);
}

SDL_Texture*
Renderable::LoadTexture(string filePath, SDL_Renderer* renderer,
			Uint8 r, Uint8 g, Uint8 b)
{
	SDL_assert(renderer != nullptr);

	SDL_Surface* loadedImage = nullptr;
	SDL_Texture* tex = nullptr;
	string basePath = SDL_GetBasePath();

	loadedImage = IMG_Load((basePath + filePath).c_str());
	if (loadedImage == nullptr) {
		string errMsg("IMG error while opening: ");
		errMsg += IMG_GetError();
		SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, errMsg.c_str());
		return nullptr;
	}

	SDL_SetColorKey(loadedImage, SDL_TRUE,
			SDL_MapRGB(loadedImage->format, r, g, b));

	tex = SDL_CreateTextureFromSurface(renderer, loadedImage);
	if (tex == nullptr) {
		string errMsg("SDL error while converting surface: ");
		errMsg += SDL_GetError();
		SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, errMsg.c_str());
	}

	SDL_SetTextureBlendMode(tex, SDL_BLENDMODE_BLEND);

	SDL_FreeSurface(loadedImage);

	return tex;
}

void
Renderable::Enlarge(int dw, int dh)
{
	rect_.w += dw;
	rect_.h += dh;
}

void
Renderable::SetSize(unsigned int w, unsigned int h)
{
	rect_.w = w;
	rect_.h = h;
}

void
Renderable::SetRenderer(SDL_Renderer* renderer)
{
	targetRenderer_ = renderer;
}

void
Renderable::MoveBy(int x, int y)
{
	rect_.x += x;
	rect_.y += y;
}

void
Renderable::MoveXTo(int x)
{
	rect_.x = x;
}

void
Renderable::MoveYTo(int y)
{
	rect_.y = y;
}

void
Renderable::MoveTo(int x, int y)
{
	rect_.x = x;
	rect_.y = y;
}

int
Renderable::PosX() const
{
	return rect_.x;
}


int
Renderable::PosY() const
{
	return rect_.y;
}

int
Renderable::Width() const
{
	return rect_.w;
}

int
Renderable::Height() const
{
	return rect_.h;
}

SDL_Rect
Renderable::Rect() const
{
	return rect_;
}

void
Renderable::Hide()
{
	visable_ = false;
}

void
Renderable::Show()
{
	visable_ = true;
}

void
Renderable::SetVisable(bool value)
{
	visable_ = value;
}

bool
Renderable::GetVisable() const
{
	return visable_;
}
bool
Renderable::MouseHovered(int32_t mouseX, int32_t mouseY)
{
	if (
		mouseX < (rect_.x + rect_.w) && mouseX > rect_.x &&
		mouseY < (rect_.y + rect_.h) && mouseY > rect_.y
	)
		return true;
	else
		return false;
}
