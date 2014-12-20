/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: window.cpp
 */

#include "window.h"

#include <stdexcept>

Window::Window(const char* title, uint32_t width, uint32_t height)
{
	title_ = title;

	/* Create and setup new SDL window, and check error */
	window_ = SDL_CreateWindow(
		title_.c_str(),
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		width, height,
		SDL_WINDOW_SHOWN
		);
	if (window_ == nullptr) {
		std::string errMsg("SDL window error: ");
		errMsg += SDL_GetError();
		throw std::runtime_error(errMsg);
	}
}

Window::~Window()
{
	SDL_DestroyWindow(window_);
	window_ = nullptr;
}

void
Window::eventHandler(const SDL_Event& event)
{
	switch (event.type) {
	case SDL_WINDOWEVENT:
		if (event.window.windowID == ID()) {
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
Window::resize(int width, int height)
{
	SDL_SetWindowSize(window_, width, height);
}

void
Window::setTitle(const std::string& title)
{
	SDL_SetWindowTitle(window_, title.c_str());
}

void
Window::moveTo(int x, int y)
{
	SDL_SetWindowPosition(window_, x, y);
}

void
Window::show()
{
	SDL_ShowWindow(window_);
}

void
Window::hide()
{
	SDL_HideWindow(window_);
}

int
Window::posX() const
{
	int xToReturn;
	SDL_GetWindowPosition(window_, &xToReturn, nullptr);
	return xToReturn;
}


int
Window::posY() const
{
	int yToReturn;
	SDL_GetWindowPosition(window_, nullptr, &yToReturn);
	return yToReturn;
}

int
Window::width() const
{
	int wToReturn;
	SDL_GetWindowSize(window_, &wToReturn, nullptr);
	return wToReturn;
}

int
Window::height() const
{
	int hToReturn;
	SDL_GetWindowSize(window_, nullptr, &hToReturn);
	return hToReturn;
}

bool
Window::isWindowed() const
{
	return isWindowed_;
}

bool
Window::isFocused() const
{
	return isFocused_;
}

SDL_Window*
Window::window() const
{
	return window_;
}

uint32_t
Window::ID() const
{
	return SDL_GetWindowID(window_);
}
