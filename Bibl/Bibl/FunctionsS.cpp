#include<iostream>
#include<string>
#include<stdlib.h>
#include<fstream>
//#include"FunctionsL.h"

using namespace std;


void SwapMove(int *a, int *b)
{
	*b = *a;
	*a = 0;
}

void stdout_chess(int a[8][8], int k)
{
	for (int i = 1; i < 9; i++)
	{
		printf("\n | \n");
		if (k == 0)
			printf("%d|", 9 - i);
		else
			printf("%d|", i);
		for (int j = 1; j < 9; j++)
			if (k == 0) printf("%3d ", a[i][j]);
			else printf("%3d ", a[9 - i][9 - j]);
	}
	printf("\n");
	printf(" ---------------------------------\n");
	if (k == 0)
		printf("  %3c %3c %3c %3c %3c %3c %3c %3c\n", 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h');
	else
		printf("  %3c %3c %3c %3c %3c %3c %3c %3c\n", 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a');
}

int CheckSafetyKing(int a[8][8], int y, int x)
{
	for (int i = 1; i<9; i++)
		for (int j = 1; j<9; j++)
			if (CheckMove(a, i, j, y, x) == 2) return 1;
	return 0;
}

int Attack(int a[8][8], int y, int x, int y1, int x1)
{
	if (a[y][x] == 1)
	{
		if ((a[y][x - 1] == 7) || (a[y][x + 1] == 7)) return 6;
	}
	if (a[y][x] == 7)
	{
		if ((a[y][x - 1] == 1) || (a[y][x + 1] == 1)) return 6;
	}
	return 0;
}

