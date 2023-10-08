#include<stdio.h>
#include<stdlib.h>

struct NODE
{
  int info;
  struct NODE * link;
};

typedef struct NODE * node;

node insertrear(node);
node insertfront(node);
node deleterear(node);
node deletefront(node);
node insertbypos(node);
node deletebypos(node);
node insertbyorder(node);
node deletebykey(node);
void Sort(node);
int Search(node);
node copy(node);
node reverse(node);

void display(node);
node createnode();

int n=0,k ;

void main()
{
  node lp=NULL,r,c;
  int ch,flag;
  for( ; ; )
  {
   printf("Enter the choice : \n");
   printf("1-insert rear\n2-insert front\n3-delete rear\n4-delete front\n5-insert by position\n6-delete by pos\n7-insert by order\n");
   printf("8-delete by key\n9-Sort\n10-Search\n11-Copy\n12-Reverse\nexit\n");
   scanf("%d",&ch);
   switch(ch)
   {
    case 1 : lp = insertrear(lp); display(lp); break;
    case 2 : lp = insertfront(lp) ; display(lp); break;
    case 3 : lp = deleterear(lp); display(lp); break;
    case 4 : lp = deletefront(lp); display(lp); break;
    case 5 : lp = insertbypos(lp); display(lp); break;
    case 6 : lp = deletebypos(lp); display(lp); break;
    case 7 : lp = insertbyorder(lp); display(lp); break;
    case 8 : lp = deletebykey(lp); display(lp); break;
    case 9 : Sort(lp); display(lp); break;
    case 10: flag = Search(lp);
              if(flag == -1)
                printf("Element %d not found\n",k);
              else
                 printf("Element %d is found at position %d\n",k,flag);      
              break;      
    case 11:  c = copy(lp) ; display(c); break;
    case 12:  r = reverse(lp); display(r); break;

    default : printf("Invalid choice!!\nProg Terminated\n"); exit (0);
   }
  }
}

node insertrear(node lp)
{
  node nn;
  nn = createnode();
  nn->link = NULL;
  printf("Enter new element: \n"); scanf("%d",&nn->info);
  if(lp == NULL)
   {  nn->link = nn; n++; return nn; }
  nn->link = lp->link;
  lp->link = nn;
  n++;
  return nn;
}

node insertfront(node lp)
{
  node nn;
  nn=createnode();
  nn->link = NULL;
  printf("Enter new element: \n"); scanf("%d",&nn->info);
  if(lp == NULL)
   { nn->link = nn; n++;  return nn; }
  nn->link = lp->link;
  lp->link = nn;
  n++;
  return lp;
}

node deleterear(node lp)
{
  node tp=lp,ep;
  if(tp==NULL)
    { printf("List Empty\n"); return tp; }
  if(tp->link == tp)
    { tp = NULL ; n--; return tp; }
  while(tp->link != lp)
       tp = tp->link;

  ep = tp->link;
  tp->link = ep->link;
  ep->link = NULL;
  free(ep);
  n--;
  return tp;
}

node deletefront(node lp)
{
  node tp=lp,ep;
  if(tp==NULL)
    { printf("List Empty\n"); return tp; }
  if(tp->link == tp)
    { tp = NULL ; n--; return tp; }
  ep = tp->link;
  tp->link = ep->link;
  ep->link = NULL;
  free(ep);
  n--;
  return tp;
}

node insertbypos(node lp)
{
  node tp=lp,nn;
  int i,pos;

  do
  { printf("Enter the position from 1 to %d\n",n+1); scanf("%d",&pos); }
  while(pos<1 || pos>n+1);

  nn = createnode();
  nn->link = NULL;
  printf("Enter new element: \n"); scanf("%d",&nn->info);

  if(tp==NULL)
   { nn->link = nn;  n++;  return nn;  }
  
  for(i=1 ; i<=pos-1 ; i++)
    tp = tp->link;
  nn->link = tp->link;
  tp->link = nn;
  if(pos==n+1)
    { n++; return nn; }
  n++;
  return lp;
}

node deletebypos(node lp)
{
  node tp=lp, ep;
  int i,pos;
  if(tp==NULL)
   { printf("List Empty\n"); return tp; }
  do
  { printf("Enter the positon from 1 to %d\n",n); scanf("%d",&pos); }
   while (pos<1 || pos>n);

  if(tp->link == tp)
    { tp = NULL;    n--;    return tp;  }
  else
 {
  for(i=1 ; i<=pos-1 ; i++)
       tp = tp->link;
  ep = tp->link;
  tp->link = ep->link;
  ep->link = NULL;
  free(ep);
  if(pos == n)
    { n--; return tp; }
  n--;
  return lp;
 }
}

node insertbyorder(node lp)
{
  node tp=lp,nn;
  int flag=1;
  nn = createnode();
  nn->link = NULL;
  printf("Enter the new element: \n"); scanf("%d",&nn->info); 
  while(tp->link->info < nn->info)
    {
      tp = tp->link;
      if(tp == lp)
        { flag=-1; break; }
    }
  nn->link = tp->link;
  tp->link = nn;
  n++;
  if(flag==-1)
     return nn;
  return lp;
}

node deletebykey(node lp)
{
  node tp=lp,ep;
  int key,flag=1;
  if(tp == NULL)
    return tp ;
L1:
  printf("Enter the valid key element: \n"); scanf("%d",&key);
  while(tp->link->info != key)
   {
    tp = tp->link;
    if(tp==lp)
     { printf("Element is not present in list\n"); goto L1; }
   }
  if(tp->link == tp)
     { tp = NULL;   n--;   return tp;  }

  if(tp->link == lp)
      flag=-1;

  ep = tp->link;
  tp->link = ep->link;
  ep->link = NULL;

  free(ep);
  n--;
  if(flag == -1)
      return tp; 
  return lp;
}

int Search(node lp)
{
  node tp=lp,ep;
  int i=1,flag=-1;
  printf("Enter element to be searched: \n"); scanf("%d",&k);
  tp = tp->link;
  while(tp->info != k)
     {
     if(tp==lp)
      { flag = 1 ; break; }
     tp = tp->link;
     i++;
     }
  if(flag == 1)
      return -1;  
  else
     return i;
}

void Sort(node lp)
{
  node tp=lp,ep;
  int i,j,temp;
  for(i=0 ; i<n ; i++)
  {
    tp = lp;
    for(j=0 ; j<n-1-i ; j++)
    {
      tp = tp->link;
      if(tp->info > tp->link->info)
        {
          temp = tp->info;
          tp->info = tp->link->info;
          tp->link->info=temp;
        }
    }
  }
}

node copy(node lp)
{
  int i=1;
  node tp=lp,nn,tn;
  if(lp==NULL)
     return lp;
     
  for( ; ; )
  {
    tp = tp->link;
    nn = createnode();
    nn->info = tp->info ;
    if(i==1)
    {
    nn->link = nn;
    tn = nn;
    }
    else
    {
    nn->link = tn->link;
    tn->link = nn;
    tn = nn;
    }
    if(tp == lp)
       return nn;
    i++;
  }
}

node reverse(node tp)
{
  int i=1;
  node ep,cp,lp0;
  if(tp == NULL)
     return tp;
  for( ; ; )
  {
   ep = tp->link;
   tp->link =ep->link;
   ep->link = NULL;
   if(i==1)
   {
    ep->link = ep;
    lp0 = ep;
    cp = ep;
   }
   else
   {
   lp0->link = ep;
   ep->link = cp;
   cp = ep;
   }
   if(cp == tp)
     return lp0;
   i++;
  }
}
void display(node lp)
{
  node tp=lp;
  if(lp == NULL)
   { printf("List is Empty\n"); return ; }
  while(tp->link != lp)
  {  
    tp = tp->link;
    printf("%d     ",tp->info);
  }
  tp = tp->link;
  printf("%d     ",tp->info);
  printf("\n");
} 

node createnode()
{
  node nn = (node)malloc(sizeof(struct NODE));
  return nn;
}