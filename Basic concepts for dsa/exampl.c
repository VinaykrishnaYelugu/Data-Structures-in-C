#include<stdio.h>
#include<stdlib.h>

void main()
{
  int m,n,*p,*q,i;
  printf("Enter nomber of rows: \n"); scanf("%d",&m);
  printf("Enter number of colums: \n"); scanf("%d",&n);
  int a[m][n];
  p = &a[0][0];
  q=p;
  for(q=p ; q!=(p+m*n) ; q++)
   { scanf("%d",q); }
  for(q=p ; q!=(p+m*n) ; )
  {
  for(i=0 ; i<n ; i++)
   { 
    printf("%d\t",*q); q++;
   }
   printf("\n");
  }
}