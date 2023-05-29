#ifndef STRING_H_
#define STRING_H_


#include <string>
#include "..\Manager\FontManager.h"

namespace STAR
{
	namespace OBJECT
	{
		class String : public std::string
		{
		private:
			std::string m_Font;
		public:
			String(std::string str, std::string fname = "") : std::string(str), m_Font(fname){}
			void SetFont(std::string font);
			virtual ~String(){}

			void Render();
			void Render(int x, int y, SDL_Color *color = NULL, int w = 0, int h = 0);

			String &operator=(std::string text){
				*this = text;
			}
		};
	}
}



#endif