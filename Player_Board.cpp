#include "pch.h"
#include "Player_Board.h"
#include <iostream>


Player_Board::Player_Board(int x, int y, int mine) : Board(x, y)
{
	this->init_Array(10);
	this->numOpened = 0;
	this->numMines = mine;
}

Player_Board::~Player_Board()
{
}

void Player_Board::init_Array(int k) {
	for (int i = 0; i < this->get_row(); i++) {
		for (int j = 0; j < this->get_col(); j++) {
			this->set_cell(i, j, k);
		}
	}
}

void Player_Board::open(int x, int y, Board *b) {
	if ((x < 0) || (y < 0) || (x >= this->get_row()) || (y >= this->get_col())) {

	}
	else if (!(this->is_checked(x, y))) { // 오픈되지 않은 곳 이라면
		int copyed = b->get_cell(x, y);
		// 지뢰라면
		if (copyed == 9) {
			this->set_cell(x, y, b->get_cell(x, y));
			this->GameOver();
		}
		// 주변 8칸에 대해 재귀호출
		else if (copyed == 0) {
			for (int i = (x - 1); i < (x + 2); i++) {
				for (int j = (y - 1); j < (y + 2); j++) {
					if ((i == x && j == y) || (i < 0) || (j < 0) || (i >= this->get_row()) || (j >= this->get_col())) { // 자신 셀이거나 배열 밖이면 패스
						continue;
					}
					// 재귀 호출
					this->set_cell(x, y, b->get_cell(x, y));
					this->open(i, j, b);
				}
			}
		}
		else {
			this->set_cell(x, y, b->get_cell(x, y));
		}
		// 열은 칸 수 기록
		this->numOpened++;

		// 승리 조건 : 남은 칸 수 = 지뢰 수
		if ((this->get_row()*this->get_col() - this->numOpened) == this->numMines)
		{
			this->GameClear();
		}
	}
}

bool Player_Board::is_checked(int x, int y) {
	// 기본적으로 10 . 확인한 경우 다른값으로 변경
	bool checked = false;
	if (this->get_cell(x, y) != 10) {
		checked = true;
	}
	return checked;
}

void Player_Board::GameOver() {
	this->gameover = true;
	std::cout << "Game Over !\n";
}
void Player_Board::GameClear() {
	std::cout << "Game Clear !\n";
	// 승리
}