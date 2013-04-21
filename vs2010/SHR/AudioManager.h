#ifndef AUDIO_MANAGER
#define AUDIO_MANAGER

#include "SDL_mixer.h"
#include "Context.h"

class AudioManager {
public:
	AudioManager();
	~AudioManager();
	int loadMusic(const char* file);
	int playMusic();
	int pauseMusic();
	int stopMusic();
	int cleanUp();

	Context* ctxt;
	Mix_Music *music;

};

#endif