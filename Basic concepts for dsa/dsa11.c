#include<stdio.h>

void Read(int *);
void Dis(int *);

int n;

void main()
{
    int A[10];
    printf("Enter number of array elements: \n");
    scanf("%d",&n);
    printf("Enter elements of the array : \n"); 
    Read(A);
    printf("Entered elements: \n");
    Dis(A);

    return ;
}

void Read(int *p)
{   
    int i;
    for(i=0 ; i< n ; i++)
     scanf("%d",p+i);
}

void Dis(int *p)
{
    int i;
    for(i=0 ; i<n; i++)
      printf("%d\t",*(p+i));
}