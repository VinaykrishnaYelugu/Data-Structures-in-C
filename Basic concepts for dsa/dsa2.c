#include<stdio.h>

void main()
{

  int a,b,c,*p;
  p = &a;
  printf("Reading a using pointer: \n"); scanf("%d",p);
  printf("Displaying a using pointer p:\n"); printf("%d\n",*p);

  p = &b;
  printf("Reading b using pointer: \n"); scanf("%d",p);
  printf("Displaying b using pointer p: \n"); printf("%d\n",*p);

  p = &c;
  printf("Reading c using pointer: \n"); scanf("%d",p);
  printf("Displaying c using pointer p: \n"); printf("%d\n",*p);

  return ;
}
  