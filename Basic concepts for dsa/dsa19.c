#include<stdio.h>
#include<stdlib.h>
void main()
{
  int n,i;
  printf("Eter number of integers: \n");
  scanf("%d",&n);

  //allocating memory
  int *ptr= (int*)malloc(n*sizeof(int));

  if(ptr == NULL)
  {
    printf("Memory is full:\n");
  }

  printf("Enter integers : \n");
  for(i=0 ; i<n ; i++)
    scanf("%d",ptr+i);
  printf("Entered integers : \n");
  for(i=0 ;i < n; i++)
    printf("%d\t",*(ptr+i));

}