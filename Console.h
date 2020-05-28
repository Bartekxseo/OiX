#pragma once

void draw(int** game, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			switch (game[i][j])
			{
			case 1:
				std::cout << "O ";
				break;
			case 0:
				std::cout << "X ";
				break;
			case -1:
				std::cout << "# ";
				break;
			}
		}
		std::cout << std::endl;
	}
}

void player_turn(int size, int** game, int turn)
{
	int k = 1, choice, player = turn % 2;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cout << k << " ";
			k++;
		}
		std::cout << std::endl;
	}
	std::cout << "wybierz pole: ";
	int x = 0, y = 0;
	do
	{
		std::cin >> choice;
		int z = 1;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (choice == z)
				{
					x = i;
					y = j;
				}
				z++;
			}
		}
	} while ((choice > k && choice <= 0) || game[x][y] != -1);
	game[x][y] = player;
}