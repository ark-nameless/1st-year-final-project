#ifndef BUTTON_H_
#define BUTTON_H_

#include <string>

#include "Rect.h"
#include "..\Core\Texture.h"
#include "..\Manager\InputManager.h"
#include "String.h"

namespace STAR
{
	namespace OBJECT
	{

		class Button : public CORE::Texture , public Rect
		{
		protected :
			int m_ID;
			Rect m_dRect;
			String m_Text;

		public :
			Button() : Rect(0, 0, 0, 0), CORE::Texture("NoName"), m_dRect(0,0,0,0), m_Text("NoName"){m_ID = 0;m_Text = "NoName";}
			Button(std::string texture, std::string text, int id, int x, int y, int w, int h);
			~Button();

			int Click();
			bool Point() override;

			// None Implemented
			void SetFont(std::string font);
			void Render();
			void RenderClip(int x, int y, int frame);
			//bool Hover();

		};

	}
}




#endif