#include "Rect.h"

#include "..\Manager\InputManager.h"

namespace STAR
{
	namespace OBJECT
	{
		Rect::Rect(int x, int y, int w, int h)
		{
			this->x = x;
			this->y = y;
			this->w = w;
			this->h = h;
		}
		Rect::~Rect()
		{

		}

		bool Rect::Point()
		{
			SDL_Rect l_rect = this->toSDL();
			SDL_Point l_mouse = STAR::MANAGER::InputManager::GetInstance()->MousePos();

			return SDL_PointInRect(&l_mouse, &l_rect);
		}

		SDL_Rect Rect::toSDL()
		{
			SDL_Rect l_rect = { x, y, w, h };
			return l_rect;
		}

	}
}