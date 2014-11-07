/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: window.h
 */

#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <string>
#include <stdexcept>

#include <SDL2/SDL.h>

using namespace std;

class Window
{
	public:
		Window(string windowTitle, int width, int height,
				bool useOpenGL = false);
		~Window();

		void EventHandler(const SDL_Event& event);

		void Clear();
		void Present();

		/* Function to control this object */
		void Resize(int width, int height);
		void SetTitle(const string& title);
		void MoveTo(int x, int y);
		void Show();
		void Hide();

		void SetClearColor(SDL_Color value);

		/* Function to get object states or statuses */
		int PosX() const;
		int PosY() const;
		int Width() const;
		int Height() const;
		SDL_Rect Rect() const;

		bool IsWindowed() const;
		bool IsFocused() const;

		SDL_Window* GetWindow() const;
		SDL_Renderer* GetRenderer() const;
		Uint32 ID() const;
	private:
		SDL_Window* window_ = nullptr;
		string title_;
		Uint32 windowID_;

		SDL_Renderer* renderer_ = nullptr;
		SDL_Color clearColor_ = {31, 31, 31, 255};

		bool isFocused_ = false;
		bool isWindowed_ = true;

		bool useOpenGL_ = false;

		void Release_();
};

#endif	/* WINDOW_H */
