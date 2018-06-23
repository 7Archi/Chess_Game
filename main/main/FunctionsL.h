//#pragma once
#ifndef GL
#define GL
int CheckSafetyKing(int **a, int y, int x);
int Castling(int **a, int y, int x, int y1, int x1, int cast);
int Charge(int **a, int y, int x, int y1, int x1);
void Change(int **a, int y, int x);
#endif