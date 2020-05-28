#pragma once
#define ADDC 2

bool is_win(int turn, int win_size, int** game, int size, bool* tie)
{
	int player = turn % 2;
	int counter = 0;
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
			return true;
			break;
		}
		counter = 0;
	}
	counter = 0;
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
			return true;
			break;
		}
		counter = 0;
	}
	counter = 0;
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
		return true;
	}
	counter = 0;
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
		return true;
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
				return true;
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
				return true;
			}
		}
	}
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
		*tie = true;
	}
	return false;
}

int min_max(int** game, int turn, int win_size, int size, int depth)
{
	if (turn <= depth)
	{
		int m = 0, mmx = 0;
		bool tie = false;
		if (is_win(turn, win_size, game, size, &tie))
		{
			{
				if (turn % 2 == 0)
				{
					return 1;
				}
				return -1;
			}
		}
		if (tie)
		{
			return 0;
		}
		turn++;
		if (turn % 2 == 1)
		{
			mmx = 10;
		}
		else
		{
			mmx = -10;
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (game[i][j] == -1)
				{
					game[i][j] = turn % 2;
					m = min_max(game, turn, win_size, size, depth);
					game[i][j] = -1;
					if (((turn % 2 == 1) && (m < mmx)) || ((turn % 2 == 0) && (m > mmx)))
					{
						mmx = m;
					}
				}
			}
		}
		return mmx;
	}
}

void AI_turn(int** game, int size, int win_size, int turn, int dif)
{
	srand(std::time(NULL) + turn);
	int depth = win_size + ADDC + turn;
	int choice1 = 0, choice2 = 0, m = 0, mmx = -10, tmp = 0;
	tmp = rand() % 100;
	if (tmp >= dif)
	{
		do
		{
			choice1 = rand() % size;
			choice2 = rand() % size;
		} while (game[choice1][choice2] != -1);
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (game[i][j] == -1)
				{
					game[i][j] = turn % 2;
					m = min_max(game, turn, win_size, size, depth);
					game[i][j] = -1;
					if (m > mmx)
					{
						mmx = m;
						choice1 = i;
						choice2 = j;
					}
				}
			}
		}
	}
	game[choice1][choice2] = turn % 2;
}
