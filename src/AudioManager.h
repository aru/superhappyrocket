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

#ifndef SHR_AUDIOMANAGER
#define SHR_AUDIOMANAGER

#include <SDL_mixer.h>
#include <vector>

#include "Context.h"

class AudioManager{
public:

	AudioManager();
	AudioManager( Context* ctx );
	~AudioManager();

	/* Standard Engine Methods */
	int Initialize();
	int LoadContent();
	int Update();
	int UnloadContent();

	/* Public Methods for the BG Music */
	int LoadMusic( const char* file );
	int PlayMusic();

	/* Public Methods for sounds */
	int LoadSound( const char* file );
	int PlaySound( int soundFile, int loopTimes );
	int PauseSound( int soundFile );
	int StopSound( int soundFile );

	/* Context Pointer */
	Context* ctxt;
	/* Background Music */
	Mix_Music* music;
	/* vector array that points to current sound files */
	std::vector<Mix_Chunk*> sounds;

	/* Setup variables */
	int audio_rate;
	int audio_format; 
	int audio_channels;
	int audio_buffers;
};

#endif