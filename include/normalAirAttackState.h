/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: normalAirAttackState.h
 */

#ifndef NORMAL_AIR__ATTACK_STATE_H
#define NORMAL_AIR__ATTACK_STATE_H

#include <iostream>
#include <SDL.h>

#include "state.h"
#include "gameActor.h"
#include "potionBullet.h"

using namespace std;

class NormalAirAttackState : public State
{
public:
	~NormalAirAttackState() {};

	void onEnter(GameActor& actor);
	void onExit(GameActor& actor);

	void eventHandler(GameActor& actor, const SDL_Event& event);
	void update(GameActor& actor);
private:
	int frameCount;
};

#endif /* NORMAL_AIR__ATTACK_STATE_H */
