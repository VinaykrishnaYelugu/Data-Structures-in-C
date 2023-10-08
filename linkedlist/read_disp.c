#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};

typedef struct node * sn;

sn read(sn);
void display(sn);
sn Createnode();

int n;

void main()
{
    int i;
    sn f=NULL ;
    printf("Enter the number of elements: \n"); scanf("%d",&n);
    f=read(f);
    display(f);
}

sn read(sn f)
{
  int i;
  sn tp=f,nn;
  for(i=1 ; i<=n ; i++)
  {
     nn = Createnode();
     printf("Enter the data %d: \n",i); scanf("%d",&nn->info);
     nn->link = NULL;
     if(f == NULL)
     {
       tp = nn;
       f = nn;
     }
     else
     {
       tp->link = nn;
       tp = tp->link;
     }
  }
  return f;
}

void display(sn f)
{
    int i;
    sn tp =f;
    if(f == NULL)
        printf("Array is empty\n");
    for(i=1 ; i<=n ; i++)
    {
        printf("Data %d - %d\n",i,tp->info);
        tp = tp->link;
    }
}
sn Createnode()
{
    sn nn = (sn)malloc(sizeof(struct node));
    return nn;
}