#include "pch.h"
#include "Board.h"

Board::Board(int x, int y)
{
	this->rows = x;
	this->cols = y;
	this->make_Array(this->rows, this->cols);
}


Board::~Board()
{
	// 동적으로 할당된 2차원 배열 해제
	for (int i = 0; i < this->rows; i++) {
		delete[] mine_Array[i];
	}
	delete [] mine_Array;
}

int Board::get_cell(int x, int y) {
	return this->mine_Array[x][y];
}
int Board::get_row() {
	return this->rows;
}
int Board::get_col() {
	return this->cols;
}
void Board::set_cell(int x, int y, int set) {
	this->mine_Array[x][y] = set;
}

void Board::make_Array(int x, int y) {
	// 2차원 배열을 동적 할당하기 위한 반복문
	this->mine_Array = new int*[x];
	for (int i = 0; i < x; i++) {
		this->mine_Array[i] = new int[y](); // 값을 0 으로 채움
	}
}