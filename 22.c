#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 16

void merge_sort(char* *arr, int size);
void merge(char* *arr, char** left_arr, char** right_arr, int size);
void print_array(char **array, int size);
int binary_search(char **arr, char* data, int size);
int get_worth(char *str);

int main()
{
  int n;
  char **name_array = NULL;

  /* set an array */
  scanf("%d", &n);
  name_array = calloc(n, sizeof(char *));
  for (int n_i = 0; n_i < n; ++n_i)
    {
      name_array[n_i] = calloc(MAX_LEN, sizeof(char));
      scanf("%s", name_array[n_i]);
    }

  /* sort */
  merge_sort(name_array, n);
  
  /* get queries and print results */
  int query;
  scanf("%d", &query);

  for (int q_i = 0; q_i < query; ++q_i)
    {
      char str[13] = {0,};
      scanf("%s", str);

      int loc = binary_search(name_array, str, n);
      printf("%d\n", get_worth(str) * (loc+1));
    }

  /* deallocation */
  for (int i = 0; i < n; ++i)
    free(name_array[i]);
  free(name_array);

  return 0;
}

void merge_sort(char **arr, int size)
{
  if (size < 2)
    return ;

  int left_size = size / 2, right_size = size - left_size;
  char **left_arr = calloc(left_size, sizeof(char*)),
       **right_arr = calloc(right_size, sizeof(char *));

  for (int i = 0; i < left_size; ++i)
    left_arr[i] = arr[i];
  for (int i = 0; i < right_size; ++i)
    right_arr[i] = arr[i+left_size];


  merge_sort(left_arr, left_size);
  merge_sort(right_arr, right_size);

  merge(arr, left_arr, right_arr, size);

  free(left_arr);
  free(right_arr);
}

void merge(char **arr, char ** left_arr, char **right_arr, int size)
{
  int left_size = size/2, right_size = size - left_size;
  int left_i = 0, right_i = 0, arr_i = 0;

  while (left_i < left_size && right_i < right_size)
    {
      if (strcmp(left_arr[left_i], right_arr[right_i]) < 0)
        {
          arr[arr_i] = left_arr[left_i];
          ++left_i, ++arr_i;
        }
      else
        {
          arr[arr_i] = right_arr[right_i];
          ++right_i, ++arr_i;
        }
    }

  while (left_i < left_size)
    {
      arr[arr_i] = left_arr[left_i];
      ++left_i, ++arr_i;
    }
  while (right_i < right_size)
    {
      arr[arr_i] = right_arr[right_i];
      ++right_i, ++arr_i;
    }
}

void print_array(char **array, int size)
{
  for (int i = 0; i < size; ++i)
    printf("%s\n", array[i]);
  printf("----------------------------\n");
}

int binary_search(char **arr, char* data, int size)
{
  int left = 0, right = size - 1, mid = (left + right) / 2;
  while (left <= right)
    {
      int cmp = strcmp(data, arr[mid]);

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

int get_worth(char *str)
{
  int res = 0;
  for (int s_i = 0; str[s_i]; ++s_i)
    res += (str[s_i] - 64);

  return res;
}
