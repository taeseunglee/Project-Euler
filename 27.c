#include <stdio.h>
#include <stdlib.h>

struct __res
{
  int cnt;
  int a;
  int b;
};

#define PRIME_BOUND 40002

int main()
{
  /* init */
  int *is_prime = calloc(PRIME_BOUND, sizeof(int));
  int cnt_prime = 0;
  for (int i = 2; i < PRIME_BOUND; ++i)
    is_prime[i] = 1;

  /* determine 'is this number a prime?' */
  for (int p_i = 2; p_i < PRIME_BOUND; ++p_i)
    if (is_prime[p_i])
      {
        ++ cnt_prime;
        for (int i = p_i*p_i; i < PRIME_BOUND; i += p_i)
          is_prime[i] = 0;
      }

  /* get primes array */
  int *primes = calloc(cnt_prime, sizeof(int));
  int idx, p_i;
  for (idx = 0, p_i = 2; p_i < PRIME_BOUND; ++p_i)
    if (is_prime[p_i])
      primes[idx++] = p_i;

  /*********************************************/

  /* check n*n + a*n + b is prime */
  /* a : an odd number, b : a prime number */
  int n;
  scanf("%d", &n);

  int start_a = n;
  struct __res max = 
    {
      .cnt = -1,
      .a = 0,
      .b = 0,
    };
  if (!(n%2))
    start_a = -n+1;

  for (int a_i = start_a; a_i <= n; a_i += 2)
    {
      for (int b_i = 0; b_i < cnt_prime && primes[b_i] <= n; ++b_i)
        {
          long long int n_i = 0;
          for (n_i = 0; ; ++n_i)
            {
              long long int poly_res = (long long int)n_i*n_i + a_i*n_i + primes[b_i];

              if (poly_res < 0) break;
              if (!is_prime[poly_res])
                break;
            }

          if (max.cnt < n_i)
            {
              max.cnt = n_i;
              max.a = a_i;
              max.b = primes[b_i];
            }
        }
    }
  printf("%d %d\n", max.a, max.b);

  return 0;
}
