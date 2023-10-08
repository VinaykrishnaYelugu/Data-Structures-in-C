#include<stdio.h>

int * large(int *, int*);

void main()
{
    int a,b,*p;
    printf("Enter two numbers: \n");
    scanf("%d%d",&a,&b);
    p = large(&a,&b);
    
    printf("Largest of two numbers %d and %d is : %d",a,b,*p);
    return ;
}

int * large(int *p,int *q)
{
    int *m;
    m = (*p>*q)?  p : q ;
    return m ;
}