#include "AudioManager.h"

AudioManager::AudioManager() {}
AudioManager::~AudioManager() {}
int AudioManager::loadMusic(const char * file)
{
	music = Mix_LoadMUS( file );
	if( music )
		return 0;
	else
		return 1;
}

int AudioManager::playMusic()
{
		//If there is no music playing
        if( Mix_PlayingMusic() == 0 )
        {
                //Play the music
               if( Mix_PlayMusic( music, -1 ) == -1 )
               {
                    return 1;
			   }    
         }
		return 0;
}