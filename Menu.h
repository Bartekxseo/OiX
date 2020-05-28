#pragma once

void change_game_size(int** size)
{
	system("cls");
	std::cout << "Podaj wielkosc pola" << std::endl;
	do
	{
		if (**size < 3)
		{
			std::cout << "Podano bledna wartosc" << std::endl;
		}
		std::cin >> **size;
	} while (**size < 3);
}

void change_win_size(int** win_size, int* size)
{
	system("cls");
	std::cout << "Podaj ilosc znakow do wygranej" << std::endl;
	do
	{
		if (**win_size < 3 || **win_size > * size)
		{
			std::cout << "Podano bledna wartosc" << std::endl;
		}
		std::cin >> **win_size;
	} while (**win_size < 3 || **win_size > * size);
}

void rules(int win_size)
{
	std::cout << "Aby wygrac nalezy ulozyc " << win_size << " znakow w prostej lini" << std::endl;
	std::cout <<
		"Licza sie znaki ulozone na calej dlugosci kolumny badz wiersza lub znaki ulozone na jedenj z dwoch glownych przekatnych"
		<< std::endl;
	system("pause");
	system("cls");
}

void menu(int* size, bool* AI, bool* game_over, bool* end, int* win_size, bool* windowed, int* dif)
{
	bool start = false;
	int option;
	while (!start)
	{
		std::cout << "Wielkosc pola gry: " << *size << std::endl;
		std::cout << "Ilosc znakow do wygranej: " << *win_size << std::endl;
		if (*AI)
		{
			std::cout << "Gracz vs AI" << std::endl;
			std::cout << "Trudnosc gracza AI: ";
			if (*dif == 0) std::cout << "Latwy" << std::endl;
			if (*dif == 1) std::cout << "Sredni" << std::endl;
			if (*dif == -1) std::cout << "Trudny" << std::endl;
		}
		else
		{
			std::cout << "Gracz vs Gracz" << std::endl;
		}
		if (*windowed)
		{
			std::cout << "Wersja okienkowa" << std::endl;
		}
		else
		{
			std::cout << "Wersja konsolowa" << std::endl;
		}
		std::cout << std::endl;
		std::cout << "1. Start" << std::endl;
		std::cout << "2. Zmien pole gry" << std::endl;
		std::cout << "3. Zmien przeciwnika" << std::endl;
		std::cout << "4. Zmien ilosc pol do wygranej" << std::endl;
		std::cout << "5. Zmien wersje gry" << std::endl;
		std::cout << "6. Zmien trudnosc" << std::endl;
		std::cout << "7. Zasady" << std::endl;
		std::cout << "8. Koniec" << std::endl;
		std::cin >> option;
		system("cls");
		switch (option)
		{
		case 1:
			std::cout << "Milej gry" << std::endl;
			start = true;
			break;
		case 2:
			change_game_size(&size);
			break;
		case 3:
			*AI = !*AI;
			break;
		case 8:
			start = true;
			*game_over = true;
			*end = true;
			break;
		case 7:
			rules(*win_size);
			break;
		case 4:
			change_win_size(&win_size, size);
			break;
		case 5:
			*windowed = !*windowed;
			break;
		case 6:
			(*dif)++;
			*dif = *dif % 3;
			break;
		default:
			std::cout << "Brak takiej opcji" << std::endl;
			break;
		}
		system("cls");
	}
	if (!*game_over)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		system("cls");
	}
}
