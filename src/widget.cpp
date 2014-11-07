/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: widget.cpp
 */

#include "widget.h"

Widget::~Widget()
{
}

void
Widget::Pause()
{
	isPaused_ = true;
	PauseAllSound_();
}

void
Widget::Resume()
{
	isPaused_ = false;
	ResumeAllSound_();
}

void
Widget::PauseAllSound_()
{
	for (auto& e : soundList_) {
		if (e->IsPlaying())
			e->Pause();
	}
}

void
Widget::ResumeAllSound_()
{
	for (auto& e : soundList_) {
		if (e->IsPaused())
			e->Play();
	}
}

