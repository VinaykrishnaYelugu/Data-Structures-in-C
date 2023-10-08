#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};

typedef struct node *sn;

sn Read(sn);
void Display(sn);
sn Reverse(sn);
sn Createnode();

int n;

void main()
{
    sn f=NULL;
    int ch;
    for( ; ; )
    {
        printf("Enter choice\n1-Read\t2-Display\t3-Reverse\t4-Exit\n"); 
        scanf("%d",&ch);
        switch(ch)
        {
           case 1:
               f = Read(f); break;
           case 2:
               Display(f); break;
           case 3:
               f = Reverse(f); break;

           default :
                exit(0);
        }
    }
}

sn Read(sn f)
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

void Display(sn f)
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

sn Reverse(sn wn)
{
    printf("Reversing...\n");
    sn tn= wn,cn;
    if(n==0)
      { printf("Array is empty\n"); return wn; }
    if(n==1)
       return wn;
    wn = wn->link;
    tn->link =NULL;
    while(wn->link != NULL)
    {
        cn = wn;
        wn = wn->link;
        cn->link = tn;   /*  cn->link = NULL;  cn->link = tn;   i.e, same as cn->link=tn  */
        tn = cn;
    }
    wn->link = tn;
    return wn;
}

sn Createnode()
{
    sn nn = (sn)malloc(sizeof(struct node));
    return nn; 
}
