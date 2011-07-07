#include "EventHandler.h"


/*Getting modifier keys*/
void EventHandler::DisplayModifiers(SDL_KeyboardEvent *key)
{
	SDLMod modifier = key->keysym.mod;
	if( modifier & KMOD_NUM ) std::cout << "NUMLOCK" << std::endl;
	if( modifier & KMOD_CAPS ) std::cout << "CAPSLOCK" << std::endl;
	if( modifier & KMOD_MODE ) std::cout << "MODE" << std::endl;
	if( modifier & KMOD_LCTRL ) std::cout << "LCTRLn" << std::endl;
	if( modifier & KMOD_RCTRL ) std::cout << "RCTRL" << std::endl;
	if( modifier & KMOD_LSHIFT ) std::cout << "LSHIFT" << std::endl;
	if( modifier & KMOD_RSHIFT ) std::cout << "RSHIFT" << std::endl;
	if( modifier & KMOD_LALT ) std::cout << "LALT" << std::endl;
	if( modifier & KMOD_RALT ) std::cout << "RALT" << std::endl;
	if( modifier & KMOD_LMETA ) std::cout << "LMETA" << std::endl;
	if( modifier & KMOD_RMETA ) std::cout << "RMETA" << std::endl;
}

/* Just displaying the key name*/
void EventHandler::DisplayKey(SDL_KeyboardEvent *key)
{
	std::cout << SDL_GetKeyName(key->keysym.sym) << std::endl;
}

/*Keyboard key state*/
void EventHandler::DisplayState(SDL_KeyboardEvent *key)
{
	if (key->type == SDL_KEYUP)
		std::cout << "RELEASED: " << std::endl;
	else
		std::cout << "PRESSED: " << std::endl;
	
}

/*Event catcher skeleton*/
int EventHandler::Catch()
{ SDL_Event event;
	while ( SDL_PollEvent(&event) ) {
		switch (event.type) {
			case SDL_KEYDOWN:
			case SDL_KEYUP:
				DisplayState(&event.key);
				DisplayModifiers(&event.key);
				DisplayKey(&event.key);
				break;
			case SDL_QUIT:
				return 1;
		}
	}
	return 0;
}
