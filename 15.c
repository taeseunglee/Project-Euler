#include <stdio.h>

#define MOD 1000000007

int mem[501][501];

int main()
{
  for (int i = 1; i < 501; ++i)
    {
      mem[i][1] = i+1;
      mem[1][i] = i+1;
    }

  for (int i = 2; i < 501; ++i)
    for (int j = 2; j < 501; ++j)
      {
        mem[i][j] = mem[i-1][j] + mem[i][j-1];
        mem[i][j] %= MOD;
      }

  int t;
  scanf("%d", &t);
  for (int t_i = 0; t_i < t; ++t_i)
    {
      int row, col;
      scanf("%d %d", &row, &col);
      printf("%d\n", mem[row][col]);
    }

  return 0;
}
