#ifndef AUDIO_H
#define AUDIO_H

// declaracao das funcoes --------------------------
void StartMusic(); // start playing a music that could be identified by a config file
void ChangeMusic(int musicIdx); // change music to another one
void PauseMusic(); // pauses music

void PlaySoundIdx(int soundIdx); // play a sound that could be identified by a index
void ChangeMusicVolume(float volume, int musicIdx); // change the music volume
void ResumeMusic(int musicIDX);
int LoadSoundFile(const char *fileName); // load sound and save in dynamic array of sounds
int LoadMusicFile(const char *fileName); // load music and save in dynamic array of musics

void UnloadAll_Audio(); // unload all sounds and musics and free memory
// ---------------------------------------------------
#endif
