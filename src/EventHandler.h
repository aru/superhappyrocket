#ifndef EVENT_HANDLER
#define EVENT_HANDLER

#include <iostream>

class EventHandler
{
	private:
		
	public:
		EventHandler() { }
		void DisplayModifiers(SDL_KeyboardEvent *key);
		void DisplayKey(SDL_KeyboardEvent *key);
		void DisplayState(SDL_KeyboardEvent *key);
		int Catch();
};
#endif