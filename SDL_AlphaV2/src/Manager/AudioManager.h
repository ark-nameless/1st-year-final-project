#ifndef AUDIOMANAGER_H_
#define AUDIOMANAGER_H_

#include "..\Core\Core.h"
#include <map>


namespace STAR
{
	namespace MANAGER
	{

		class AudioManager
		{
		private :
			std::map<std::string, Mix_Music *>m_MusicMap;
			std::map<std::string, Mix_Chunk *>m_SFXMap;
			
			static AudioManager *s_Instance;

		public :
			static AudioManager *GetInstance();
			static void Release();

			Mix_Music *GetMusic(std::string filename);
			Mix_Chunk *GetSFX(std::string filename);

			void PlayMusic(std::string filename, int loops = -1);
			void PauseMusic();
			void ResumeMusic();

			void PlaySFX(std::string filename, int loops = 0, int channel = 0);


		private :
			AudioManager();
			~AudioManager();
		};

	}
}




#endif