#include "AudioHandler.h"

int AudioHandler::initializeAudio(){
	
	audio_rate = 22050;
	audio_format = AUDIO_S16SYS;
	audio_channels = 2;
	audio_buffers = 4096;
	sound_sizes[0] = NUM_MUSIC_TRACKS;
	sound_sizes[1] = NUM_GAMEPLAY_MUSIC_TRACKS;
	sound_sizes[2] = NUM_FX_TRACKS;
	sound_sizes[3] = NUM_MENU_TRACKS;
	sound_sizes[4] = NUM_ACHIEVEMENTS_TRACKS;
	sound_sizes[5] = NUM_OTHER_TRACKS;
	filenames[0] = MUSIC_FILENAME;
	filenames[1] = MUSIC_GAMEPLAY_FILENAME;
	filenames[2] = FX_FILENAME;
	filenames[3] = MENU_FILENAME;
	filenames[4] = ACHIEVEMENTS_FILENAME;
	filenames[5] = OTHER_FILENAME;
	
	/*Building paths relative to OS*/
	char number[8];
	for (int i = 0; i < NUM_SOUND_CLASSES; i++) {
		for (int j = 0 ; j < sound_sizes[i]; j++) {
			strcpy(paths[i][j],PATH_AUDIO);
			strcat(paths[i][j],filenames[i]);
			sprintf(number, "%d", j);
			strcat(paths[i][j],number);
			strcat(paths[i][j],DEFAULT_EXTENSION);
			channels[i][j] = -1;
		}
	}
	if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) != 0) {
		fprintf(stderr, "Unable to initialize audio: %s\n", Mix_GetError());
	}
	return 0;
}

/*Load WAV files into the sound matrix sounds*/
int AudioHandler::initWavs(){
	
	for (int i = 0 ; i < NUM_SOUND_CLASSES; i++) {
		for (int j = 0; j < sound_sizes[i]; j++) {
			sounds[i][j] = NULL;
			sounds[i][j] = Mix_LoadWAV(paths[i][j]);
			if(!sounds[i][j]){
				printf("Mix_LoadWAV: %s\n", Mix_GetError());
				printf("%s\n", paths[i][j]);
			}
		}
	}
	return 0;
}

/*You will call play this way
  playSound(<INDEX OF THE SOUND>,<TYPE OF THE SOUND>);
  <TYPE OF THE SOUND> - e.g MUSIC_SOUND
 */
void AudioHandler::playSound(int index, int type){
	if(index <= sound_sizes[type]){
		stopSound(index,type);
		if(channels[type][index] < 1){
			channels[type][index] = Mix_PlayChannel(-1,sounds[type][index],0);
			printf("Channel Assigned: %d\n",channels[type][index]);	
			if(channels[type][index] == -1)
					fprintf(stderr, "Unable to play WAV file: %s\n", Mix_GetError());
		}
	}
	else {
		printf("Sound undefined\n");
	}

}

void AudioHandler::stopSound(int index, int type){
	if(index <= sound_sizes[type]){
		if(channels[type][index] != -1 && Mix_Playing(channels[type][index]) == 1) {
			Mix_HaltChannel(channels[type][index]);
			channels[type][index] = -1;
		}
	}
	else {
		printf("Sound undefined\n");
	}
}

void AudioHandler::pauseSound(int index, int type){
	if(index <= sound_sizes[type]){
		if(channels[type][index] != -1 && Mix_Playing(channels[type][index]) == 1) {
			Mix_Pause(channels[type][index]);
		}
	}
	else {
		printf("Sound undefined\n");
	}
}

void AudioHandler::resumeSound(int index, int type){
	if(index <= sound_sizes[type]){
		if(Mix_Paused(channels[type][index]) == 1) {
			Mix_Resume(channels[type][index]);
		}
	}
	else {
		printf("Sound undefined\n");
	}
}

void AudioHandler::closeAudio(){
	Mix_HaltChannel(-1);
	for (int i = 0; i < NUM_SOUND_CLASSES; i++) {
		for (int j = 0; j < sound_sizes[i]; j++) {
			Mix_FreeChunk(sounds[i][j]);
			sounds[i][j] = NULL;
		}
	}
	Mix_CloseAudio();
}