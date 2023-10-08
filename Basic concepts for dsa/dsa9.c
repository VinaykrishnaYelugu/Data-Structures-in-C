#include<stdio.h>

void swap(int ,int ,int );

void main()
{
    int a,b,c;
    printf("Enter 3 values :\n");
    scanf("%d%d%d",&a,&b,&c);

    swap(a,b,c);

    printf("Printing in MAIN function: \n%d\t%d\t%d",a,b,c);
    return ;
}

void swap(int a,int b,int c)
{
    int t;
    t = a;
    a = b;
    b = c;
    c = t;
    printf("Printing in SWAP function : \n%d\t%d\t%d\n",a,b,c);
    return ;
}