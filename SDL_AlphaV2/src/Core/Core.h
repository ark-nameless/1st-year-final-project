#pragma once
#define CORE_H_

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include <string>
#include <iostream>


namespace STAR
{
	namespace CORE
	{
		static std::string BASEPATH = SDL_GetBasePath();
		const std::string ASSETBASEPATH = BASEPATH + "Assets\\";

		bool InitSDL();
		void UintSDL();


		// Graphics With Error/Warning Prompt 
		SDL_Surface *LoadSurface(const char *title);
		SDL_Texture *LoadTexture(SDL_Renderer *renderer, const char *name);
	}
}


