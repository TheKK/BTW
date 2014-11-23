/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: gameActor_Zup.h
 */

#ifndef GAME_ACTOR_ZUP_H
#define GAME_ACTOR_ZUP_H

#include <iostream>

#include "gameActor.h"
#include "luaStateMachine.h"
#include "sprite.h"
#include "window.h"

using namespace std;

class GameActor_Zup : public GameActor
{
public:
	GameActor_Zup();
	~GameActor_Zup();

	void handleInput(const GameActorController& controller);
	void update();
	void render();

	void updatePosAndSprite();
	void moveRight();
	void moveLeft();
private:
	Sprite sprite_onGround_;
	//Sprite sprite_onGroundAttack_;
	Sprite sprite_jumping_;
	//Sprite sprite_jumpingAttack_;

	LuaStateMachine machine_;

	int frictionDelay_;
	int spriteDelay_;
};

#endif /* GAME_ACTOR_ZUP_H */
