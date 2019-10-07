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
	else if (!(this->is_checked(x, y))) { // ���µ��� ���� �� �̶��
		int copyed = b->get_cell(x, y);
		// ���ڶ��
		if (copyed == 9) {
			this->set_cell(x, y, b->get_cell(x, y));
			this->GameOver();
		}
		// �ֺ� 8ĭ�� ���� ���ȣ��
		else if (copyed == 0) {
			for (int i = (x - 1); i < (x + 2); i++) {
				for (int j = (y - 1); j < (y + 2); j++) {
					if ((i == x && j == y) || (i < 0) || (j < 0) || (i >= this->get_row()) || (j >= this->get_col())) { // �ڽ� ���̰ų� �迭 ���̸� �н�
						continue;
					}
					// ��� ȣ��
					this->set_cell(x, y, b->get_cell(x, y));
					this->open(i, j, b);
				}
			}
		}
		else {
			this->set_cell(x, y, b->get_cell(x, y));
		}
		// ���� ĭ �� ���
		this->numOpened++;

		// �¸� ���� : ���� ĭ �� = ���� ��
		if ((this->get_row()*this->get_col() - this->numOpened) == this->numMines)
		{
			this->GameClear();
		}
	}
}

bool Player_Board::is_checked(int x, int y) {
	// �⺻������ 10 . Ȯ���� ��� �ٸ������� ����
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
	// �¸�
}