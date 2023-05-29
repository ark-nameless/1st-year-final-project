#include "InputManager.h"
#include <string.h>



namespace STAR
{
	namespace MANAGER
	{
		InputManager *InputManager::s_Instance = NULL;

		// CONSTRUCTORS AND DESTRUCTORS
		InputManager *InputManager::GetInstance()
		{
			if (s_Instance == NULL)
				s_Instance = new InputManager;
			return s_Instance;
		}
		void InputManager::Release()
		{
			delete s_Instance;
			s_Instance = NULL;
		}
		InputManager::InputManager()
		{
			m_KeyboardState = SDL_GetKeyboardState(&m_KeyLength);
			m_PrevKeyboardState = new Uint8[m_KeyLength];

			memcpy(m_PrevKeyboardState, m_KeyboardState, m_KeyLength);
		}
		InputManager::~InputManager()
		{
			delete[] m_PrevKeyboardState;
			m_PrevKeyboardState = NULL;
		}

		// KEYBOARDS
		bool InputManager::KeyDown(SDL_Scancode scanCode)
		{
			return m_KeyboardState[scanCode];
		}
		bool InputManager::KeyPressed(SDL_Scancode scanCode)
		{
			return !m_PrevKeyboardState[scanCode] && m_KeyboardState[scanCode];
		}
		bool InputManager::KeyReleased(SDL_Scancode scanCode)
		{
			return m_PrevKeyboardState[scanCode] && !m_KeyboardState[scanCode];
		}

		// MOUSE
		SDL_Point InputManager::MousePos()
		{
			SDL_Point mousePos = { m_MouseXPos, m_MouseYPos };
			return mousePos;
		}
		bool InputManager::MouseButtonDown(MOUSE_BUTTON button)
		{
			Uint32 mask = 0;
			switch (button){
			case LEFT:
				mask = SDL_BUTTON_LMASK;
				break;
			case RIGHT:
				mask = SDL_BUTTON_RMASK;
				break;
			case MIDDLE:
				mask = SDL_BUTTON_MMASK;
				break;
			case BACK:
				mask = SDL_BUTTON_X1MASK;
				break;
			case FORWARD:
				mask = SDL_BUTTON_X2MASK;
				break;
			}
			return (m_MouseState & mask);
		}
		bool InputManager::MouseButtonPressed(MOUSE_BUTTON button)
		{
			Uint32 mask = 0;
			switch (button){
			case LEFT:
				mask = SDL_BUTTON_LMASK;
				break;
			case RIGHT:
				mask = SDL_BUTTON_RMASK;
				break;
			case MIDDLE:
				mask = SDL_BUTTON_MMASK;
				break;
			case BACK:
				mask = SDL_BUTTON_X1MASK;
				break;
			case FORWARD:
				mask = SDL_BUTTON_X2MASK;
				break;
			}
			return !(m_PrevMouseState & mask) && (m_MouseState & mask);
		}
		bool InputManager::MouseButtonReleased(MOUSE_BUTTON button)
		{
			Uint32 mask;
			switch (button){
			case LEFT:
				mask = SDL_BUTTON_LMASK;
				break;
			case RIGHT:
				mask = SDL_BUTTON_RMASK;
				break;
			case MIDDLE:
				mask = SDL_BUTTON_MMASK;
				break;
			case BACK:
				mask = SDL_BUTTON_X1MASK;
				break;
			case FORWARD:
				mask = SDL_BUTTON_X2MASK;
				break;
			}
			return (m_PrevMouseState & mask) && !(m_MouseState & mask);
		}

		void InputManager::Update()
		{
			m_MouseState = SDL_GetMouseState(&m_MouseXPos, &m_MouseYPos);
		}

		void InputManager::UpdatePrevInput()
		{
			memcpy(m_PrevKeyboardState, m_KeyboardState, m_KeyLength);

			m_PrevMouseState = m_MouseState;
		}


	}
}


