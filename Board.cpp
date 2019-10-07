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
	// �������� �Ҵ�� 2���� �迭 ����
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
	// 2���� �迭�� ���� �Ҵ��ϱ� ���� �ݺ���
	this->mine_Array = new int*[x];
	for (int i = 0; i < x; i++) {
		this->mine_Array[i] = new int[y](); // ���� 0 ���� ä��
	}
}