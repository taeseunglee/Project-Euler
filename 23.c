#include <stdio.h>
#include <stdlib.h>

int get_abundant_array(int **);
int binary_search(int *arr, int data, int size);

int main()
{
  int *abundant_array = NULL;
  int abundant_cnt = get_abundant_array(&abundant_array);

  int t;
  scanf("%d", &t);

  for (int t_i = 0; t_i < t; ++t_i)
    {
      int n;
      scanf("%d", &n);

      if (n > 28123)
        printf("YES\n");
      else
        {
          int is_found = 0;

          for (int i = 0; i < abundant_cnt; ++i)
            {
              if (binary_search(abundant_array, n - abundant_array[i], abundant_cnt) != -1)
                {
                  is_found = 1;
                  break;
                }
            }

          if (is_found) // n is expressed n + (n - abundant_array[i])
            printf("YES\n");
          else
            printf("NO\n");
        }
    }

  free(abundant_array);

  return 0;
}

int get_abundant_array(int **abundant_array)
{
  int cnt = 0,
      *temp_array = calloc(28123, sizeof(int)),
      *new_abudant = NULL;

  // each number
  for (int n_i = 1; n_i < 28123; ++n_i)
    {
      // calculate sum of proper divisor
      int sum = 1;
      for (int i = 2; i*i <= n_i; ++i)
        {
          if (!(n_i%i))
            {
              int temp = n_i/i;
              if (i != temp)
                sum += i + temp;
              else
                sum += i;
            }
        }
      if (n_i < sum)
        temp_array[cnt++] = n_i;
    }

  new_abudant = calloc(cnt, sizeof(int));

  for (int i = 0; i < cnt; ++i)
    new_abudant[i] = temp_array[i];
  *abundant_array = new_abudant;

  free(temp_array);

  return cnt;
}

int binary_search(int *arr, int data, int size)
{
  int left = 0, right = size - 1, mid = (left + right) / 2;
  while (left <= right)
    {
      int cmp = data - arr[mid];

      if (cmp < 0)
        right = mid-1;
      else if (cmp > 0)
        left = mid+1;
      else
        return mid;
      mid = (left + right) / 2;
    }
  return -1; // Not found
}
