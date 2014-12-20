/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: graphics.cpp
 */

#include "graphics.h"

#include <SDL_image.h>

#include "window.h"

Graphics::Graphics(Window& window,
		   uint32_t logicalWidth, uint32_t logicalHeight)
{
	/* Create and setup new SDL renderer, and check error */
	renderer_ = SDL_CreateRenderer(
		window.window(),
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
		);
	if (renderer_ == nullptr) {
		std::string errMsg("SDL renderer error: ");
		errMsg += SDL_GetError();
		throw std::runtime_error(errMsg);
	}

	/* Make fullscreen fit physical screen */
	SDL_RenderSetLogicalSize(renderer_, logicalWidth, logicalHeight);
}

Graphics::~Graphics()
{
	for (auto& e : spriteSheets_)
		SDL_DestroyTexture(e.second);
	spriteSheets_.clear();

	SDL_DestroyRenderer(renderer_);
	renderer_ = nullptr;
}

void
Graphics::clear()
{
	SDL_SetRenderDrawColor(renderer_,
			       clearColor_.r,
			       clearColor_.g,
			       clearColor_.b,
			       clearColor_.a);
	SDL_RenderClear(renderer_);
}

void
Graphics::present()
{
	SDL_RenderPresent(renderer_);
}

void
Graphics::setClearColor(const SDL_Color* value)
{
	clearColor_.r = value->r;
	clearColor_.g = value->g;
	clearColor_.b = value->b;
	clearColor_.a = value->a;
}

TextureId
Graphics::loadTexture(const std::string& filePath,
		      uint8_t r, uint8_t g, uint8_t b)
{
	SDL_Surface* loadedImage = nullptr;
	SDL_Texture* tex = nullptr;
	char* basePath = nullptr;
	std::string fullPath;

	if (spriteSheets_.count(filePath) == 1)
		return spriteSheets_[filePath];

	basePath = SDL_GetBasePath();
	fullPath += basePath;
	fullPath += filePath;

	SDL_free(basePath);
	basePath = nullptr;

	loadedImage = IMG_Load(fullPath.c_str());
	if (loadedImage == nullptr) {
		std::string errMsg("IMG error while opening: ");
		errMsg += IMG_GetError();
		SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, errMsg.c_str());
		return nullptr;
	}

	SDL_SetColorKey(loadedImage, SDL_TRUE,
			SDL_MapRGB(loadedImage->format, r, g, b));

	tex = SDL_CreateTextureFromSurface(renderer_, loadedImage);
	if (tex == nullptr) {
		std::string errMsg("SDL error while converting surface: ");
		errMsg += SDL_GetError();
		SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, errMsg.c_str());
		return nullptr;
	}

	SDL_SetTextureBlendMode(tex, SDL_BLENDMODE_BLEND);

	SDL_FreeSurface(loadedImage);

	spriteSheets_[filePath] = tex;

	return tex;
}

void
Graphics::renderCopy(SDL_Texture* source, const SDL_Rect* source_rect,
		 const SDL_Rect* dest_rect)
{
	SDL_RenderCopy(renderer_, source, source_rect, dest_rect);
}
void
Graphics::renderCopy(SDL_Texture* source, const SDL_Rect* source_rect,
		     const SDL_Rect* dest_rect,
		     const double degree, const SDL_Point* center,
		     const SDL_RendererFlip flip)
{
	SDL_RenderCopyEx(renderer_, source, source_rect, dest_rect,
			 degree, center, flip);
}

int
Graphics::w() const
{
	int w;
	SDL_RenderGetLogicalSize(renderer_, &w, nullptr);
	return w;
}

int
Graphics::h() const
{
	int h;
	SDL_RenderGetLogicalSize(renderer_, nullptr, &h);
	return h;
}
