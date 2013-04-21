#include "AudioManager.h"

AudioManager::AudioManager() {}
AudioManager::~AudioManager() {
	
}
AudioManager::AudioManager( Context* ctx )
	:ctxt(ctx)
{
}
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

int AudioManager::shutDown()
{
	// Free the music
    Mix_FreeMusic( music );
	return 0;
}