#include "Textbox.h"
#include "..\Manager\FontManager.h"
#include "..\Manager\TextureManager.h"


namespace STAR
{
	namespace OBJECT
	{
		Textbox::Textbox(std::string texture, int x, int y, int w, int h)
		{
			m_DRect = { x, y, w, h };
			m_Texture = CORE::Texture(texture);
			m_Active = false;
		}

		void Textbox::Render(std::string fname, SDL_Color *color)
		{
			m_Texture.RenderClip(m_DRect.x, m_DRect.y, m_DRect.w, m_DRect.h, 1);
		}


	}

	
}


