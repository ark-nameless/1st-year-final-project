#ifndef TEXTURE_H_
#define TEXTURE_H_


#include "Core.h"
#include "..\Manager\TextureManager.h"

namespace STAR
{
	namespace CORE
	{
		class Texture
		{
		private :
			SDL_Texture *m_Texture;
			Uint8 m_Column;
			Uint8 m_Rows;
			Uint8 m_Frame;
			int m_Width;
			int m_Height;

		public :
			Texture();
			Texture(std::string name);
			~Texture();

			virtual void Render(int x = 0, int y = 0, int w = 0, int h = 0);
			virtual void RenderClip(int x, int y, int w, int h, int frame = 0);

			// Setters and Getters
			void Row(Uint8 p_row){m_Rows = p_row;}
			Uint8 Row(){ return m_Rows; }
			void Width(Uint8 p_width) { m_Width = p_width; }
			Uint8 Width() { return m_Column; }
		};

	}
}



#endif