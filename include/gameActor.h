/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: gameActor.h
 */

#ifndef GAME_ACTOR_H
#define GAME_ACTOR_H

#include <iostream>
#include <vector>
#include <SDL.h>

#include "bullet.h"
#include "sprite.h"
#include "gameActorController.h"

using namespace std;

enum ActorDirection
{
	ACTOR_FACE_RIGHT = 0x00,
	ACTOR_FACE_LEFT,
};

enum ActorSprite
{
	SPRITE_ON_GROUND = 0x00,
	SPRITE_JUMPING,
	SPRITE_DIVE,
	SPRITE_NORMAL_ATTACK,

	SPRITE_COUNT
};

class Bullet;
class GameActorController;

class GameActor
{
public:
	GameActor();
	virtual ~GameActor();

	virtual void handleInput(const GameActorController& controller) = 0;
	virtual void update() = 0;
	virtual void render() = 0;

	/* Base class should override the functions it need */
	virtual void moveRight() {};
	virtual void moveLeft() {};
	virtual void jump() {};
	virtual void land() {};
	virtual void dive() {};
	virtual void normalAttack() {};
	virtual void normalAirAttack() {};

	void addBullet(Bullet* bullet);
	vector<Bullet*>* bulletList();
	void testBulletCollision(GameActor& caster);
	void updateBullet(GameActor& target);
	void renderBullet();

	void applyAcc(int x, int y);
	void setVelX(int n);
	void setVelY(int n);

	void setAsInvisible();
	void setAsVisible();
	bool isInvisible();

	void setGravity(int g);
	void setHorizon(int h);
	int getGravity();
	int getHorizon();

	bool isOnGround();
	enum ActorDirection direction();

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

	void setSprite(enum ActorSprite which);
protected:
	SDL_Rect posRect_ = {0};
	int velX_ = 0;
	int velY_ = 0;

	bool isInvisible_ = false;

	int gravity_ = 0;
	int horizon_ = 0;

	enum ActorDirection direction_ = ACTOR_FACE_RIGHT;

	vector<Bullet*> bulletList_;

	Sprite* currentSprite_ = nullptr;
	vector<Sprite*> spriteList_;
};

#endif /* GAME_ACTOR_H */
