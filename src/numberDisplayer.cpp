/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: numberDisplayer.cpp
 */

#include "numberDisplayer.h"

NumberDisplayer::NumberDisplayer(string picPath, uint8_t displayDigitalNum,
				uint16_t digitalWidth, uint16_t digitalHeight,
				 SDL_Renderer* renderer):
	numSprite_(picPath, renderer, digitalWidth, digitalHeight),
	digitalNum_(displayDigitalNum)
{
	SetRenderer(renderer);

	/* Set rendering size of this displayer */
	SetSize(digitalWidth * displayDigitalNum, digitalHeight);

	/* Set vector size and init value */
	digitalVect_.resize(digitalNum_);

	CounterSetZero();
}

NumberDisplayer::~NumberDisplayer()
{
	Release_();
}

void
NumberDisplayer::AddNum(uint32_t value)
{
	Uint32 toNext = 0;

	digitalVect_[digitalNum_- 1] += value;
	if (digitalVect_[digitalNum_ - 1] > 9) {
		digitalVect_[digitalNum_ - 1] -= 10;
		toNext = 1;
	}

	for (int i = digitalNum_ - 2; i >= 0; i--) {
		digitalVect_[i] += toNext;

		if (digitalVect_[i] > 9) {
			toNext = 1;
			digitalVect_[i] -= 10;
		} else {
			break;
		}
	}
}

void
NumberDisplayer::SetNum(int value)
{
	SDL_assert(value < pow(10, digitalNum_));
	for (int i = 0; i < digitalNum_; i++) {
		digitalVect_[i] = value / pow(10, digitalNum_ - 1 - i);
		value -= pow(10, digitalNum_ - 1 - i) * digitalVect_[i];
	}
}

uint64_t
NumberDisplayer::GetNum() const
{
	Uint64 toReturn = 0;

	for (int i = 0; i < digitalVect_.size(); i++)
		toReturn +=
			(digitalVect_[i] *
			 pow(10, digitalVect_.size() - i - 1));

	return toReturn;
}

void
NumberDisplayer::SetAlpha(Uint8 value)
{
	numSprite_.SetAlpha(value);
}

void
NumberDisplayer::CounterSetZero()
{
	for (auto& e: digitalVect_)
		e = 0;
}

void
NumberDisplayer::Render()
{
	for (int i = 0; i < digitalNum_; i++) {
		numSprite_.MoveTo((rect_.x + numSprite_.Width() * i), rect_.y);
		numSprite_.JumpTo(digitalVect_[i]);
		numSprite_.Render();
	}
}

void
NumberDisplayer::Release_()
{
}
