/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: window.h
 */

#ifndef WINDOW_H
#define WINDOW_H

#include <string>

#include <SDL.h>

class Window
{
public:
	Window(const char* title, uint32_t width, uint32_t height);
	~Window();

	void eventHandler(const SDL_Event& event);

	void clear();
	void present();

	void resize(int width, int height);
	void setTitle(const std::string& title);
	void moveTo(int x, int y);
	void show();
	void hide();

	int posX() const;
	int posY() const;
	int width() const;
	int height() const;

	bool isWindowed() const;
	bool isFocused() const;

	SDL_Window* window() const;
	uint32_t ID() const;
private:
	SDL_Window* window_;
	std::string title_;

	bool isFocused_;
	bool isWindowed_;
};

#endif	/* WINDOW_H */
