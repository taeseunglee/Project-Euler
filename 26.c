#include <stdio.h>
#include <stdlib.h>

int get_cycle_len(int n);

int main()
{
  int *cycle_len = calloc(10001, sizeof(int));

  cycle_len[3] = 1;
  for (int i = 4; i < 10001; ++i)
    cycle_len[i] = get_cycle_len(i);

  int *longest_num = calloc(10001, sizeof(int));
  int max_cycle_len = 1, max_num = 3;
  for (int i = 4; i < 10001; ++i)
    {
      longest_num[i] = max_num;
      if (cycle_len[i] > max_cycle_len)
        {
          max_num = i;
          max_cycle_len = cycle_len[i];
        }
    }

  
  int t;
  scanf("%d", &t);

  for (int t_i = 0; t_i < t; ++t_i)
    {
      int n;
      scanf("%d", &n);

      printf("%d\n", longest_num[n]);
    }
  
  free(cycle_len);
  return 0;
}


int get_cycle_len(int n)
{
  int *remainder_pos = calloc(n, sizeof(int)),
      pos = 1,
      cur_val = 1;

  /*
     (remainder_pos[cur_val] != 0): find a cycle.
     => cycle_len = pos - remainder_pos[cur_val]
     
     (cur_val == 0): n doesn't have a cycle.
     => cycle_len = 0
  */
  while (!remainder_pos[cur_val] && cur_val != 0)
    {
      remainder_pos[cur_val] = pos;
      cur_val = (cur_val*10)%n;
      ++pos;
    }

  if (cur_val)
    return pos - remainder_pos[cur_val];
  else
    return 0;
}
