#ifndef AUDIO_HANDLER
#define AUDIO_HANDLER

/*Sounds clasification, we can locate sounds
  in a matrix easily, this way
  Referred as <TYPE OF THE SOUND>
 */
	
enum {
	MUSIC_SOUND, MUSIC_GAMEPLAY_SOUND, FX_SOUND, 
	MENU_SOUND, ACHIEVEMENTS_SOUND, OTHER_SOUND
};

//Number of sound classes
#define NUM_SOUND_CLASSES 6	
/*Here we just define the number of the sounds
  of each clasification, located in Sounds folder*/
#define NUM_MUSIC_TRACKS 5
#define NUM_GAMEPLAY_MUSIC_TRACKS 5
#define NUM_FX_TRACKS 5
#define NUM_MENU_TRACKS 5
#define NUM_ACHIEVEMENTS_TRACKS 5
#define NUM_OTHER_TRACKS 3

/*IDE Relative paths stuff*/
#if defined(__APPLE__)
#define PATH_AUDIO "../../../../Sounds/" 
#include "SDL_mixer/SDL_mixer.h"
#elif defined(__LINUX__)
#define PATH_AUDIO "../../Sounds/"
#elif defined(WIN32)
#define PATH_AUDIO "../Sounds/"
#include "SDL_mixer.h" //SDL_mixer
#endif 

/*This is IMPORTANT, this is the way the sound
  files must be named, for example:
  shr_music_1.wav
  shr_menu_20.wav
  initWavs() will automatically load every sound
  file with NUM_*_TRACKS definition.
 */
#define MUSIC_FILENAME "shr_music_"
#define MUSIC_GAMEPLAY_FILENAME "shr_gp_music_"
#define FX_FILENAME "shr_fx_"
#define MENU_FILENAME "shr_menu_"
#define ACHIEVEMENTS_FILENAME "shr_achievements_"
#define OTHER_FILENAME "shr_other_"

/*We will use WAV extension*/
#define DEFAULT_EXTENSION ".wav"

#include <stdlib.h>


class AudioHandler
{
private:
	
	//Stuff needed by SDL_mixer
	int audio_rate;
	Uint16 audio_format;
	int audio_channels;
	int audio_buffers;
	
	/*Structures needed to save the sounds, paths, channels*/
	Mix_Chunk *sounds[NUM_SOUND_CLASSES][10];
	int channels[NUM_SOUND_CLASSES][10];
	char paths[NUM_SOUND_CLASSES][10][100];
	int sound_sizes[NUM_SOUND_CLASSES];
	char* filenames[NUM_SOUND_CLASSES];
	
public:
	
	AudioHandler() {
		initializeAudio();
		initWavs();
	}
	int initializeAudio();
	int initWavs();
	void closeAudio();
	
	/*Functions you're gonna use*/
	void playSound(int index,int type);
	void stopSound(int index, int type);
	void pauseSound(int index, int type);
	void resumeSound(int index, int type);
	
};


#endif