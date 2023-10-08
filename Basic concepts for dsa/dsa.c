#include<stdio.h>

void main()
{

  int a,*p;
  p = &a;
  printf("Reading a using pointer: \n");
  scanf("%d",p);
  printf("Address of a :\n");
  printf("%d\n",p);
  printf("Value stored in p: \n");
  printf("%d\n",p);
  printf("Value of x using pointer: \n");
  printf("%d",*p);

  return ;
}
  