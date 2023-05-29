#include <iostream>

#include "TextureManager.h"


namespace STAR
{
	namespace MANAGER
	{
		TextureManager *TextureManager::s_Instance = nullptr;
		SDL_Renderer *TextureManager::s_Renderer = nullptr;

		TextureManager* TextureManager::GetInstance()
		{
			if (s_Instance == nullptr){
				s_Instance = new TextureManager;
			}
			return s_Instance;
		}

		TextureManager::TextureManager()
		{

		}

		TextureManager::~TextureManager()
		{
			for (auto tex : m_TextureMap){
				if (tex.second != NULL){
					SDL_DestroyTexture(tex.second);
				}
			}
			m_TextureMap.clear();
		}

		void TextureManager::Release()
		{
			delete s_Instance;
			s_Instance = nullptr;
		}

		SDL_Texture* TextureManager::GetTexture(std::string name)
		{
			if (m_TextureMap[name] == nullptr)
				m_TextureMap[name] = CORE::LoadTexture(s_Renderer, name.c_str());

			return (m_TextureMap[name]);
		}
		void TextureManager::Remove(std::string name)
		{
			if (m_TextureMap[name] != nullptr){
				SDL_DestroyTexture(m_TextureMap[name]);
				m_TextureMap[name] = NULL;
				m_TextureMap.erase(name);
			}

		}
	}
}