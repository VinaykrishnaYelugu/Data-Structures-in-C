#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node * link;
};

typedef struct node *sn;

void display(pl);
sn createnode();

sn insertrear(sn);

int n=0;

void main()
{
    int choice;
    sn pl;
    for( ; ;)
    {
        printf("Enter choice\n1-insertrear\nexit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: pl = insertrear(pl); display(pl); break;

            default : printf("Invalid!!\n");
        }
    }
}

sn createnode()
{
    sn nn=(sn)malloc(sizeof(struct node));
    return nn;
}

void display(sn pl)
{
    sn tp=pl;
    if(pl == 0)
    { printf("List Empty\n"); return ; }
    while (tp->link != pl);
    {
      tp = tp->link;
      printf("%d     ",tp->info);
    } 
      printf("%d     ",tp->link->info);
}