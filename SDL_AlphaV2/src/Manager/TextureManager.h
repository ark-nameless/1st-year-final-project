#ifndef TEXTUREMANAGER_H_
#define TEXTUREMANAGER_H_

#include <SDL.h>
#include <map>

#include "..\Core\Core.h"


namespace STAR
{
	namespace MANAGER 
	{
		class TextureManager
		{
		private:
			std::map<std::string, SDL_Texture*> m_TextureMap;
			static TextureManager *s_Instance;
			static SDL_Renderer *s_Renderer;

		public:
			static TextureManager*GetInstance();
			static void Release();
			static void Renderer(SDL_Renderer *renderer) { s_Renderer = renderer; }
			static SDL_Renderer* Renderer(){ return s_Renderer; }


			SDL_Texture* GetTexture(std::string name);
			void Remove(std::string name);

		private:
			TextureManager();
			~TextureManager();
		};
	}
}




#endif