#ifndef _2048_H_
#define _2048_H_


namespace STAR
{
	namespace _2048
	{
		void moveLeft(int p_arr[], int p_pos);
		int nonZero(int p_row[], int p_pos);
		int Zero(int p_arr[]);
		int LeftGuide(int p_arr[], int *score);
		void Guide(int p_arr[][4], int *score);
		void dispField(int p_field[4][4]);
		void Rotate(int p_arr[][4]);
		bool populateField(int p_field[][4], int p_num);

		bool GameOver(int p_field[][4]);


	}
}



#endif