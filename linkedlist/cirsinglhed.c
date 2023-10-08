#include<stdio.h>
#include<stdlib.h>

struct NODE
{
    int info;
    struct NODE *link;
};

typedef struct NODE * node;

node createnode();
void display(node);
void insertbypos(node);
void deletebypos(node);
void insertbyorder(node);
void deletebykey(node);
int search(node);
void sort(node);

int k; 

void main()
{
    node hd = createnode();
    hd->info = 0;
    hd->link = hd;
    int choice,index;
    for(;;)
    {
        printf("Enter the choice\n"); 
        printf("1-Insert by position\n2-Delete by positon\n3-Insertbyorder\n4-Delete by key\n5-Search\n6-Sort\nExit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : insertbypos(hd) ; display(hd); break;
            case 2 : deletebypos(hd) ; display(hd); break;
            case 3 : insertbyorder(hd); display(hd); break;
            case 4 : deletebykey(hd); display(hd); break;
            case 5 : index = search(hd); 
                     if(index == -1)
                      { printf("Element not found"); }
                     else
                       printf("%d is in list,at position %d\n\n",k,index);
                     break;
            case 6 : sort(hd); display(hd); break;

            default : printf("Invalid\n"); exit(0);
        }
    }
}

node createnode()
{
    node nn = (node)malloc(sizeof(struct NODE));
    return nn;
}

void display(node hd)
{
  node tp=hd;
  if(hd->info==0)
    { printf("List Empty\n"); return ; }
  printf("Elements are : \n");
  tp = tp->link;
  while(tp->link != hd)
  {
    printf("%d     ",tp->info);
    tp = tp->link;
  }
    printf("%d     ",tp->info);
    printf("\n\n");
}

void insertbypos(node hd)
{
  node nn,tp=hd;
  int i,pos;
  nn = createnode();
  printf("Enter the new item: \n"); scanf("%d",&nn->info);
  nn->link = NULL;
  do
  {
    printf("Enter the position from 1 to %d\n",hd->info+1); scanf("%d",&pos);
  } while (pos<1 || pos>hd->info+1);
  for( i =1 ; i<=pos-1 ; i++)
    tp = tp->link;
  nn->link = tp->link;
  tp->link = nn;
  hd->info++;
}

void deletebypos(node hd)
{
    node tp=hd,dp;
    int i,pos;
    if(hd->info == 0)
     { return ; }
    do
    {
      printf("Enter the position from 1 to %d\n",hd->info); scanf("%d",&pos);
    } while(pos<1 || pos>hd->info);
    for(i=1 ; i<=pos-1 ; i++)
        tp =tp->link;
    dp = tp->link;
    tp->link = tp->link->link;
    free(dp);
    hd->info--;
}

void insertbyorder(node hd)
{
  node nn,tp=hd;
  nn = createnode();
  nn->link = NULL;
  printf("Enter the new element: \n"); 
  scanf("%d",&nn->info);
  if(hd->info==0)
    { nn->link = tp->link; tp->link = nn ; hd->info++;  return; }
  while(tp->link->info < nn->info)
     {
         tp = tp->link;
         if(tp->link==hd)
           break;
     }
  nn->link = tp->link;
  tp->link = nn;
  hd->info++;
}

void deletebykey(node hd)
{
    node tp=hd,dp;
    int key;
    if(hd->info == 0)
      { return ; }
   L0:
    tp = hd;
    printf("Enter valid key element: \n"); scanf("%d",&key);
    while(tp->link->info != key)
        {
           tp = tp->link;
           if(tp->link == hd)
             {  goto L0; }
        }
    dp = tp->link;
    tp->link = tp->link->link;
    free(dp);
    hd->info--;
}

int search(node hd)
{
  node tp = hd;
  printf("Enter the element to be serached: \n"); scanf("%d",&k);
  int i;
  tp = tp->link;
  for(i=1 ; i<=hd->info ; i++)
  {
    if(tp->info == k)
      { return i; }
    tp = tp->link;
    if(tp == hd)
       { return -1; }
  }
}

void sort(node hd)
{
  node tp = hd;
  int i,j,temp;
  for(i=0 ; i<hd->info ; i++)
  {
    tp = hd->link;
    for(j=0 ; j<hd->info-1-i ; j++)
    {
      if(tp->info > tp->link->info)
      {
         temp = tp->info;
         tp->info = tp->link->info;
         tp->link->info = temp;
         tp = tp->link;
      }
    }
  }
}