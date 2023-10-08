#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node * link;
};

typedef struct node * sn;

sn Read(sn);
void Display(sn);
sn Copy(sn,sn);
sn Createnode();

int n;

void main()
{
    sn f=NULL,fc;
    int ch,ch1;
    for( ;  ; )
    {
    printf("Enter choice\n1-Read\t2-Display\t3-Copy\t4-Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1 : f = Read(f); break;
        case 2 : 
                 printf("Enter the choice\n");
                 printf("10 for original\t20 for duplicate\n");
                 scanf("%d",&ch1);
                 if(ch1==10)
                   { Display(f); break; }
                 else
                  { Display(fc); break; }
        case 3 : 
                 fc = Copy(fc,f);
                 break;
        
        default: exit(0);
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

sn Copy(sn fc,sn f)
{
  int i=2;
  sn tp=f,nn,wn;
  printf("Copying the the elements in list-f to list-fc... \n");
    if(n==1)
    { 
       nn = Createnode();
       nn->link = NULL;
       fc = nn;
       fc->info = tp->info;
       return fc;
    }
    else
    {
       nn = Createnode();
       nn->link = NULL;
       nn->info = tp->info;
       fc = nn;
       
      while(tp->link != NULL)
      {
        wn = Createnode();
        wn->link = NULL;
        wn->info = (tp->link)->info;
        nn->link = wn;
        tp = tp->link;
        nn = wn;
      }

      return fc;
    }
}

sn Createnode()
{
  sn nn;
  nn = (sn)malloc(sizeof(struct node));
  return nn;
}