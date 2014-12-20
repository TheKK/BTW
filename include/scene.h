/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: scene.h
 */

#ifndef SCENE_H
#define SCENE_H

#include <SDL.h>

/* XXX Not this way */
enum SceneList {
	SCENE_NULL = 0x00,

	SCENE_INTRO,
	SCENE_MAIN,

	SCENE_TEST,

	SCENE_QUIT
};

class Scene
{
public:
	virtual ~Scene();

	virtual void eventHandler(const SDL_Event& event) = 0;
	virtual void update() = 0;
	virtual void render() = 0;

	bool hasNext() const;
	enum SceneList next() const;
protected:
	void setNext(enum SceneList next);
private:
	enum SceneList next_ = SCENE_NULL;
};

#endif	/* SCENE_H */
