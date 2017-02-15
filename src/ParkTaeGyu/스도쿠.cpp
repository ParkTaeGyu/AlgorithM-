#include<iostream>
using namespace std;
int sudoku[10][10];
int check_num[9];
int centerx, centery;
int dx[9] = { -1, -1, -1, 0,0,0, 1, 1, 1 };
int dy[9] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };

int ThreeToThreeCheck(int centery,int centerx)
{
	int cnt = 0;
	for (int i = 0; i <= 8; i++)
	{
		if (sudoku[centery + dy[i]][centerx + dx[i]] == 0) cnt++;
	}
	return cnt;
}

int RowCheck(int row)
{
	int cnt = 0;
	for (int i = 1; i <= 9; i++)
		if (sudoku[row][i] == 0) cnt++;
	return cnt;
}

int ColumnCheck(int col)
{
	int cnt = 0;
	for (int i = 1; i <= 9; i++)
	if (sudoku[i][col] == 0) cnt++;
	return cnt;
}


int main()
{
	for (int i = 1; i <= 9; i++)
	for (int j = 1; j <= 9; j++)
		cin >> sudoku[i][j];

	for (int i = 2; i <= 8; i += 3)
	for (int j = 2; j <= 8; j += 3)
		ThreeToThreeCheck(j, i);
	for (int i = 1; i <= 9; i++)
	{
		RowCheck(i);
		ColumnCheck(i);
	}



	return 0;
}