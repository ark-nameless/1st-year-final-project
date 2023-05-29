#pragma once

#include "..\Geometry\Size.h"
#include "..\Geometry\Vec2.h"
#include "Font.h"
#include "..\Core\Core.h"

#include <SDL_ttf.h>


namespace STAR
{
	namespace MANAGER
	{
		
		class FontManager
		{
		private :
			std::map<std::string, OBJECT::Fonts*> m_FontMap;
			static FontManager *s_Instance;

		public :
			static FontManager *GetInstance();
			static void Release();

			SDL_Texture *RenderChar(std::string font, int ch);
			void RenderString(std::string fname, std::string text);
			void RenderStringFit(std::string fname, std::string text, GEOMETRY::Vector2 pos, GEOMETRY::Size h, SDL_Color *color = NULL);

		private :
			FontManager();
			~FontManager();
		};
	}
}