#include "AudioManager.h"



namespace STAR
{
	namespace MANAGER
	{

		AudioManager *AudioManager::s_Instance = NULL;


		AudioManager* AudioManager::GetInstance()
		{
			if (s_Instance == NULL)
				s_Instance = new AudioManager();

			return (s_Instance);
		}

		void AudioManager::Release()
		{
			delete s_Instance;
			s_Instance = NULL;
		}

		AudioManager::AudioManager()
		{
			if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0){
				printf("Warning! Unable to Initialize SDL_Mixer! Mix_Error: %s!\n", Mix_GetError());
			}
		}

		AudioManager::~AudioManager()
		{
			s_Instance = NULL;
			Mix_Quit();
		}

		void AudioManager::PlayMusic(std::string filename, int loops)
		{
			Mix_PlayMusic(GetMusic(filename), loops);
		}

		void AudioManager::PauseMusic()
		{
			if (Mix_PlayingMusic() != 0)
				Mix_PauseMusic();
		}

		void AudioManager::ResumeMusic()
		{
			if (Mix_PausedMusic() != 0)
				Mix_ResumeMusic();
		}


		void AudioManager::PlaySFX(std::string filename, int loops, int channel)
		{
			Mix_PlayChannel(channel, GetSFX(filename), loops);
		}

		Mix_Music *AudioManager::GetMusic(std::string filename)
		{
			std::string fullpath = CORE::ASSETBASEPATH;
			fullpath.append(filename);

			if (m_MusicMap[fullpath] == nullptr){
				m_MusicMap[fullpath] = Mix_LoadMUS(fullpath.c_str());

				if (m_MusicMap[fullpath] == nullptr)
					printf("Warning! Unable to Load Music File: %s! Mix_Error: %s!\n", fullpath.c_str(), Mix_GetError());
			}

			return (m_MusicMap[fullpath]);
		}

		Mix_Chunk *AudioManager::GetSFX(std::string filename)
		{
			std::string fullpath = CORE::ASSETBASEPATH;
			fullpath.append(filename);

			if (m_SFXMap[fullpath] == nullptr){
				m_SFXMap[fullpath] = Mix_LoadWAV(fullpath.c_str());

				if (m_SFXMap[fullpath] == nullptr)
					printf("Warning! Unable to Load SFX: %s! Mix_Errror: %s!\n", fullpath.c_str(), Mix_GetError());
			}

			return (m_SFXMap[fullpath]);
		}

	}
}


