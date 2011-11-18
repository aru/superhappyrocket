#include "Log.h"


	// this function will take the category of log, followed by the number of elements to print, followed by all the elements
	void Log::logPrint(int category, int num, ... )
	{
		va_list vl;							// A place to store the list of arguments					
		va_start(vl, num);					// Initializing arguments to store all values after num

		if (category==EVENT)
		{
			for(int x = 0; x < num; x++)	// Loop until all elements are printed
				std::cout <<  va_arg(vl, int) << " " ;
			std::cout << "\n";
			va_end ( vl );					 // Cleans up the list
		}
	}
