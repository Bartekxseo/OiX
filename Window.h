#pragma once

void player_turn(int** game, int size, sf::RenderWindow* Window, int turn)
{
	sf::Event event;
	bool eventdone = false;
	int py, px, x = -1, y = -1;
	while (!eventdone && Window->isOpen()==true)
	{
		while (Window->waitEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				Window->close();
				break;
			}
			if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				Window->close();
				break;
			}
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				px = event.mouseButton.x;
				py = event.mouseButton.y;
				for (x; px > 0; x++)
				{
					px = px - 205;
				}
				for (y; py > 0; y++)
				{
					py = py - 205;
				}
				if (game[y][x] == -1)
				{
					game[y][x] = turn % 2;
					eventdone = true;
				}
			}
			if (eventdone)
			{
				break;
			}
		}
	}
}

void draw_G(int** game, int size, sf::RenderWindow* Window)
{
	int px, py, x = 0, y = 0, turn = 1;

	for (int i = 0; i < size - 1; i++)
	{
		sf::RectangleShape Rec1(sf::Vector2f(200 * size + 5 * (size - 1), 5));
		sf::RectangleShape Rec2(sf::Vector2f(5, 200 * size + 5 * (size - 1)));
		Rec1.setFillColor(sf::Color::Black);
		Rec2.setFillColor(sf::Color::Black);
		Rec1.setPosition(sf::Vector2f(0, 200 * (i + 1)));
		Rec2.setPosition(sf::Vector2f(200 * (i + 1), 0));
		Window->draw(Rec1);
		Window->draw(Rec2);
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			sf::CircleShape circ(96.f);
			sf::RectangleShape Rec1(sf::Vector2f(280, 5));
			sf::RectangleShape Rec2(sf::Vector2f(280, 5));
			Rec1.setPosition(sf::Vector2f(0, 0));
			Rec2.setPosition(sf::Vector2f(0, 0));
			circ.setPosition(sf::Vector2f(0, 0));
			int k = j + 1;
			switch (game[i][j])
			{
			case 1:

				circ.setFillColor(sf::Color::White);
				circ.setOutlineColor(sf::Color::Black);
				circ.setOutlineThickness(3);
				circ.move(sf::Vector2f(205 * j + 0.5, 205 * i + 0.5));
				Window->draw(circ);
				break;
			case 0:

				Rec1.setFillColor(sf::Color::Black);
				Rec2.setFillColor(sf::Color::Black);
				Rec1.setRotation(45);
				Rec2.setRotation(135);
				Rec1.move(sf::Vector2f(205 * j, 205 * i));
				Rec2.move(sf::Vector2f(202.5 * k, 205 * i));
				Window->draw(Rec1);
				Window->draw(Rec2);
				break;
			case -1:
				break;
			}
		}
		Window->display();
	}
}