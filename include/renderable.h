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
		virtual void Render() = 0;
		virtual void SetAlpha(uint8_t value) = 0;

		SDL_Texture* LoadTexture(string filePath,
					 SDL_Renderer* renderer,
					 Uint8 r, Uint8 g, Uint8 b);

		void Enlarge(int dw, int dh);
		void SetSize(unsigned int w, unsigned int h);
		void SetRenderer(SDL_Renderer* renderer);

		void MoveBy(int x, int y);
		void MoveXTo(int x);
		void MoveYTo(int y);
		void MoveTo(int x, int y);

		int PosX() const;
		int PosY() const;
		int Width() const;
		int Height() const;
		SDL_Rect Rect() const;

		void Hide();
		void Show();
		void SetVisable(bool value);
		bool GetVisable() const;

		bool MouseHovered(int32_t mouseX, int32_t mouseY);
	protected:
		SDL_Rect rect_ = {0, 0, 0, 0};

		SDL_Renderer* targetRenderer_ = nullptr;

		bool visable_ = true;

		static uint32_t objectCount_;
};

#endif	/* RENDERABLE_H */
