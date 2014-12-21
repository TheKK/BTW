/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: position.h
 */

#ifndef POSITION_H
#define POSITION_H

#include <SDL.h>

class Position
{
public:
	Position();
	Position(float x, float y, int w, int h);
	~Position();

	void moveBy(float dx, float dy);
	void moveTo(float x, float y);

	void setX(float n);
	void setY(float n);
	void setW(int n);
	void setH(int n);

	void setRect(float x, float y, int w, int h);

	int x() const;
	int y() const;
	int w() const;
	int h() const;

	int top() const;
	int button() const;
	int left() const;
	int right() const;

	const SDL_Rect* rect();
private:
	float posX_ = 0;
	float posY_ = 0;
	SDL_Rect posRect_ = {0};
};

#endif /* POSITION_H */
