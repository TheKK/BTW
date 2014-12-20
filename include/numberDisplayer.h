/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: numberDisplayer.h
 */

#ifndef NUMBER_DISPLAYER_H
#define NUMBER_DISPLAYER_H

#include <vector>
#include <SDL.h>

#include "sprite.h"
#include "renderable.h"

class NumberDisplayer : public Renderable
{
public:
	NumberDisplayer(const char* filePath, Graphics& graphics,
			uint8_t howManyDigitals,
			uint16_t digitalWidth, uint16_t digitalHeight);
	~NumberDisplayer();

	void render(Graphics& graphics, const SDL_Rect* rect);

	void addNum(uint32_t value);
	void setNum(int value);
	uint64_t getNum() const;

	void setAlpha(Uint8 value);

	void counterSetZero();
private:
	Sprite numSprite_;

	std::vector<uint8_t> digitalVect_;
	uint16_t digitalNum_;

	void release_();
};

#endif	/* NUMBER_DISPLAYER_H */
