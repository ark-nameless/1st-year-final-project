#include "2048.h"
#include <iostream>


namespace STAR
{
	namespace _2048
	{
		static int Index(int px, int py)
		{
			return 12 + py - (px * 4);
		}
		void moveLeft(int p_arr[], int p_pos)
		{
			int temp;
			for (int i = p_pos, j = i + 1; j < 4; i++, j++){
				temp = p_arr[i];
				p_arr[i] = p_arr[j];
				p_arr[j] = temp;
			}

		}
		int nonZero(int p_row[], int p_pos)
		{
			int i = 0;
			for (i = p_pos; i < 4; i++){
				if (p_row[i] != 0){
					break;
				}
			}
			return i;
		}
		int Zero(int p_arr[])
		{
			int i;
			for (i = 0; i < 4; i++){
				if (p_arr[i] == 0)
					break;
			}
			return i;
		}

		int LeftGuide(int p_arr[], int *score)
		{
			int guide = 0;
			do
			{
				for (int i = 0, j = i + 1; j < 4; i++, j++)
				{
					if (p_arr[i] == 0){
						moveLeft(p_arr, i);
					}
				}
				for (int i = 0, j = i + 1; j < 4; i++, j++)
				{
					if (p_arr[i] == p_arr[j]){
						p_arr[i] += p_arr[j];
						p_arr[j] = 0;
						guide = 1;
						*score += p_arr[i];
					}
				}
			} while (nonZero(p_arr, Zero(p_arr)) < 3);
			for (int i = 0, j = i + 1; j < 4; i++, j++)
			{
				if (p_arr[i] == p_arr[j]){
					p_arr[i] += p_arr[j];
					p_arr[j] = 0;
					guide = 1;
					*score += p_arr[i];
				}
			}
			return guide;
		}
		void Guide(int p_arr[][4], int *score)
		{
			for (int i = 0; i < 4; i++){
				LeftGuide(p_arr[i], score);
			}
		}
		void dispField(int p_field[4][4])
		{
			for (int i = 0; i < 4; i++){
				std::cout << "|";
				for (int j = 0; j < 4; j++){
					printf("%-4d|", p_field[i][j]);
				}
				std::cout << "\n";
			}
		}
		void Rotate(int p_arr[][4])
		{
			int arr[16];
			int index = 0;
			for (int py = 0; py < 4; py++){
				for (int px = 0; px < 4; px++){
					arr[index] = p_arr[py][px];
					index++;
				}
			}

			for (int py = 0; py < 4; py++){
				for (int px = 0; px < 4; px++){
					p_arr[py][px] = arr[Index(px, py)];
				}
			}
		}

		bool populateField(int p_field[][4], int p_num)
		{
			int power = rand() % 3;
			switch (power){
			case 1:
				power *= 2;
				break;
			case 2:
				power *= 2;
				break;
			case 3:
				power = 8;
				break;
			}
			int x = rand() % 4;
			int y = rand() % 4;
			bool enough = true;
			int j = 0;
			for (int i = 0; i < p_num; j++){
				x = rand() % 4;
				y = rand() * x % 4;
				if (p_field[y][x] == 0){
					p_field[y][x] = power;
					i++;
				}
				if (j > 100){
					enough = false;
					break;
				}
			}
			if (!enough)
			{
				int feed = 0;
				for (int i = 0; i < p_num; i++){
					for (int j = 0; j < 3; j++){
						if (p_field[i][j] == 0){
							p_field[i][j] = power;
							feed++;
						}
						if (feed >= p_num){
							break;
						}
					}
				}
				if (feed == 0)
					return false;
			}
			return true;
		}

		bool GameOver(int p_field[][4])
		{
			bool over = true;
			int arr[4][4];
			for (int i = 0; i < 4; i++){
				for (int j = 0; j < 4; j++){
					arr[i][j] = p_field[i][j];
					if (p_field[i][j] == 0)
						over = false;
				}
			}
			for (int tried = 0; tried < 4; tried++){
				Rotate(arr);
				for (int i = 0; i < 4; i++){
					for (int j = 0; j < 3; j++){
						if (arr[i][j] == arr[i][j + 1])
							over = false;
					}
				}
			}
			return over;
		}
	}
}