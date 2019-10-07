// MineSweeper.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include "pch.h"
#include "Mine_Board.h"
#include "Player_Board.h"
// #include "LEVEL.h" 
#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>	

int size = 32; // 이미지 크기
bool game_over = false;
// 보드 크기에 따른 윈도우 상대 크기값
int window_row, window_col = 0;
Mine_Board *mineB;
Player_Board *playerB;

void initGrid(int x, int y); //  윈도우 상대 크기 초기화

void initGrid(int x, int y) {
	window_row = x;	
	window_col = y;
}

int main()
{
	std::cout << "Mine Sweeper!\n";
	// rand 시드 
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	sf::RenderWindow app(sf::VideoMode(640, 640), "MineSweeper");
	// LEVEL e = LEVEL::EASY;
	
	mineB = new Mine_Board(20, 20, 10);
	playerB = new Player_Board(20, 20, 10);

	initGrid(20, 20);

	sf::Texture t;
	t.loadFromFile("tiles.jpg");
	sf::Sprite s(t);
	while (app.isOpen() && !game_over)
	{
		sf::Vector2i pos = sf::Mouse::getPosition(app);
		int x = pos.x / size;
		int y = pos.y / size;

		sf::Event e;
		while (app.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				app.close();

			if (e.type == sf::Event::MouseButtonPressed)
				if (e.key.code == sf::Mouse::Left) playerB->open(x, y, mineB);
				else if (e.key.code == sf::Mouse::Right) {
					// 깃발 표시
					if (playerB->get_cell(x, y) == 10) {
						playerB->set_cell(x, y, 11);
					}
					else if (playerB->get_cell(x, y) == 11) {
						playerB->set_cell(x, y, 10);
					}
				}
		}

		app.clear(sf::Color::White);
		for (int i = 0; i < window_row; i++)
			for (int j = 0; j < window_col; j++)
			{
				if (playerB->get_cell(i,j) == 9) playerB->open(i, j, mineB);
				s.setTextureRect(sf::IntRect(playerB->get_cell(i, j) * size, 0, size, size));
				s.setPosition(i*size, j*size);
				app.draw(s);
			}
		game_over = playerB->gameover;
		app.display();
	}
}
