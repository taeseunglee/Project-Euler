#include <stdio.h>

// 10^9 + 7
#define MOD 1000000007

int main()
{
  // n: input
  // t = (n+1)/2
  // term1: (t-1)t(2t-1)*8/3
  // term2: 2t(t+1)
  // res = (term1 + term2 - 3) (mod MOD)

  int t;
  scanf("%d", &t);

  for (int t_i = 0; t_i < t; ++t_i)
    {
      long long int term[2] = {0,}, n, t;
      scanf("%lld", &n);
      t = (n+1)/2;


      /* calculate term1 */
      if (!((t-1)%3))
        {
          term[0] = (t-1)/3 % MOD;
          term[0] = (term[0]*(t % MOD)) % MOD;
          term[0] = (term[0]*(n % MOD)) % MOD;
          term[0] = (term[0]*8) % MOD;
        }
      else if (!(t%3))
        {
          term[0] = (t-1) % MOD;
          term[0] = (term[0]*((t/3) % MOD)) % MOD;
          term[0] = (term[0]*(n % MOD)) % MOD;
          term[0] = (term[0]*8) % MOD;
        }
      else if(!(n%3))
        {
          term[0] = (t-1) % MOD;
          term[0] = (term[0]*(t % MOD)) % MOD;
          term[0] = (term[0]*((n/3) % MOD)) % MOD;
          term[0] = (term[0]*8) % MOD;
        }
      
      /* calculate term2 */
      term[1] = (2*t) % MOD;
      term[1] = (term[1]*((t+1) % MOD)) % MOD;

      /* get and print a result */
      printf("%lld\n", (term[0]%MOD + term[1]%MOD - 3) % MOD);
    }
  return 0;
}
