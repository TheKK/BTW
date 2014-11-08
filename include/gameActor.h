/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: gameActor.h
 */

#ifndef GAME_ACTOR_H
#define GAME_ACTOR_H

#include <iostream>
#include <SDL.h>

using namespace std;

class GameActor
{
public:
	virtual ~GameActor() {};

	virtual void eventHandler(const SDL_Event& event) = 0;
	virtual void update() = 0;
	virtual void render() = 0;

	void applyAcc(int x, int y);
	void setVelX(int n);
	void setVelY(int n);

	void setGravity(int g);
	void setHorizon(int h);

	bool isOnGround();

	void moveBy(int dx, int dy);
	void moveTo(int x, int y);
	void moveXto(int n);
	void moveYto(int n);

	void setW(int n);
	void setH(int n);

	int x() const;
	int y() const;
	int w() const;
	int h() const;
	SDL_Rect* rect();
	SDL_Renderer* renderer() const;

	virtual void moveRight() = 0;
	virtual void moveLeft() = 0;
	virtual void jump() = 0;
	virtual void land() = 0;
	virtual void dive() = 0;
protected:
	SDL_Renderer* renderer_ = nullptr;
	SDL_Rect posRect_ = {0};
	int velX_ = 0;
	int velY_ = 0;

	int gravity_ = 0;
	int horizon_ = 0;
};

#endif /* GAME_ACTOR_H */
