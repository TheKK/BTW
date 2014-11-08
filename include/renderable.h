/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: renderable.h
 */

#ifndef RENDERABLE_H
#define RENDERABLE_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

class Renderable
{
	public:
		Renderable();
		virtual ~Renderable();
		virtual void render() = 0;
		virtual void setAlpha(uint8_t value) = 0;

		SDL_Texture* loadTexture(string filePath,
					 SDL_Renderer* renderer,
					 Uint8 r, Uint8 g, Uint8 b);

		void enlarge(int dw, int dh);
		void setSize(unsigned int w, unsigned int h);
		void setRenderer(SDL_Renderer* renderer);

		void moveBy(int x, int y);
		void moveXTo(int x);
		void moveYTo(int y);
		void moveTo(int x, int y);

		int posX() const;
		int posY() const;
		int width() const;
		int height() const;
		SDL_Rect rect() const;

		void hide();
		void show();
		void setVisable(bool value);
		bool getVisable() const;

		bool mouseHovered(int32_t mouseX, int32_t mouseY);
	protected:
		SDL_Rect rect_ = {0, 0, 0, 0};

		SDL_Renderer* targetRenderer_ = nullptr;

		bool visable_ = true;

		static uint32_t objectCount_;
};

#endif	/* RENDERABLE_H */
