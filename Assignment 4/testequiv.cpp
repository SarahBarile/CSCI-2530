#include <cstdio>
#include "equiv.h"
using namespace std;

int main()
{
  int i, j;

  printf("\nCreating four equivalence managers (e1, e2, e3, e4)\n");
  ER e1 = newER(10);
  ER e2 = newER(5);
  ER e3 = newER(10);
  ER e4 = newER(10);

  printf("Beginning tests.\n");
  printf("Only incorrect results are shown except for\n");
  printf("headings and four calls to showER.\n\n");
  printf("\nTests using e1\n");
  combine(e1, 4, 3);
  combine(e1, 3, 2);
  combine(e1, 2, 1);
  combine(e1, 6, 5);
  combine(e1, 7, 6);
  combine(e1, 8, 7);

  for(i = 1; i <= 4; i++) 
  {
    for(j = 1; j <= 4; j++) 
    {
      if(!equivalent(e1, i, j)) 
      {
        printf("e1(a): %d %d wrong\n", i, j);
      }
    }
  }

  for(i = 5; i <= 8; i++) 
  {
    for(j = 8; j <= 8; j++) 
    {
      if(!equivalent(e1, i, j))
      {
        printf("e1(b): %d %d wrong\n", i, j);
      }
    }
  }

  for(i = 5; i <= 10; i++)
  {
    if(equivalent(e1, 1, i))
    {
      printf("e1(c): 1 %d wrong\n", i);
    }
  }

  for(i = 1; i <= 9; i++)
  {
    if(equivalent(e1, 10, i))
    {
      printf("e1(d): 10 %d wrong\n", i);
    }
  }

  if(!equivalent(e1, 10, 10))
  {
    printf("e1(e): 10 10 wrong\n");
  }

  printf("e1(final):\n");
  showER(e1, 10);
  printf("\n\nTests using e2\n");
  combine(e2, 1, 5);
  combine(e2, 5, 5);
  combine(e2, 4, 4);
  combine(e2, 3, 4);

  if(!equivalent(e2, 1, 1)) printf("e2: 1 1 wrong\n");
  if(!equivalent(e2, 1, 5)) printf("e2: 1 5 wrong\n");
  if(equivalent(e2, 1, 4))  printf("e2: 1 4 wrong\n");
  if(equivalent(e2, 1, 2))  printf("e2: 1 2 wrong\n");
  if(!equivalent(e2, 4, 4)) printf("e2: 4 4 wrong\n");
  if(!equivalent(e2, 4, 3)) printf("e2: 4 3 wrong\n");

  printf("e2(final):\n");
  showER(e2, 5);

  printf("\n\nTests using e3\n");
  combine(e3, 1, 2);
  combine(e3, 3, 4);
  combine(e3, 1, 3);
  combine(e3, 6, 5);
  combine(e3, 8, 7);
  combine(e3, 5, 7);
  combine(e3, 1, 5);
  combine(e3, 9, 10);
  combine(e3, 10, 9);

  for(i = 1; i <= 8; i++)
  {
    for(j = 1; j <= 8; j++)
    {
      if(!equivalent(e3, i, j))
      {
        printf("e3(a): %d %d wrong\n", i, j);
      }
    }
  }
  if(!equivalent(e3, 9, 10))
  {
    printf("e3(b): 9 10 wrong\n");
  }
  if(equivalent(e3, 9, 8)) {
    printf("e3(c): 9 8 wrong\n");
  }

  printf("e3(final):\n");
  showER(e3, 10);

  printf("\n\nTests using e4\n");
  combine(e4, 4, 3);
  combine(e4, 2, 1);
  combine(e4, 4, 2);

  for(i = 1; i <= 4; i++)
  {
    for(j = 1; j <= 4; j++)
    {
      if(!equivalent(e4, i, j))
      {
        printf("e4(a): %d %d wrong\n", i, j);
      }
    }
  }

  combine(e4, 9, 8);
  combine(e4, 8, 7);
  combine(e4, 8, 6);
  combine(e4, 5, 6);

  for(i = 5; i <= 9; i++)
  {
    for(j = 5; j <= 9; j++)
    {
      if(!equivalent(e4, i, j))
      {
        printf("e4(b): %d %d wrong\n", i, j);
      }
    }
  }

  printf("e4(final):\n");
  showER(e4, 10);
  printf("\n");

  return 0; 
}