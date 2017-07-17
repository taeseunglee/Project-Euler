#include <stdio.h>

int sum_pd[100001];
int amicable_num[10000];
int max_amicable;

void get_sum_pd(void);
void set_amicable_array(void);

int main()
{
  get_sum_pd();
  set_amicable_array();


  int t;
  scanf("%d", &t);

  for (int t_i = 0; t_i < t; ++t_i)
    {
      int n, res = 0;
      scanf("%d", &n);

      for (int i = 0; i < max_amicable && amicable_num[i] <= n; ++i)
        res += amicable_num[i];

      printf("%d\n", res);
    }

  return 0;
}

void get_sum_pd(void)
{
  // each number
  for (int n_i = 1; n_i < 100001; ++n_i)
    {
      // calculate sum of proper divisor
      int sum = 1;
      for (int i = 2; i*i <= n_i; ++i)
        if (!(n_i%i))
          {
            int temp = n_i/i;
            if (i != temp)
              sum += i + temp;
            else
              sum += i;
          }
      sum_pd[n_i] = sum;
    }
}

void set_amicable_array(void)
{
  for (int i = 2; i < 100001; ++i)
    {
      int temp = sum_pd[i];
      if (temp < 100001 && 
          i == sum_pd[temp] &&
          i != temp)
        amicable_num[max_amicable++] = i;
    }
}
