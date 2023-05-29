#include "FontManager.h"


#include <math.h>

namespace STAR
{
	namespace MANAGER
	{
		FontManager *FontManager::s_Instance = NULL;

		int GetNewLine(std::string text){
			int newline = 0;
			for (newline = 0; newline < text.length(); newline++){
				if (text[newline] == '\n')
					newline++;
			}
			return newline;
		}

		FontManager *FontManager::GetInstance()
		{
			if (s_Instance == NULL){
				s_Instance = new FontManager();
			}
			return s_Instance;
		}
		void FontManager::Release()
		{
			delete s_Instance;
			s_Instance = NULL;
		}
		FontManager::FontManager()
		{
			char log[512];
			if (TTF_Init() == -1){
				sprintf(log, "Warning! Unable to Properly Initialize SDL_ttf! TTF_Error: %s!\n", TTF_GetError());
				LOGMESSAGE(log);
				exit(EXIT_FAILURE);
			}
		}
		FontManager::~FontManager()
		{
			for (auto text : m_FontMap){
				if (text.second != NULL){
					delete text.second;
				}
			}
			m_FontMap.clear();
			TTF_Quit();
		}

		SDL_Texture *FontManager::RenderChar(std::string font, int ch)
		{
			if (m_FontMap[font] == nullptr){
				m_FontMap[font] = new OBJECT::Fonts();
			}
			return m_FontMap[font]->GetChar(font, ch);
		}

		void FontManager::RenderString(std::string fontname, std::string text)
		{
			//GEOMETRY::Size size;
			int w, h;
			SDL_QueryTexture(RenderChar(fontname, text[0]), NULL, NULL, &w, &h);
			SDL_Texture *textch = NULL;
			//std::cout << size;
			SDL_Rect dRect = { 0, 0, w, h };
			for (int i = 0; i < text.length(); i++){
				dRect.x += w;
				if (text.at(i) == '\n'){
					dRect.y += h;
					dRect.x = 0;
				}
				else {
					textch = RenderChar(fontname, text.at(i));
					SDL_RenderCopy(CORE::Graphics::GetRenderer(), textch, NULL, &dRect);
				}
			}
		}

		void FontManager::RenderStringFit(std::string fname, std::string text, GEOMETRY::Vector2 pos, 
			GEOMETRY::Size size, SDL_Color *color)
		{
			SDL_Texture *textch = RenderChar(fname, text[0]);
			if (size.w != 0){
				size.w = size.w / text.length();
			}
			SDL_Rect dRect = { pos.x, pos.y, size.w, size.h };

			// Make Paddings
			dRect.x += (dRect.w * .4);
			dRect.w -= (dRect.w * .1);
			dRect.y += (dRect.w * .2);
			dRect.h -= (dRect.w * .1);

			for (int i = 0; i < text.length(); i++){
				if (text.at(i) == '\n'){
					dRect.y += dRect.h;
					dRect.x = 0;
				}
				
				else {
					textch = RenderChar(fname, text.at(i));
					if (color != NULL){
						SDL_SetTextureColorMod(textch, color->r, color->g, color->b);
					}
					SDL_RenderCopy(CORE::Graphics::GetRenderer(), textch, NULL, &dRect);
					dRect.x += dRect.w;
				}
			}
		}




	}
}
