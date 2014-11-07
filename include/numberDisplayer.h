/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: numberDisplayer.h
 */

#ifndef NUMBER_DISPLAYER_H
#define NUMBER_DISPLAYER_H

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "sprite.h"
#include "renderable.h"

using namespace std;

class NumberDisplayer : public Renderable
{
	public:
		NumberDisplayer(string picPath, Uint8 displayDigitalNum,
				Uint16 digitalWidth, Uint16 digitalHeight,
				SDL_Renderer* renderer);
		~NumberDisplayer();

		void Render();

		void AddNum(Uint32 value);
		void SetNum(int value);
		Uint64 GetNum() const;

		void SetAlpha(Uint8 value);

		void CounterSetZero();
	private:
		Sprite numSprite_;

		vector<Uint8> digitalVect_;
		Uint16 digitalNum_;

		void Release_();
};

#endif	/* NUMBER_DISPLAYER_H */
