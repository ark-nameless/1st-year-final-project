#pragma once

//#include "..\Core\Graphics.h"
#include <map>
#include <SDL.h>

namespace STAR
{
	namespace OBJECT
	{
		class Fonts
		{
		private:
			std::map<int, SDL_Texture*> m_Font;

		public :
			Fonts();
			~Fonts();

			SDL_Texture *GetChar(std::string fname, int ch);
		};
	}
}

