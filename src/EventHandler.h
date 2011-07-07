#ifndef EVENT_HANDLER
#define EVENT_HANDLER

#include <iostream>
#include <string>
#include "SDL.h"

class EventHandler
{
	private:
		
	public:
		EventHandler() { }
		void DisplayModifiers(SDL_KeyboardEvent *key);
		void DisplayKey(SDL_KeyboardEvent *key);
		void DisplayState(SDL_KeyboardEvent *key);
		void MouseMotion(int x1, int y1, int x2, int y2);
		void MouseClicked(int button, int x, int y);
		int Catch();
		int xPrev, yPrev, xPost, yPost;
		int button, xPressed, yPressed;
};
#endif