#include <stdio.h>
#include <stdlib.h>

void num_to_word(long long int, int);
int oneth_number(int num);
int tenth_number(int num);

#define ERROR_MSG(fmt, ... ) { fprintf(stderr, fmt, ##__VA_ARGS__); exit(1); }


int main()
{
  int t;
  scanf("%d", &t);

  for (int t_i =0; t_i < t; ++ t_i)
    {
      long long int num;
      scanf("%lld", &num);

      if (num)
        {
          num_to_word(num, 0);
          printf("\n");
        }
      else
        printf("Zero\n");
    }

  return 0;
}

void num_to_word(long long int num, int depth)
{
  if (num/1000)
    num_to_word(num/1000, depth+1);

  int print_flag = 0;

  print_flag = oneth_number((num % 1000) / 100);
  if (print_flag)
    printf("Hundred ");
  print_flag |= tenth_number(num % 100);

  if (print_flag)
    {
      switch (depth)
        {
        case 0:
          break;
        case 1:
          printf("Thousand ");
          break;
        case 2:
          printf("Million ");
          break;
        case 3:
          printf("Billion ");
          break;
        case 4:
          printf("Trillion ");
          break;
        default: ERROR_MSG("\n\n------  Error lineno: %d  -----\n\n", __LINE__);
        }
    }
}

int oneth_number(int num)
{
  switch (num)
    {
    case 0: return 0;
    case 1: printf("One ");   break;
    case 2: printf("Two ");   break;
    case 3: printf("Three "); break;
    case 4: printf("Four ");  break;
    case 5: printf("Five ");  break;
    case 6: printf("Six ");   break;
    case 7: printf("Seven "); break;
    case 8: printf("Eight "); break;
    case 9: printf("Nine ");  break;
    default: ERROR_MSG("\n\n------  Error lineno: %d  -----\n\n", __LINE__);
    }
  return 1;
}

int tenth_number(int num)
{
  int print_flag = 1;
  if (num/10 == 1)
    {
      switch (num%10)
        {
        case 0: printf("Ten ");       break;
        case 1: printf("Eleven ");    break;
        case 2: printf("Twelve ");    break;
        case 3: printf("Thirteen ");  break;
        case 4: printf("Fourteen ");  break;
        case 5: printf("Fifteen ");   break;
        case 6: printf("Sixteen ");   break;
        case 7: printf("Seventeen "); break;
        case 8: printf("Eighteen ");  break;
        case 9: printf("Nineteen ");  break;

        default: ERROR_MSG("\n\n------  Error lineno: %d  -----\n\n", __LINE__);
        }
    }
  else
    {
      switch (num/10)
        {
        case 0: print_flag = 0; break;
        case 2: printf("Twenty ");  break;
        case 3: printf("Thirty ");  break;
        case 4: printf("Forty ");  break;
        case 5: printf("Fifty ");   break;
        case 6: printf("Sixty ");   break;
        case 7: printf("Seventy "); break;
        case 8: printf("Eighty ");  break;
        case 9: printf("Ninety ");  break;

        case 1:
        default: ERROR_MSG("\n\n------  Error lineno: %d  -----\n\n", __LINE__);
        }
      print_flag |= oneth_number(num % 10);
    }
  return print_flag;
}
