#include "Core.h"
#include <iostream>



namespace STAR
{
	namespace CORE
	{
		bool InitSDL()
		{
			static bool init = false;

			if (!init){
				if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0){
					printf("Warning! Unable to Initialize SDL! SDL_Error: %s!\n", SDL_GetError());
					exit(EXIT_FAILURE);
					std::cin.get();
				}
				else {
					int ImgFlag = IMG_INIT_PNG | IMG_INIT_JPG;
					if (!IMG_Init(ImgFlag) & ImgFlag){
						printf("Warning! Unable to Initialize SDL_Image! IMG_Error: %s!\n", IMG_GetError());
						exit(EXIT_FAILURE);
						std::cin.get();
					}
					else {
						if (TTF_Init() == -1){
							printf("Warning! Unable to Properly Initialize SDL_ttf! TTF_Error: %s!\n", TTF_GetError());
							exit(EXIT_FAILURE);
							std::cin.get();
						}
						else {
							if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0){
								printf("Warning! Unable to Initialize SDL_Mixer! Mix_Error: %s!\n", Mix_GetError());
								exit(EXIT_FAILURE);
								std::cin.get();
							}
						}
					}
				}
				init = true;
				return true;
			}
			return false;
		}
		void UintSDL()
		{
			SDL_Quit();
			IMG_Quit();
			TTF_Quit();
			Mix_Quit();
		}

		SDL_Surface *LoadSurface(const char *title)
		{
			SDL_Surface *newSurface = NULL;

			std::string path = ASSETBASEPATH + title;

			newSurface = IMG_Load(path.c_str());
			if (newSurface == NULL){
				printf("Warning! Unable to Load Surface from: %s! IMG_Error: %s!\n", path.c_str(), IMG_GetError());
			}

			return newSurface;
		}
		SDL_Texture *LoadTexture(SDL_Renderer *renderer, const char *name)
		{
			SDL_Texture *newTexture = NULL;
			std::string path = ASSETBASEPATH + name;

			newTexture = IMG_LoadTexture(renderer, path.c_str());

			if (newTexture == NULL){
				printf("Warning! Unable to Load Texture From: %s! IMG_Error: %s!\n", path.c_str(), SDL_GetError());
			}

			return newTexture;
		}
	}
}