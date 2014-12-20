/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: gameActor_Zup.h
 */

#ifndef GAME_ACTOR_ZUP_H
#define GAME_ACTOR_ZUP_H

#include "gameActor.h"
#include "sprite.h"

namespace {
	const float walkingSpeedMax = 5.0f;
	const float walkingAcceleration = 0.4f;
	const float slowdownFator = 0.85f;
}

class Graphics;
class Controller;

class GameActor_Zup : public GameActor
{
public:
	GameActor_Zup(Graphics& graphics, const Controller& controller);
	~GameActor_Zup();

	void handleInput();
	void update();
	void render(Graphics& graphics);

	void updateSprite();
	void updatePosition();

	void movingRight();
	void movingLeft();
	void stopMoving();
	void normalAttack();
private:
	Sprite sprite_onGround_;
	Sprite sprite_normalAttack_;
	Sprite sprite_jumping_;

	int frictionDelay_;
	int gravityDelay_;
	int spriteDelay_;
};

#endif /* GAME_ACTOR_ZUP_H */
