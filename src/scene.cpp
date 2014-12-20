/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: scene.cpp
 */

#include "scene.h"

Scene::~Scene()
{
}

bool
Scene::hasNext() const
{
	return (next_ != SCENE_NULL);
}

enum SceneList
Scene::next() const
{
	return next_;
}

void
Scene::setNext(enum SceneList next)
{
	next_ = next;
}
