#ifndef SCROLLBAR_H_
#define SCROLLBAR_H_

#include "Button.h"

namespace STAR
{
	namespace OBJECT
	{
		class ScrollBar
		{
		public :
			enum {HORIZONTAL,VERTICAL};
		private :
			int x, y;
			int w, h;
			int m_Orient;
			Button *m_Button;

		public  :
			ScrollBar();
			ScrollBar(int x, int y, int w, int h, int orient);
		
			virtual void Render();
			virtual void Event();
		};
	}
}


#endif