/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: gameActor.h
 */

#ifndef GAME_ACTOR_H
#define GAME_ACTOR_H

#include <vector>
#include <SDL.h>

#include "position.h"

using namespace std;

enum FaceDirection
{
	FACE_RIGHT = 0x00,
	FACE_LEFT,
};

enum ActorSprite
{
	SPRITE_ON_GROUND = 0x00,
	SPRITE_JUMPING,
	SPRITE_DIVE,
	SPRITE_NORMAL_ATTACK,

	SPRITE_COUNT
};

class Sprite;
class Bullet;
class StateMachine;
class Graphics;

class GameActor
{
public:
	GameActor();
	virtual ~GameActor();

	virtual void handleInput() = 0;
	virtual void update() = 0;
	virtual void render(Graphics& graphics) = 0;

	/* Base class should override the functions it need */
	virtual void movingRight() {};
	virtual void movingLeft() {};
	virtual void stopMoving() {};
	virtual void jump() {};
	virtual void dive() {};
	virtual void normalAttack() {};
	virtual void normalAirAttack() {};

	int16_t hp() const;

	void applyAcc(float x, float y);
	void setVelX(float n);
	void setVelY(float n);
	float velX() const;
	float velY() const;

	void setGravity(float g);
	void setHorizon(int h);
	float gravity() const;
	int horizon() const;

	bool isOnGround() const;
	enum FaceDirection direction() const;

	void addBullet(Bullet* bullet);
	const vector<Bullet*>& bulletList();
	void testBulletCollision(GameActor& caster);
	void updateBullet(GameActor& target);
	void renderBullet();

	void setAsInvisible();
	void setAsVisible();
	bool isInvisible() const;

	const Position& pos() const;

	void setSprite(enum ActorSprite which);
protected:
	int16_t hp_ = 100;
	bool isInvisible_ = false;

	Position pos_;
	float velX_ = 0.0f;
	float velY_ = 0.0f;
	float accX_ = 0.0f;
	float accY_ = 0.0f;
	float gravity_ = 0;
	int horizon_ = 0;
	enum FaceDirection direction_ = FACE_RIGHT;

	StateMachine* stateMachine_ = nullptr;

	vector<Bullet*> bulletList_;

	Sprite* currentSprite_ = nullptr;
	vector<Sprite*> spriteList_;
};

#endif /* GAME_ACTOR_H */
