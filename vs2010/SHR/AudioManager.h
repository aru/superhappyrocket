/**
 * AudioManager.h
 *
 * Manages the audio on the current context
 * responsible for loading, playing, pausing, stoppingand shutting down
 * the audio.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details http://www.gnu.org/licenses/.
 */

#ifndef AUDIO_MANAGER
#define AUDIO_MANAGER

#include "SDL_mixer.h"
#include "Context.h"

class AudioManager {
public:
	AudioManager( Context* ctx );
	AudioManager();
	~AudioManager();
	int loadMusic(const char* file);
	int playMusic();
	int pauseMusic();
	int stopMusic();
	int shutDown();

	Context* ctxt;
	Mix_Music *music;

};

#endif