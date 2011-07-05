/*	Quick re-cap
	Things engine needs to do:
		* Everything XNA does with the Game class (will explain later)
	
*/

#include <cassert>
#include <cctype>
#include <cfloat>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

class Simple3DEngine
{
	void Init();
	void Load();
	void Draw();
	void Update();
	void Unload();
	void Shutdown();
};