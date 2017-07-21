#include <stdio.h>
#include <stdlib.h>

int main()
{
  int digit[13];
  for (int d_i = 0, size = 1; d_i < 13; size *= d_i)
    {
      digit[12-d_i] = size;
      ++ d_i;
    }

  int t;
  scanf("%d", &t);
  for (int t_i = 0; t_i < t; ++t_i)
    {
      int is_char_assigned[13] = {0,};

      int num;
      scanf("%d", &num);
      --num;

      for (int w_i = 0; w_i < 13; ++w_i)
        {
          int digit_num = num / digit[w_i];
          num %= digit[w_i];

          // assign character - for loop
          for (int c_i = 0; c_i < 13; ++c_i)
            {
              if (!is_char_assigned[c_i])
                {
                  if (!digit_num)
                    {
                      is_char_assigned[c_i] = 1;
                      printf("%c", c_i + 'a');
                      break;
                    }
                  -- digit_num;
                }
            }
        }
      printf("\n");
    }

  return 0;
}
