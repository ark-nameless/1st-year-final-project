#include "Font.h"



namespace STAR
{
	namespace OBJECT
	{
		Fonts::Fonts()
		{
			m_Font.begin();
		}
		Fonts::~Fonts()
		{
			for (auto ch : m_Font){
				if (ch.second != NULL){
					SDL_DestroyTexture(ch.second);
				}
			}
			m_Font.clear();
		}

		SDL_Texture *Fonts::GetChar(std::string fname, int ch)
		{
			if (m_Font[ch] == nullptr){
				m_Font[ch] = CORE::Graphics::GetInstance()->GetChar(fname, ch);
			}
			return m_Font[ch];
		}
	}
}