#ifndef WINDOW_H_
#define _WINDOW_H_

#include <SDL.h>
#include <iostream>

#include "Core.h"


namespace STAR
{
	namespace CORE
	{
		const unsigned int DEF_WINDOW_WIDTH = 200;
		const unsigned int DEF_WINDOW_HEIGHT = 300;


		class Window
		{
		public :
			static SDL_Event s_Event;

		private:
			SDL_Window *m_Window;
			SDL_Renderer *m_Renderer;
			SDL_Surface *m_BackBuffer;

			static int s_WindowNum;

			// State Members
			bool hasIcon : 1;
			bool isRunning : 1;

		public:
			/*
		@brief
		Default constructor for window class.
		All members are set to nullptr.
		*/
			Window();
			/*
		@brief
		\	Create a window class based in the parameters.
		@param
		\	w  = width of the window class.
		\	h  = height of the window class.
		\	flags = behavior of the window, Default to WINDOS_SHOWN.
		*/
			Window(std::string title, int w, int h, Uint8 flags = SDL_WINDOW_SHOWN);
			/*
		@brief
		\	Default destructor for Window class.
		*/
			~Window();

			void Window::SetName(const char *title) const;
			void Window::SetIcon(const char *icon);
			void Update() const;
			void Clear() const;

			bool Closed() const{ return isRunning; }

			static int GetWindowNum() { return s_WindowNum; }
			static SDL_Event &GetEvent(){ return s_Event; }
			void Events();
			SDL_Renderer *GetRenderer() const { return m_Renderer; }

		};


	}
}


#endif