#include<stdio.h>

void main()
{
  int x,*p1,*p2,*p3;
  p1 = &x;
  printf("Reading x using pointers p1: \n");
  scanf("%d",p1);
  printf("Displaying x using pointers p1: \n");
  printf("%d\n",*p1);
  
  p2 = &x;
  printf("Reading x using pointer p2: \n");
  scanf("%d",p2);
  printf("Displaying x using pointer p2: \n");
  printf("%d\n",*p2);

  p3 = &x;
  printf("Reading x using pointer p3: \n");
  scanf("%d",p3);
  printf("Displaying x using pointer p3: \n");
  printf("%d\n",*p3);
  
  return ;
}