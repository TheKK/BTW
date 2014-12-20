/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: hpBar.h
 */

#ifndef HP_BAR_H
#define HP_BAR_H

#include <SDL.h>

#include "texture.h"

class Graphics;
class GameActor;

class HPBar
{
public:
	HPBar(Graphics& graphics);
	~HPBar();

	void update();
	void render(Graphics& graphics);

	void bindGameActor(const GameActor& actor);
private:
	Texture hpBarTex_;
	SDL_Rect posRect_ = {0};

	const GameActor* actor_;
};

#endif /* HP_BAR_H */
