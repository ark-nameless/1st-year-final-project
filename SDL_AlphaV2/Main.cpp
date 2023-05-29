#include <iostream>
#include <cstdlib>
#include <conio.h>

#include "src\Core\Window.h"
#include "src\Manager\TextureManager.h"
#include "src\Manager\AudioManager.h"
#include "src\Core\Texture.h"

#include "src\OBJECTS\Rect.h"
#include "src\OBJECTS\Button.h"
#include "src\OBJECTS\Textbox.h"

#include "src\2048\2048.h"

void RenderField(int x, int y, int field[][4]);


int main(int argc, char **argv)
{

	STAR::CORE::Window *win = new STAR::CORE::Window("2048 Sample", 620,480);
	STAR::MANAGER::TextureManager *TextureManager = STAR::MANAGER::TextureManager::GetInstance();
	STAR::MANAGER::TextureManager::Renderer(win->GetRenderer());
	STAR::MANAGER::InputManager *Inputs = STAR::MANAGER::InputManager::GetInstance();
	STAR::MANAGER::AudioManager *Sounds = STAR::MANAGER::AudioManager::GetInstance();

	SDL_Texture *BackGround = TextureManager->GetTexture("ACG.GY_07.jpg");
	Sounds->GetSFX("Button.wav");
	Sounds->GetSFX("Slide.wav");

	STAR::OBJECT::String sScore("", "NORAI___.TTF");
	STAR::OBJECT::Button btnMusic("sound5.png", "", 10, 50, 20, 32, 32);
	btnMusic.SetFont("NORAI___.TTF");


	char filename[255];
	std::string fileName;
	for (int i = 1; i < 13; i++){
		sprintf(filename, "Block%d.png", i);
		fileName = filename;
		TextureManager->GetTexture(fileName);
	}

	int field[][4] = { { 0, 0, 0, 2 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 } };


	bool running = false;
	int score = 0;
	int move = 0;
	bool changed = true;
	int frame = 1;
	while (win->Closed() && !running)
	{
		while (SDL_PollEvent(&win->GetEvent()) != 0){
			win->Events();

		}
		win->Clear();

		if (Inputs->KeyPressed(SDL_SCANCODE_A) || Inputs->KeyPressed(SDL_SCANCODE_LEFT)){
			STAR::_2048::Guide(field, &score);
			STAR::_2048::populateField(field, 1);
			Sounds->PlaySFX("Slide.wav");
			changed = true;
		}
		else if (Inputs->KeyPressed(SDL_SCANCODE_D) || Inputs->KeyPressed(SDL_SCANCODE_RIGHT)){
			STAR::_2048::Rotate(field);
			STAR::_2048::Rotate(field);
			STAR::_2048::Guide(field, &score);
			STAR::_2048::Rotate(field);
			STAR::_2048::Rotate(field);
			STAR::_2048::populateField(field, 1);
			changed = true;
			Sounds->PlaySFX("Slide.wav");
		}
		else if (Inputs->KeyPressed(SDL_SCANCODE_S) || Inputs->KeyPressed(SDL_SCANCODE_DOWN)){
			STAR::_2048::Rotate(field);
			STAR::_2048::Guide(field, &score);
			STAR::_2048::Rotate(field);
			STAR::_2048::Rotate(field);
			STAR::_2048::Rotate(field);
			STAR::_2048::populateField(field, 1);
			changed = true;
			Sounds->PlaySFX("Slide.wav");
		}
		else if (Inputs->KeyPressed(SDL_SCANCODE_W) || Inputs->KeyPressed(SDL_SCANCODE_UP)){
			STAR::_2048::Rotate(field);
			STAR::_2048::Rotate(field);
			STAR::_2048::Rotate(field);
			STAR::_2048::Guide(field, &score);
			STAR::_2048::Rotate(field);
			STAR::_2048::populateField(field, 1);
			changed = true;
			Sounds->PlaySFX("Slide.wav");
		}

		if (Inputs->MouseButtonPressed(STAR::MANAGER::InputManager::LEFT)){
			Sounds->PlaySFX("Button.wav");
		}



		// Render
		SDL_RenderCopy(TextureManager->Renderer(), BackGround, NULL, NULL);

		//RenderFields
		RenderField(180, 100, field);

		//btnMusic.Render();


		// Check Fields
		if (running){
			char message[255];
			sprintf(message, "Game Over!\nYour Score: %d\n", score);
			SDL_ShowSimpleMessageBox(NULL, "Information", message, NULL);
		}

		if (changed){
			changed = false;
			system("CLS");
			STAR::_2048::dispField(field);
			running = STAR::_2048::GameOver(field);
		}

		Inputs->UpdatePrevInput();
		Inputs->Update();

		win->Update();
		SDL_Delay(16);
	}

	std::cout << "GAME OVER!\n\n";
	std::cout << "SCORE: " << score << "\n";

	delete win;
	TextureManager->Release();
	Inputs->Release();
	Sounds->Release();

	std::cin.get();

	return (0);
}

void RenderField(int x, int y, int field[][4])
{
	SDL_Rect dRect = { 0, 0, 64, 64 };
	for (int row = 0; row < 4; row++){
		for (int col = 0; col < 4; col++){
			dRect.x = col * dRect.w + x;
			dRect.y = row * dRect.h + y;

			switch (field[row][col]){
			case 0:
				SDL_RenderCopy(STAR::MANAGER::TextureManager::Renderer(),
					STAR::MANAGER::TextureManager::GetInstance()->GetTexture("Block7.png"), NULL, &dRect);
				break;
			case 2:
				SDL_RenderCopy(STAR::MANAGER::TextureManager::Renderer(), 
					STAR::MANAGER::TextureManager::GetInstance()->GetTexture("Block1.png"), NULL, &dRect);
				break;
			case 4:
				SDL_RenderCopy(STAR::MANAGER::TextureManager::Renderer(),
					STAR::MANAGER::TextureManager::GetInstance()->GetTexture("Block2.png"), NULL, &dRect);
				break;
			case 8:
				SDL_RenderCopy(STAR::MANAGER::TextureManager::Renderer(),
					STAR::MANAGER::TextureManager::GetInstance()->GetTexture("Block3.png"), NULL, &dRect);
				break;
			case 16:
				SDL_RenderCopy(STAR::MANAGER::TextureManager::Renderer(),
					STAR::MANAGER::TextureManager::GetInstance()->GetTexture("Block4.png"), NULL, &dRect);
				break;
			case 32:
				SDL_RenderCopy(STAR::MANAGER::TextureManager::Renderer(),
					STAR::MANAGER::TextureManager::GetInstance()->GetTexture("Block5.png"), NULL, &dRect);
				break;
			case 64:
				SDL_RenderCopy(STAR::MANAGER::TextureManager::Renderer(),
					STAR::MANAGER::TextureManager::GetInstance()->GetTexture("Block6.png"), NULL, &dRect);
				break;
			case 128:
				SDL_RenderCopy(STAR::MANAGER::TextureManager::Renderer(),
					STAR::MANAGER::TextureManager::GetInstance()->GetTexture("Block8.png"), NULL, &dRect);
				break;
			case 256:
				SDL_RenderCopy(STAR::MANAGER::TextureManager::Renderer(),
					STAR::MANAGER::TextureManager::GetInstance()->GetTexture("Block9.png"), NULL, &dRect);
				break;
			case 512:
				SDL_RenderCopy(STAR::MANAGER::TextureManager::Renderer(),
					STAR::MANAGER::TextureManager::GetInstance()->GetTexture("Block10.png"), NULL, &dRect);
				break;
			case 1024:
				SDL_RenderCopy(STAR::MANAGER::TextureManager::Renderer(),
					STAR::MANAGER::TextureManager::GetInstance()->GetTexture("Block11.png"), NULL, &dRect);
				break;
			case 2048:
				SDL_RenderCopy(STAR::MANAGER::TextureManager::Renderer(),
					STAR::MANAGER::TextureManager::GetInstance()->GetTexture("Block12.png"), NULL, &dRect);
				break;
			}
			if (field[row][col] > 1024){
				SDL_RenderCopy(STAR::MANAGER::TextureManager::Renderer(),
					STAR::MANAGER::TextureManager::GetInstance()->GetTexture("Block12.png"), NULL, &dRect);
			}
		}
	}
}