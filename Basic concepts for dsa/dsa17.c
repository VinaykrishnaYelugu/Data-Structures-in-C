#include<stdio.h>
#define N 3

int add(int,int);
int sub(int,int);
int mul(int,int);

void main()
{
    int a,b,i,(*ptr[N])(int,int)={ &add, &sub, &mul};
    printf("Enter 2 numbers: \n");
    scanf("%d%d",&a,&b);

    for(i =0 ;i<N ; i++)
    printf("Result : %d\n%d\n",ptr[i](a,b),(*ptr[i])(a,b) );
}

int add(int x,int y)
 { return x+y ; }

int sub(int x,int y)
{ return x-y ; }

int mul(int x,int y)
{ return x*y ; }