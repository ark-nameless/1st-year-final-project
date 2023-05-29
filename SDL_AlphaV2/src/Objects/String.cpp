#include "String.h"


namespace STAR
{
	namespace OBJECT
	{
		void String::SetFont(std::string font)
		{
			m_Font = font;
		}
		void String::Render()
		{

		}

		void String::Render(int x, int y, SDL_Color *color, int w, int h)
		{
			//MANAGER::FontManager::GetInstance()->Render(m_Font, *this, x, y, color, w, h);
		}
	}
	
}

