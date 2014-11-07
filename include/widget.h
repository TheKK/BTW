/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: widget.h
 */

#ifndef WIDGET_H
#define WIDGET_H

#include <SDL2/SDL.h>
#include <vector>

#include "renderable.h"
#include "sound.h"

using namespace std;

class Widget
{
	public:
		virtual ~Widget();

		virtual void Update() = 0;
		virtual void EventHandler(const SDL_Event& event) = 0;
		virtual void Render() = 0;

		void Pause();
		void Resume();
	protected:
		/* State */
		bool debugOff_ = true;
		bool isPaused_ = false;

		/* Graphic */
		SDL_Renderer* targetRenderer_ = nullptr;

		/* XXX: Is that right to put sound list here?? */
		/* Sound */
		vector<Sound*> soundList_;

		/* Functions */
		void PauseAllSound_();
		void ResumeAllSound_();
};

#endif	/* WIDGET_H */
