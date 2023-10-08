#include<stdio.h>

void Read(int *);
void Dspla(int *);
int comp(int *,int *);

int n;

void main()
{
    int A[10],B[10];
    printf("Enter number os array elements: \n");
    scanf("%d",&n);

    printf("Enter array A elements: \n");
    Read(A);
    printf("Enter array B elements: \n");
    Read(B);
    printf("Array A elements: \n");
    Dspla(A);
    printf("Array B elements:\n");
    Dspla(B);
    
    //COMPARING
    if(comp(A,B)==1)
       printf("Both A and B arrays are same\n");
    else
       printf("Arrays A and B are not same:\n");

    return ;
}

void Read(int *p)
{
  int i;
  for(i=0 ; i<n ; i++)
    scanf("%d",p+i);
  return ;
}

void Dspla(int *p)
{
    int i;
    for(i=0 ; i<n ;i++)
     printf("%d\t",*(p+i));
    printf("\n");
    return ;
}

int comp(int *p,int *q)
{
   int i;
   for(i=0 ; i<n ; i++)
        if(*(p+i)!=*(q+i))
           return -1;
    return 1;
}