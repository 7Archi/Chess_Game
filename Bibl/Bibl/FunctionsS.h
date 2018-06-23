//#pragma inline_depth
//once
#ifndef GS
#define GS
void SwapMove(int *a, int *b);
void stdout_chess(int **a, int k);
int CheckSafetyKing(int **a, int y, int x);
int Attack(int **a, int y, int x, int y1, int x1);
#endif
