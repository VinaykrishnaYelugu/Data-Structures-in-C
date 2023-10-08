#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};

typedef struct node * sn; 
sn Createnode();
sn Exchange(sn,sn,sn);
void Display(sn);

int n;

void main()
{ 
  int run;
    int l,k,j,i;
    sn f=NULL,nn,tp;
    printf("Enter the number of elements:   "); scanf("%d",&n);
    sn p[n];
    if(n==0)
      {  return ; }
  for( ; ;)
  { 
    printf("Enter value of run : \n1-run\n-1 to stop\n"); scanf("%d",&run);
    if(run==-1)
        exit (0);
  tp=f;
  for(i=1 ; i<=n ; i++)
  {
     nn = Createnode();
     p[i-1] = nn;
     printf("Enter the data %d: \t",i); scanf("%d",&nn->info);
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
    tp = f;
    if(f == NULL)
        printf("Array is empty\n");

    printf("Enter 2 valid choice of address of respective element\n");
    for(i=1 ; i<=n ; i++)
    {
        printf(" %d for -> Address of %d\n",i,tp->info);
        tp = tp->link;
    }
    scanf("%d%d",&k,&l);
    printf("%d\n%d\n",p[k-1]->info,p[l-1]->info);
    printf("Before\n");
    Display(f);
    f = Exchange(f,p[k-1],p[l-1]);
    printf("After\n");
    Display(f);
  }
}
sn Createnode()
{
    sn nn = (sn)malloc(sizeof(struct node));
    return nn; 
}
sn Exchange(sn f,sn n1, sn n2)
{
  sn tp=f,ep,cp;

  if(tp != n1)
  {
    while(tp->link != n1)
      tp = tp->link;
    tp->link = (tp->link)->link;

     while(tp->link != n2)
       tp = tp->link;
     tp->link = (tp->link)->link;

     if(n1->link != n2)
     { 
       ep = n1->link;
       n1->link = n2->link;
       n2->link = ep;
       tp = f;
       while(tp->link != n2->link)
       tp = tp->link;
       tp->link = n2;

       while(tp->link != n1->link)
          tp = tp->link;
       tp->link = n1;
     }
    else
    {
      n1->link = n2->link;
      n2->link = n1; 
      tp =f;
      while(tp->link != n1->link)
        tp = tp->link;
      tp->link = n2;
    }
  }
 if(tp == n1)
  {
  if(n1->link != n2)
  { 
    while(tp->link != n2)
       tp = tp->link;
    tp->link = (tp->link)->link;

    ep = n1->link;
    n1->link = n2->link;
    n2->link = ep;

     tp->link = n1;
     f = n2;
   }
   else
    {
      n1->link = n2->link;
      n2->link = n1; 
      f =n2;
   printf("(:-)) \n");
    }
  }
  return f;
 }
void Display(sn f)
{
    sn tp = f;
    int i;
    if(f == NULL)
        printf("Array is empty\n");
    for(i=1 ; i<=n ; i++)
    {
        printf(" Data %d -> %d\t",i,tp->info);
        tp = tp->link;
    }
    printf("\n");
}