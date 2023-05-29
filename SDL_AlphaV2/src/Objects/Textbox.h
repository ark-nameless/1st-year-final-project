#ifndef TEXTBOX_H_
#define TEXTBOX_H_

#include <string>

#include "..\Core\Texture.h"


namespace STAR
{
	namespace OBJECT
	{

		class Textbox
		{
		private:
			CORE::Texture m_Texture;
			SDL_Rect m_DRect;
			bool m_Active;

		public :
			Textbox(){}
			Textbox(std::string texture,int x, int y, int w, int h);
			~Textbox(){}

			void Active();
			void Render(std::string fname, SDL_Color *color);

		};

	}
}



#endif