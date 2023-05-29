#include "Window.h"


namespace STAR
{
	namespace CORE
	{
		int Window::s_WindowNum = 0;
		SDL_Event Window::s_Event;


		Window::Window()
		{
			m_Window = nullptr;
			m_Renderer = nullptr;
			m_BackBuffer = nullptr;
		}

		Window::Window(std::string title, int w, int h, Uint8 flag)
		{
			InitSDL();
			if (w < 0){
				printf("Warning! Invalid Window Width! Window Width Set to Default %ud!\n", DEF_WINDOW_WIDTH);
				w = DEF_WINDOW_WIDTH;
			}
			if (h < 0){
				printf("Warning! Invalid Window Height! Window Height Set to Default %ud!\n", DEF_WINDOW_HEIGHT);
				h = DEF_WINDOW_HEIGHT;
			}

			m_Window = SDL_CreateWindow("WindowClass", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
				w, h, flag);

			if (m_Window == NULL){
				printf("Warning! Unable to Create Window! SDL_Error: %s!\n", SDL_GetError());
				m_Window = NULL;
				m_Renderer = NULL;
			}
			// No Problems
			else {
				++s_WindowNum;
				m_Renderer = SDL_CreateRenderer(m_Window, -1,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
				if (m_Renderer == NULL){
					printf("Warning! Unable to Create Renderer! SDL_Error: %s!\n", SDL_GetError());
					m_Renderer = NULL;
				}
			}
			SDL_SetWindowTitle(m_Window, title.c_str());
			m_BackBuffer = NULL;
			hasIcon = 0;
			isRunning = true;
		}

		Window::~Window()
		{
			if (m_Window != NULL)
				SDL_DestroyWindow(m_Window);
			if (m_Renderer != NULL)
				SDL_DestroyRenderer(m_Renderer);
			if (m_BackBuffer != NULL)
				SDL_FreeSurface(m_BackBuffer);

			m_Window = NULL;
			m_Renderer = NULL;
			m_BackBuffer = NULL;
			s_WindowNum--;
			UintSDL();
		}

		// Public Window Class Operations
		void Window::SetName(const char *title) const
		{
			SDL_SetWindowTitle(m_Window, title);
		}
		void Window::SetIcon(const char *icon)
		{
			if (hasIcon == 0){
				SDL_Surface *newSurface = LoadSurface(icon);
				if (newSurface != NULL){
					hasIcon = 1;
					SDL_SetWindowIcon(m_Window, newSurface);
					SDL_FreeSurface(newSurface);
				}
				newSurface = nullptr;
			}
		}
		void Window::Update() const
		{
			SDL_RenderPresent(m_Renderer);
		}
		void Window::Clear()const
		{
			SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 0xFF);
			SDL_RenderClear(m_Renderer);
		}

		void Window::Events()
		{
			if (s_Event.type == SDL_QUIT ||  // Check Quit Event 
				(s_Event.type == SDL_WINDOWEVENT && s_Event.window.event == SDL_WINDOWEVENT_CLOSE) ||
				(s_Event.type == SDL_KEYDOWN && s_Event.key.keysym.sym == SDLK_ESCAPE)){
				isRunning = false;

			}
		}


		// Public Window Class Operations



	}
}