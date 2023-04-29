#include <iostream>
#include <ctime>
#include "game_of_life.h"
using namespace std;

game_of_life::game_of_life()
{
	for (int i = 0; i < REDAKA; i++) 
	{
		for (int j = 0; j < STUPACA; j++) 
		{
			_generacija[i][j] = slucajna_vrijednost();
		}
	}
}

bool game_of_life::slucajna_vrijednost()
{
	return rand() % 2;
}

void game_of_life::kopiraj()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}
}

void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i < REDAKA; i++) 
	{
		for (int j = 0; j < STUPACA; j++) 
		{
			int n = 0;

			if (j < 39) n += _generacija[i][j + 1];
			if (j > 0) n += _generacija[i][j - 1];

			if (i < 19) n += _generacija[i + 1][j];
			if (i > 0) n += _generacija[i - 1][j];

			if (j < 39 && i < 19) n += _generacija[i + 1][j + 1];
			if (j > 0 && i < 19) n += _generacija[i + 1][j - 1];

			if (i > 0 && j < 39) n += _generacija[i - 1][j + 1];
			if (i > 0 && j > 0) n += _generacija[i - 1][j - 1];

			if (_generacija[i][j] == 1) 
			{
				if (n == 2 || n == 3) 
				{
					_sljedeca_generacija[i][j] = 1;
				}
				else 
				{
					_sljedeca_generacija[i][j] = 0;
				}

				if (n < 2 || n > 3) 
				{
					_sljedeca_generacija[i][j] = 0;
				}
				else 
				{
					_sljedeca_generacija[i][j] = 1;
				}
			}

			if (_generacija[i][j] == 0) 
			{
				if (n == 3) 
				{
					_sljedeca_generacija[i][j] = 1;
				}
				else 
				{
					_sljedeca_generacija[i][j] = 0;
				}
			}
		}
	}
	kopiraj();
}

void game_of_life::iscrtaj()
{
	for (int i = 0; i < REDAKA; i++) 
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (_generacija[i][j] == 0) cout << "-";
			if (_generacija[i][j] == 1) cout << "*";
		}
		cout << endl;
	}
}