/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: gameActor_Zup.h
 */

#ifndef GAME_ACTOR_ZUP_H
#define GAME_ACTOR_ZUP_H

#include <map>
#include <string>

#include "gameActor.h"
#include "sprite.h"

namespace {
	/* Walking */
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

	void startJump();
	void stopJump();

	void faceRight();
	void faceLeft();

	void normalAttack();
private:
	enum HorizontalFacing {
		RIGHT,
		LEFT
	};

	enum MotionType {
		STANDING,
		WALKING,
		JUMPING,
		FALLING
	};

	struct SpriteState
	{
		SpriteState(enum HorizontalFacing facing,
			    enum MotionType motion):
			horizontalFacing(facing),
			motionType(motion) {};

		HorizontalFacing horizontalFacing;
		MotionType motionType;
	};
	friend bool operator<(const SpriteState& a, const SpriteState& b);

	HorizontalFacing horizontalFacing_;

	std::map<SpriteState, Sprite*> spriteSheets_;

	int spriteDelay_;

	void initSprites_(Graphics& graphics);
	const SpriteState getSpriteState_() const;
};

#endif /* GAME_ACTOR_ZUP_H */
