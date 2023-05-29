#ifndef INPUTMANAGER_H_
#define INPUT_MANAGER_H_

#include <SDL.h>

namespace STAR
{
	namespace MANAGER
	{
		class InputManager
		{
		public :
			enum MOUSE_BUTTON {LEFT, RIGHT, MIDDLE, BACK, FORWARD};

		private :
			static InputManager *s_Instance;

			Uint8 *m_PrevKeyboardState;
			const Uint8 *m_KeyboardState;
			int m_KeyLength;

			Uint32 m_PrevMouseState;
			Uint32 m_MouseState;

			int m_MouseXPos;
			int m_MouseYPos;

		public :
			static InputManager *GetInstance();
			static void Release();

			bool KeyDown(SDL_Scancode scanCode);
			bool KeyPressed(SDL_Scancode scanCode);
			bool KeyReleased(SDL_Scancode scanCode);

			bool MouseButtonDown(MOUSE_BUTTON button);
			bool MouseButtonPressed(MOUSE_BUTTON button);
			bool MouseButtonReleased(MOUSE_BUTTON button);

			SDL_Point MousePos();

			void Update();
			void UpdatePrevInput();

		private : 
			InputManager();
			~InputManager();

		};

	}
}


#endif