#pragma once
#include "AI.h"
#include "Window.h"
#include "Console.h"

void Logic(int turn, bool* game_over, int** game, int size, bool* win, int win_size)
{
	const int player = turn % 2;
	int counter = 0;
	bool tie = false;
	counter = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (game[i][j] == player)
			{
				counter++;
			}
			else
			{
				if (counter != win_size)
					counter = 0;
			}
		}
		if (counter == win_size)
		{
			*game_over = true;
			*win = true;
			break;
		}
		counter = 0;
	}
	counter = 0;
	if (!*game_over)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (game[j][i] == player)
				{
					counter++;
				}
				else
				{
					if (counter != win_size)
						counter = 0;
				}
			}
			if (counter == win_size)
			{
				*game_over = true;
				*win = true;
				break;
			}
			counter = 0;
		}
	}
	counter = 0;
	if (!*game_over)
	{
		for (int i = 0; i < size; i++)
		{
			if (game[i][i] == player)
			{
				counter++;
			}
			else
			{
				if (counter != win_size)
					counter = 0;
			}
		}
		if (counter == win_size)
		{
			*game_over = true;
			*win = true;
		}
	}
	counter = 0;
	if (!*game_over)
	{
		for (int i = 0; i < size; i++)
		{
			if (game[i][size - 1 - i] == player)
			{
				counter++;
			}
			else
			{
				if (counter != win_size)
					counter = 0;
			}
		}
		if (counter == win_size)
		{
			*game_over = true;
			*win = true;
		}
	}
	counter = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			counter = 0;
			for (int z = 0; z + i < size; z++)
			{
				if (game[i + z][j + z] == player)
				{
					counter++;
				}
				else
				{
					if (counter != win_size)
						counter = 0;
				}
			}
			if (counter == win_size)
			{
				*game_over = true;
				*win = true;
				break;
			}
		}
	}
	counter = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		for (int j = 0; j < size; j++)
		{
			counter = 0;
			for (int z = 0; (z + j < size) && (i - z >= 0); z++)
			{
				if (game[i - z][j + z] == player)
				{
					counter++;
				}
				else
				{
					if (counter != win_size)
						counter = 0;
				}
			}
			if (counter == win_size)
			{
				*game_over = true;
				*win = true;
				break;
			}
		}
	}
	if (!*game_over)
	{
		counter = 0;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (game[i][j] != -1)
				{
					counter++;
				}
			}
		}
		if (counter == size * size)
		{
			tie = true;
			*game_over = true;
		}
	}
}

void game_AI_G(bool game_over, int** game, int size, int win_size, int dif)
{
	bool win = false;
	int turn = 1;
	sf::RenderWindow Window(sf::VideoMode(200 * size + 5 * (size - 1), 200 * size + 5 * (size - 1), 32),
		"kolko i krzyrzyk");
	Window.clear(sf::Color::White);
	while (!game_over)
	{
		draw_G(game, size, &Window);
		if (turn % 2 == 1)
		{
			player_turn(game, size, &Window, turn);
		}
		else
		{
			AI_turn(game, size, win_size, turn, dif);
		}
		Logic(turn, &game_over, game, size, &win, win_size);
		draw_G(game, size, &Window);
		turn++;
	}
	draw_G(game, size, &Window);
	if (win == true)
	{
		std::cout << "Gra zakonczona." << std::endl;
		if ((turn - 1) % -1 == 1)
		{
			std::cout << "Gre wygywa Gracz" << std::endl;
		}
		else
		{
			std::cout << "Gre wygrywa AI" << std::endl;
		}
	}
	else
	{
		std::cout << "Gra zakonczona remisem." << std::endl;
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	system("cls");
}

void game_player_G(bool game_over, int** game, int size, int win_size)
{
	bool win = false;
	int turn = 1;
	sf::RenderWindow Window(sf::VideoMode(200 * size + 5 * (size - 1), 200 * size + 5 * (size - 1), 32),
		"kolko i krzyrzyk");
	Window.clear(sf::Color::White);
	draw_G(game, size, &Window);
	while (!game_over)
	{
		draw_G(game, size, &Window);
		player_turn(game, size, &Window, turn);
		Logic(turn, &game_over, game, size, &win, win_size);
		draw_G(game, size, &Window);
		turn++;
	}
	draw_G(game, size, &Window);
	if (win == true)
	{
		std::cout << "Gra zakonczona." << std::endl;
		if ((turn - 1) % -1 == 1)
		{
			std::cout << "Gre wygywa Gracz 1" << std::endl;
		}
		else
		{
			std::cout << "Gre wygrywa Gracz -1" << std::endl;
		}
	}
	else
	{
		std::cout << "Gra zakonczona remisem." << std::endl;
	}

	std::this_thread::sleep_for(std::chrono::seconds(1));
	Window.close();
	system("cls");
}

void game_AI(bool game_over, int** game, int size, int win_size, int dif)
{
	bool win = false;
	int turn = 1;
	while (!game_over)
	{
		draw(game, size);
		switch (turn % 2)
		{
		case 0:
			AI_turn(game, size, win_size, turn, dif);
			break;
		case 1:
			player_turn(size, game, turn);
			break;
		default:
			break;
		}
		Logic(turn, &game_over, game, size, &win, win_size);
		turn++;
		system("cls");
	}
	draw(game, size);
	if (win == true)
	{
		std::cout << "Gra zakonczona." << std::endl;
		if ((turn - 1) % -1 == 1)
		{
			std::cout << "Gre wygywa Gracz 1" << std::endl;
		}
		else
		{
			std::cout << "Gre wygrywa AI" << std::endl;
		}
	}
	else
	{
		std::cout << "Gra zakonczona remisem." << std::endl;
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	system("cls");
}

void game_player(bool game_over, int** game, int size, int win_size)
{
	bool win = false;
	int turn = 1;
	while (!game_over)
	{
		draw(game, size);
		player_turn(size, game, turn);
		Logic(turn, &game_over, game, size, &win, win_size);
		turn++;
		system("cls");
	}
	draw(game, size);
	if (win == true)
	{
		std::cout << "Gra zakonczona." << std::endl;
		if ((turn - 1) % -1 == 1)
		{
			std::cout << "Gre wygywa Gracz 1" << std::endl;
		}
		else
		{
			std::cout << "Gre wygrywa Gracz -1" << std::endl;
		}
	}
	else
	{
		std::cout << "Gra zakonczona remisem." << std::endl;
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	system("cls");
}
