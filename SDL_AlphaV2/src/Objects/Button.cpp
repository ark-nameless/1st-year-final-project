#include "Button.h"
#include <iostream>
#include <cmath>

namespace  STAR
{
	namespace OBJECT
	{
		Button::Button(std::string texture, std::string text, int id, int x, int y, int w, int h)
			: Rect(x, y, w, h), CORE::Texture(texture), m_dRect(x, y, w, h), m_Text(text)
		{
			m_ID = id;
		}
		Button::~Button()
		{
			
		}

		int Button::Click()
		{
			typedef MANAGER::InputManager Inputs;
			if (Point() && Inputs::GetInstance()->MouseButtonPressed(Inputs::LEFT)){
				return m_ID;
			}
			return 0;
		}

		bool Button::Point()
		{
			typedef MANAGER::InputManager Inputs;
			if (this->Rect::Point()){
				return true;
			}
			return false;
		}

		void Button::Render()
		{
			SDL_Color WHITE = { 0xFF, 0xFF, 0xFF, 0xFF };
			Texture::Render(x ,y);
			m_Text.Render(x, y, &WHITE, w, h);
		}
		void Button::RenderClip(int x, int y, int frame)
		{
			SDL_Color WHITE = { 0xFF, 0xFF, 0xFF, 0xFF };
			Texture::RenderClip(x, y, this->w/2, h, frame);
			m_Text.Render(x, y, &WHITE, w/2, h);
		}

		void Button::SetFont(std::string fname)
		{
			m_Text.SetFont(fname);
		}

	}
}