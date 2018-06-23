#include<iostream>
#include<string>
#include<stdlib.h>
#include<fstream>
//#include"FunctionsS.h"

int Castling(int a[8][8], int y, int x, int y1, int x1, int cast)
{
	if ((abs(x - x1) == 2) && (y = y1) && (x1 != x))
	{
		if (CheckSafetyKing(a, y, x) == 0)
		{
			if ((x1 > x) && ((cast == 3) || (cast == 2)))
			{
				for (int i = x + 1; i < 8; i++)
				{
					if ((abs(x - i) <= 2) && (CheckSafetyKing(a, y, i) == 1)) return 0;
					if (a[y][i] != 0) return 0;
				}
				return 5;
			}
			if ((x1 < x) && ((cast == 3) || (cast == 1)))
			{
				for (int i = x - 1; i > 1; i--)
				{
					if ((abs(x - i) <= 2) && (CheckSafetyKing(a, y, i) == 1)) return 0;
					if (a[y][i] != 0) return 0;
				}
				return 5;
			}
			return 0;
		}
	}
	else return 0;
}

int Charge(int a[8][8], int y, int x, int y1, int x1)
{
	if ((a[y][x] == 1) && ((y - y1) == 2))
	{
		if ((a[y1][x1 - 1] == 7) || (a[y1][x1 + 1] == 7)) return 1;
	}
	else if ((a[y][x] == 7) && ((y1 - y) == 2))
	{
		if ((a[y1][x1 - 1] == 1) || (a[y1][x1 + 1] == 1)) return 1;
	}
	else return 0;
}

void Change(int a[8][8], int y, int x)
{
	int l = 0;
	if ((a[y][x] == 1) && (y == 1))
	{
		cout << "Choose figure for transfer:" << endl;
		cout << "1.Pawn" << endl;
		cout << "2. Rook" << endl;
		cout << "3.Knight" << endl;
		cout << "4. Bishop" << endl;
		cout << "5. Queen" << endl;
		cin >> l;
		if ((l >= 1) && (l <= 5)) a[y][x] = l;
	}
	if ((a[y][x] == 7) && (y == 8))
	{
		cout << "Choose figure for transfer:" << endl;
		cout << "7.Pawn" << endl;
		cout << "8. Rook" << endl;
		cout << "9.Knight" << endl;
		cout << "10. Bishop" << endl;
		cout << "11. Queen" << endl;
		cin >> l;
		if ((l >= 7) && (l <= 11)) a[y][x] = l;
	}
}