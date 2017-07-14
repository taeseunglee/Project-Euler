#include <stdio.h>
#include <stdlib.h>

int main()
{
  int t;
  scanf("%d", &t);

  for (int t_i = 0; t_i < t; ++ t_i)
    {
      int n;
      scanf("%d", &n);

      int ** triangle = calloc(n, sizeof(int*));
      for (int n_i = 0; n_i < n; ++n_i)
        triangle[n_i] = calloc(n_i+1, sizeof(int));

      for (int n_i = 0; n_i < n; ++n_i)
        {
          int bound = n_i+1;
          for (int n_j = 0; n_j < bound; ++n_j)
            scanf("%d", &triangle[n_i][n_j]);
        }

      for (int n_i = 1; n_i < n; ++n_i)
        {
          // left
          triangle[n_i][0] += triangle[n_i-1][0];
          // middle
          for (int n_j = 1; n_j < n_i; ++n_j)
            {
              if (triangle[n_i-1][n_j-1] < triangle[n_i-1][n_j])
                triangle[n_i][n_j] += triangle[n_i-1][n_j];
              else
                triangle[n_i][n_j] += triangle[n_i-1][n_j-1];
            }
          // right
          triangle[n_i][n_i] += triangle[n_i-1][n_i-1];
        }

      
      int max_num = -1;
      for (int n_i = 0; n_i < n; ++n_i)
        {
          if (max_num < triangle[n-1][n_i])
            max_num = triangle[n-1][n_i];
        }
      printf("%d\n", max_num);

      free(triangle);
    }

  return 0;
}
