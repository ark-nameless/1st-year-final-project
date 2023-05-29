#include "Texture.h"
#include "..\Manager\TextureManager.h"
#include <iostream>

namespace STAR
{
	namespace CORE
	{
		Texture::Texture()
		{
			m_Texture = NULL;
			m_Width = m_Rows = m_Width = m_Height = m_Frame = 0;
		}
		Texture::Texture(std::string name)
		{
			MANAGER::TextureManager::GetInstance()->Renderer();
			m_Texture = MANAGER::TextureManager::GetInstance()->GetTexture(name);
			m_Width = m_Rows = m_Width = m_Height = m_Frame = 0;

			SDL_QueryTexture(m_Texture, NULL, NULL, &m_Width, NULL);
			SDL_QueryTexture(m_Texture, NULL, NULL, NULL, &m_Height);
		}
		Texture::~Texture()
		{
			m_Texture = NULL;
		}

		void Texture::Render(int x, int y, int w, int h)
		{
			if (x < 0 || y < 0 || w < 0 || h < 0){
				SDL_RenderCopy(MANAGER::TextureManager::Renderer(), m_Texture, NULL, NULL);
			}
			else {
				SDL_Rect l_rect = { x, y, w = (w == 0) ? m_Width : w, h = (h == 0) ? m_Height : h };
				SDL_RenderCopy(MANAGER::TextureManager::Renderer(), m_Texture, NULL, &l_rect);
			}
		}

		void Texture::RenderClip(int x, int y, int w, int h, int frame)
		{
			SDL_Rect l_srcRect;
			l_srcRect = { w * frame, h * m_Rows, w, h };
			SDL_Rect l_desRect;
			l_desRect = { x, y, w, h };

			SDL_RenderCopyEx(MANAGER::TextureManager::Renderer(), m_Texture, &l_srcRect, &l_desRect, 0.0, NULL, SDL_FLIP_NONE);
		}


	}
	
}