/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: graphics.h
 */

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL.h>
#include <map>
#include <string>

typedef SDL_Texture* TextureId;

class Window;

class Graphics
{
public:
	Graphics(Window& window, uint32_t logicalWidth, uint32_t logicalHeight);
	~Graphics();

	void clear();
	void present();

	void setClearColor(const SDL_Color* color);

	TextureId loadTexture(const std::string& filePath,
			      uint8_t r, uint8_t g, uint8_t b);

	void renderCopy(SDL_Texture* source, const SDL_Rect* source_rect,
			const SDL_Rect* dest_rect);

	void renderCopy(SDL_Texture* source, const SDL_Rect* source_rect,
			const SDL_Rect* dest_rect,
			const double degree, const SDL_Point* center,
			const SDL_RendererFlip flip);

	int w() const;
	int h() const;
private:
	SDL_Renderer* renderer_ = nullptr;
	SDL_Color clearColor_ = {0};
	std::map<std::string, SDL_Texture*> spriteSheets_;
};

#endif /* GRAPHICS_H */
