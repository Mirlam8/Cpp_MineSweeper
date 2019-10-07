#pragma once
class Board
{
private:
	int rows = 2; // ���� x��
	int cols = 2; // ���� y��
	int **mine_Array = nullptr;
	void make_Array(int x, int y);

public:
	Board(int x, int y);
	~Board();
	int get_cell(int x, int y);
	int get_row();
	int get_col();
	void set_cell(int x, int y, int set);
};

