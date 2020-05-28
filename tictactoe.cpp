#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Game.h"

void fill(int** game, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			game[i][j] = -1;
		}
	}
}

int main()
{
	system("cls");
	bool game_over = false, start = false, AI = true, end = false, windowed = true;
	int size = 3, win_size = size, dif = 0;
	int dif_t[] = { 0,50,100 };
	do
	{
		menu(&size, &AI, &game_over, &end, &win_size, &windowed, &dif);
		if (!game_over)
		{
			int** game = new int* [size];
			for (int i = 0; i < size; i++)
			{
				game[i] = new int[size];
			}

			fill(game, size);
			switch (AI)
			{
			case true:
				switch (windowed)
				{
				case true:
					game_AI_G(game_over, game, size, win_size, dif_t[dif]);
					break;
				case false:
					game_AI(game_over, game, size, win_size, dif_t[dif]);
					break;
				}
				break;
			case false:
				switch (windowed)
				{
				case true:
					game_player_G(game_over, game, size, win_size);
					break;
				case false:
					game_player(game_over, game, size, win_size);
					break;
				}
				break;
			}
		}
	} while (!end);
	return 0;
}
