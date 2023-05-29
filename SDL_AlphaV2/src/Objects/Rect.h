#ifndef RECT_H_
#define RECT_H_

#include <SDL.h>

namespace STAR
{
	namespace OBJECT
	{
		struct Rect
		{
			int x, y;
			int w, h;

			Rect(int _x, int _y, int _w, int _h);
			~Rect();

			virtual bool Point();
			SDL_Rect toSDL();

		};
	}
}



#endif