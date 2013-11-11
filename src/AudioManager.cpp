#include "AudioManager.h"

AudioManager::AudioManager() {}

AudioManager::AudioManager( Context* ctx )
	:ctxt( ctx ), music( 0 )
{
	/* For now this is the default setup */
	audio_rate = 22050;
	audio_format = MIX_DEFAULT_FORMAT;
	audio_channels = 2;
	audio_buffers = 4096;
}

AudioManager::~AudioManager()
{
	/* Free the music */
	if( music )
		Mix_FreeMusic( music );

	/* Close the SDL_mixer */
	Mix_CloseAudio();
}

int AudioManager::Initialize()
{
	int i, n;

	/* Prepares everything */
	Mix_Init( MIX_INIT_MP3 | MIX_INIT_OGG );

	if( Mix_OpenAudio( audio_rate, MIX_DEFAULT_FORMAT, audio_channels, audio_buffers ) )
	{
		printf("Unable to open audio");
		return 1;
	}

	/* Print out info on supported formats */
	n = Mix_GetNumChunkDecoders();
	printf("%d available chunk(sample) decoders:\n",n);
	for( i = 0; i < n; i++ )
	{
		printf("\t%s\n", Mix_GetChunkDecoder( i ));
	}
	n = Mix_GetNumMusicDecoders();
	printf("%d available music decoders:\n",n);
	for( i = 0; i < n; i++ )
	{
		printf("\t%s\n", Mix_GetMusicDecoder( i ));
	}

	return 0;
}

int AudioManager::LoadMusic(const char * file)
{
	music = Mix_LoadMUS( file );
	if( music )
	{
		return 0;
	}
	else
	{
		printf("Unable to load music: %s\nReason: %s", file, Mix_GetError());
		return 1;
	}
}

int AudioManager::PlayMusic()
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

int AudioManager::LoadSound( const char* file )
{
	int beforeSize = sounds.size();
	int afterSize = 0;
	Mix_Chunk* temp;

	temp = Mix_LoadWAV( file );
	sounds.push_back( temp );
	afterSize = sounds.size();

	if( afterSize - beforeSize == 1 )
		return beforeSize;
	else
		return -1;
}

int AudioManager::PlaySound( int soundFile, int loopTimes )
{
	/* If soundFile is -1 we are trying to query all channels
	 * else, we are looking for a specific channel
	 * but when we try to play on channel -1, we play on the 
	 * first available channel
     */

	 /* Are we playing music in the current channel? */
	if( Mix_Playing( soundFile ) != 0 )
		return 0; // We are, bail out for now

	if( soundFile == 0 )
		return Mix_PlayChannel( -1, sounds.at( soundFile ), loopTimes );

	// Some error happened
	return 0;
}

int AudioManager::LoadContent()
{
	return SHR_SUCCESS;
}

int AudioManager::UnloadContent()
{
	return SHR_SUCCESS;
}