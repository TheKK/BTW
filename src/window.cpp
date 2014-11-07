/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: window.cpp
 */

#include "window.h"

Window::Window(string windowTitle, int width, int height, bool useOpenGL)
{
	title_ = windowTitle;

	/* Create and setup new SDL window, and check error */
	window_ = SDL_CreateWindow(
		title_.c_str(),
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		width, height,
		SDL_WINDOW_SHOWN
		);
	if (window_ == nullptr) {
		string errMsg("SDL window error: ");
		errMsg += SDL_GetError();
		throw runtime_error(errMsg);
	}

	/* Create and setup new SDL renderer, and check error */
	renderer_ = SDL_CreateRenderer(
		window_,
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
		);
	if (renderer_ == nullptr) {
		string errMsg("SDL renderer error: ");
		errMsg += SDL_GetError();
		throw runtime_error(errMsg);
	}

	/* Make fullscreen fit physical screen */
	SDL_RenderSetLogicalSize(renderer_, width, height);

	windowID_ = SDL_GetWindowID(window_);
}

Window::~Window()
{
	Release_();
}

void
Window::EventHandler(const SDL_Event& event)
{
	switch (event.type) {
	case SDL_WINDOWEVENT:
		if (event.window.windowID == windowID_) {
			switch (event.window.event) {
			//Get mouse focus
			case SDL_WINDOWEVENT_ENTER:
				isFocused_ = true;
				break;
			//Lost mouse focus
			case SDL_WINDOWEVENT_LEAVE:
				isFocused_ = false;
				break;
			}
		}
	}
}

void
Window::Clear()
{
	SDL_SetRenderDrawColor(renderer_,
			       clearColor_.r,
			       clearColor_.g,
			       clearColor_.b,
			       clearColor_.a);
	SDL_RenderClear(renderer_);
}

void
Window::Present()
{
	SDL_RenderPresent(renderer_);
}

void
Window::Resize(int width, int height)
{
	SDL_SetWindowSize(window_, width, height);
}

void
Window::SetTitle(const string& title)
{
	SDL_SetWindowTitle(window_, title.c_str());
}

void
Window::MoveTo(int x, int y)
{
	SDL_SetWindowPosition(window_, x, y);
}

void
Window::Show()
{
	SDL_ShowWindow(window_);
}

void
Window::Hide()
{
	SDL_HideWindow(window_);
}

void
Window::SetClearColor(SDL_Color value)
{
	clearColor_ = value;
}

int
Window::PosX() const
{
	int xToReturn;
	SDL_GetWindowPosition(window_, &xToReturn, nullptr);
	return xToReturn;
}


int
Window::PosY() const
{
	int yToReturn;
	SDL_GetWindowPosition(window_, nullptr, &yToReturn);
	return yToReturn;
}

int
Window::Width() const
{
	int wToReturn;
	SDL_GetWindowSize(window_, &wToReturn, nullptr);
	return wToReturn;
}

int
Window::Height() const
{
	int hToReturn;
	SDL_GetWindowSize(window_, nullptr, &hToReturn);
	return hToReturn;
}

SDL_Rect
Window::Rect() const
{
	SDL_Rect rectToReturn;
	SDL_GetWindowSize(window_, &rectToReturn.w, &rectToReturn.h);
	SDL_GetWindowPosition(window_, &rectToReturn.x, &rectToReturn.y);
	return rectToReturn;
}

bool
Window::IsWindowed() const
{
	return isWindowed_;
}

bool
Window::IsFocused() const
{
	return isFocused_;
}

SDL_Window*
Window::GetWindow() const
{
	return window_;
}

SDL_Renderer*
Window::GetRenderer() const
{
	return renderer_;
}

Uint32
Window::ID() const
{
	return windowID_;
}

void
Window::Release_()
{
	SDL_DestroyWindow(window_);
	window_ = nullptr;

	SDL_DestroyRenderer(renderer_);
	renderer_ = nullptr;
}
