#include "pch.h"
#include "Mine_Board.h"
#include <iostream>

Mine_Board::Mine_Board(int x, int y, int mine) : Board(x, y)
{
	this->numMines = mine;
	this->set_Mine();
	this->set_Num();
}

Mine_Board::~Mine_Board()
{
}
void Mine_Board::set_Mine() {
	int x, y;	
	for (int i = 0; i < get_numMines(); i++) {
		x = this->get_RandNum(0, this->get_row());
		y = this->get_RandNum(0, this->get_col());
		// 지뢰 중복 확인
		if (this->get_cell(x, y) == 0) {
			this->set_cell(x, y, 9);
		}
		else { // 중복일시 재시도
			i--;
			//std::cout << "re" << std::endl;
		}
	}
}
void Mine_Board::set_Num() {
	for (int i = 0; i < this->get_row(); i++) {
		for (int j = 0; j < this->get_col(); j++) {
			if (this->get_cell(i, j) != 9) {
				int n = 0; // 주변 지뢰 개수
				for (int i2 = (i - 1); i2 < (i + 2); i2++) {
					for (int j2 = (j - 1); j2 < (j + 2); j2++) {
						// (배열 밖 지정시 overflow 발생 가능 지점)
						if ((i2 == i && j2 == j) || (i2 < 0) || (j2 < 0) || (i2 >= this->get_row()) || (j2 >= this->get_col())) { // 자신 셀이거나 배열 밖이면 패스
							continue;
						}
						else if (this->get_cell(i2, j2) == 9) {
							// 주변에 지뢰가 있다면
							n++;
						}
					}
				}
				// 값 설정
				this->set_cell(i, j, n);
			}
		}
	}
}

int Mine_Board::get_RandNum(int min, int max) {
	return rand() % max + min;
}

int Mine_Board::get_numMines() {
	return this->numMines;
}