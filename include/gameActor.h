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

	virtual bool isOnGround() = 0;

	void move(int dx, int dy);
	void moveXto(int n);
	void moveYto(int n);

	void setW(int n);
	void setH(int n);

	void setRenderer(SDL_Renderer* renderer);

	virtual void applyAcc(int x, int y) = 0;
	virtual void setAccY(int n) = 0;

	int x() const;
	int y() const;
	int w() const;
	int h() const;
	SDL_Rect* rect();
	SDL_Renderer* renderer() const;
protected:
	SDL_Renderer* renderer_ = nullptr;
	SDL_Rect posRect_ = {0};
	int velX = 0;
	int velY = 0;

	int gY = 0;
};

#endif /* GAME_ACTOR_H */
