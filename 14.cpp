#include <cstdio>
#include <queue>

// #define MAX_NUM 50
#define MAX_NUM 5000001

using namespace std;

/* memoization
   initial state: mem[1] = 0
*/
int mem[MAX_NUM];
int maximum_value[MAX_NUM];
int maximum_idx[MAX_NUM];

inline void collatz(int num_idx);

int main()
{
  mem[2] = 1;
  mem[4] = 2;
  mem[8] = 3;

  queue <int> qu;
  qu.push(8);

  while (!qu.empty())
    {
      int idx_seq = qu.front();
      int temp_idx;
      qu.pop();

      temp_idx = idx_seq << 1;
      if (temp_idx < MAX_NUM)
        {
          mem[temp_idx] = mem[idx_seq] + 1;
          qu.push(temp_idx);
        }
      else 
        continue;

      if (!((idx_seq-1)%3)) {
          temp_idx = (idx_seq-1)/3;

          if ((temp_idx & 0x1) && temp_idx < MAX_NUM) {
              mem[temp_idx] = mem[idx_seq] + 1;
              qu.push(temp_idx);
          }
      }
    }

  for (int i = 3; i < MAX_NUM; ++i)
    {
      if (!mem[i])
        collatz(i);
    }

  for (int i = 1; i < MAX_NUM; ++i)
    {
      if (maximum_value[i-1] > mem[i])
        {
          maximum_value[i] = maximum_value[i-1];
          maximum_idx[i] = maximum_idx[i-1];
        }
      else
        {
          maximum_value[i] = mem[i];
          maximum_idx[i] = i;
        }
    }

  int t, n;
  scanf("%d", &t);
  for (int t_i = 0; t_i < t; ++t_i)
    {
      scanf("%d", &n);

      printf("%d\n", maximum_idx[n]);
    }

  return 0;
}

inline void collatz(int num_idx)
{
  int num_chain = 0;
  long long int cur_idx = num_idx;

  while (1)
    {
      if (cur_idx & 0x1) // cur_idx is odd number
        cur_idx = 3*cur_idx+1;
      else // cur_idx is even number
        cur_idx >>= 1;
      ++ num_chain;

      // condition for exit
      if (cur_idx < MAX_NUM /* condition for mem-idx, 1 <= cur_idx is unnecessary */ 
          && mem[cur_idx])
        {
          mem[num_idx] = num_chain + mem[cur_idx];
          break;
        }
    }
}
