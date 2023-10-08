#include<stdio.h>
void main()
{
  int *p,*q,*s,i,j,r,c;
  printf("Enter array size: \n");
  scanf("%d%d",&r,&c);
  int a[r][c];
  
  //INDEXING
 /* printf("Enter array elements: \n");
  for(i=0 ; i<r ; i++)
    for(j=0 ; j<c ; j++)
      scanf("%d",&a[i][j]);
  printf("Array elements: \n");
  for(i=0 ; i<r ; i++)
   { for(j=0 ; j<c ; j++)
      printf("%d\t",a[i][j]);
       printf("\n"); } */
   
  //POINTER ACCESSING BY KEEPING POINTER CONSTANT
   s=&a[0][0];
  /* p=s;
   printf("Enter array elements: \n");
   for(i=0 ; i<r ; i++)
    for(j=0 ; j<c ; j++)
      scanf("%d",p+i*c+j);
   printf("Array elements are :\n");
   for(i=0 ; i<r ; i++)
    { for(j=0 ; j<c ; j++)
       printf("%d\t",*(p+i*c+j));
       printf("\n"); } */

  //POINTER ACCESSING BY VARYING POINTER VALUE
   printf("Enter array elements: \n");

   for(q=s ; q<s+r*c ; q=q+c)
     for(p=q ; p< q+c ; p++)
      scanf("%d",p);
   printf("Array elements are : \n");
    q=s;
     for(q ; q<s+r*c ; q=q+c)
      { 
        for(p=q ; p<q+c ; p++)
        printf("%d\t",*p);
        printf("\n");
      }
/*
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
*/
return ;
}