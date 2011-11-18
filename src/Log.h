#ifndef LOG
#define LOG

#include <iostream>
#include <string>
#include <cstdarg>
#include "SDL.h"

class Log
{
	private:

	public:
		Log() { }
		static void logPrint(int category, int num,  ...);

		static enum myFlag { AUDIO , EVENT, RENDER	};

};
#endif