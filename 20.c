#include <stdio.h>
#include <stdlib.h>

#define MODE 1

// DTYPE = int or long long int
// Implment big int using DTYPE Array
#if MODE == 1
  #define DTYPE int
// EXP = 10^6
  #define EXP 1000000
  #define MAX_SIZE 500
#else
  #define DTYPE long long int
// EXP = 10^14
  #define EXP 100000000000000
  #define MAX_SIZE 200
#endif

void multiply_big_int(DTYPE *big_int, int n);
int sum_of_digit(DTYPE *big_int);


int main()
{
#ifdef TEST
  for (int i_n = 1; i_n <= 100; ++ i_n)
    {
      printf("step %d: ", i_n);
      for (int  = 4; k >= 0; --k)
        {
  #if MODE == 1
          printf("%05d", big_int[k]);
  #else
          printf("%013d", big_int[k]);
  #endif
        }
      printf("\n");
    }
#else /* TEST */
  int t;
  scanf("%d", &t);

  for (int t_i = 0; t_i < t; ++t_i)
    {
      int n;
      scanf("%d", &n);

      DTYPE *big_int = calloc(MAX_SIZE, sizeof(DTYPE));
      multiply_big_int(big_int, n);
      printf("%d\n", sum_of_digit(big_int));
      free(big_int);
    }
#endif /* NOT TEST */

  return 0;
}

void multiply_big_int(DTYPE *big_int, int n)
{
  int carry_num = 0;
  big_int[0] = 1;
  for (int i_n = 2; i_n <= n; ++ i_n)
    {
      for (int j = 0; j < MAX_SIZE; ++j)
        {
          big_int[j] = big_int[j] * i_n + carry_num;
          carry_num = big_int[j] / EXP;
          big_int[j] %= EXP;
        }
    }
}

int sum_of_digit(DTYPE *big_int)
{
  int res = 0;
  DTYPE temp;

  for (int i = 0; i < MAX_SIZE; ++i)
    {
      temp = big_int[i];

      for (int j = 0; j < 15; ++j)
        {
          res += temp%10;
          temp /= 10;
        }
    }

  return res;
}
