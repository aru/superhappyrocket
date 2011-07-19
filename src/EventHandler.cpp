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


void EventHandler::MouseMotion(int x1, int y1, int x2, int y2)
{
	xPrev = x1;
	yPrev = y1;
	xPost = x2;
	yPost = y2;
	//Display
	std::cout << "x1[ " << x1 << "] y1[" << y1 << "]\tx2[" << x2 << "] y2[" << y2 << "]\n";
}


void EventHandler::MouseClicked(int button_, int x, int y)
{
	button = button_;
	xPressed = x;
	yPressed = y;
	//Display
	std::cout << "Button[" << button << "] x[" << x << "] y[" << y << "]\n";
}


/*Event catcher skeleton*/
int EventHandler::Catch()
{ SDL_Event event;
	while ( SDL_PollEvent(&event) ) {
		switch (event.type) {
			case SDL_KEYDOWN:
			case SDL_PRESSED:
				//Just to test audio stuff
				if(strcmp(SDL_GetKeyName(event.key.keysym.sym),"escape")==0)
					return 1;
				if(strcmp(SDL_GetKeyName(event.key.keysym.sym),"1")==0)
					return 2;
				if(strcmp(SDL_GetKeyName(event.key.keysym.sym),"2")==0)
					return 3;
				if(strcmp(SDL_GetKeyName(event.key.keysym.sym),"3")==0)
					return 4;
				if(strcmp(SDL_GetKeyName(event.key.keysym.sym),"4")==0)
					return 5;
				if(strcmp(SDL_GetKeyName(event.key.keysym.sym),"5")==0)
					return 6;
				if(strcmp(SDL_GetKeyName(event.key.keysym.sym),"q")==0)
					return 10;
				if(strcmp(SDL_GetKeyName(event.key.keysym.sym),"w")==0)
					return 11;
				if(strcmp(SDL_GetKeyName(event.key.keysym.sym),"e")==0)
					return 12;
				if(strcmp(SDL_GetKeyName(event.key.keysym.sym),"r")==0)
					return 13;
				if(strcmp(SDL_GetKeyName(event.key.keysym.sym),"t")==0)
					return 14;
				if(strcmp(SDL_GetKeyName(event.key.keysym.sym),"a")==0)
					return 20;
				if(strcmp(SDL_GetKeyName(event.key.keysym.sym),"s")==0)
					return 21;
				if(strcmp(SDL_GetKeyName(event.key.keysym.sym),"d")==0)
					return 22;
				if(strcmp(SDL_GetKeyName(event.key.keysym.sym),"f")==0)
					return 23;
				if(strcmp(SDL_GetKeyName(event.key.keysym.sym),"g")==0)
					return 24;
				if(strcmp(SDL_GetKeyName(event.key.keysym.sym),"z")==0)
					return 30;
				if(strcmp(SDL_GetKeyName(event.key.keysym.sym),"x")==0)
					return 31;
				if(strcmp(SDL_GetKeyName(event.key.keysym.sym),"c")==0)
					return 32;
				if(strcmp(SDL_GetKeyName(event.key.keysym.sym),"v")==0)
					return 33;
				if(strcmp(SDL_GetKeyName(event.key.keysym.sym),"b")==0)
					return 34;
				
				DisplayState(&event.key);
				DisplayModifiers(&event.key);
				DisplayKey(&event.key);
				break;
			case SDL_MOUSEMOTION:
				MouseMotion(event.motion.xrel,event.motion.yrel,event.motion.x,event.motion.y);
				break;
			case SDL_MOUSEBUTTONDOWN:
				MouseClicked(event.button.button,event.button.x,event.button.y);
				break;
			case SDL_QUIT:
				return 1;
		}
	}
	return 0;
}

