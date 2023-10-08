#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};

typedef struct node N;

void main()
{
    int n,i;
    N *ip,*cp;
    printf("Enter number of elements; \n");
    scanf("%d",&n);
    ip = (N *)malloc(sizeof(N));
    cp = ip;
    i=0;
    while(i<n)
    {
    printf("Enter the data %d : \t",i+1);
     scanf("%d",&cp->info);
    if(i<n-1)
    {
    cp->link = (N *)malloc(sizeof(N));
    cp = cp->link;
    }
    if(i==n-1)
    {
        cp->link = NULL;
    }
    i++;

    }
   
    i=0;
    for( ; ; )
    {
    printf("Data %d: %d\t",i+1,ip->info);
    ip = ip->link;
    if(ip==NULL)
      break;
      i++;
    }

}