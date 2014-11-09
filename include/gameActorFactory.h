/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: gameActorFactory.h
 */

#ifndef GAME_ACTOR_FACTORY_H
#define GAME_ACTOR_FACTORY_H

#include <iostream>

#include "gameActor.h"

using namespace std;

class GameActorFactory
{
public:
	static void buildActor(GameActor& actor, char* recipe);
private:
	GameActorFactory() {};
};

#endif /* GAME_ACTOR_FACTORY_H */
