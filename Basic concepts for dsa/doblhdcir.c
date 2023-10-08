#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int info;
    struct Node *ll;
    struct Node *rl;
};

typedef struct Node * node;

void insertfront(node);
void insertrear(node);
void deletefront(node);
void deleterear(node);
void insertbypos(node);
void deletebypos(node);
void insertbyorder(node);
void deletebykey(node);
void sort(node);
int search(node);
void reverse(node);

node createnode();
void display(node);

int x;

void main()
{
    int choice,flag;
    node hd = createnode();
    hd->ll = hd;
    hd->rl = hd;
    hd->info = 0;
    for( ;  ; )
    {
        printf("Enter the choice\n1-Insert front\n2-Insert rear\n3-Delete front\n4-Delete rear\n5-Insert by position\n");
        printf("6-Delete by position\n7-Insert by order\n8-Delete by key\n9-sort\n10-Search\n11-Reverse\nexit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insertfront(hd);  display(hd);  break;
            case 2: insertrear(hd);  display(hd); break;
            case 3: deletefront(hd); display(hd); break;
            case 4: deleterear(hd); display(hd); break;
            case 5: insertbypos(hd); display(hd); break;
            case 6: deletebypos(hd); display(hd); break; 
            case 7: insertbyorder(hd); display(hd); break;
            case 8: deletebykey(hd); display(hd); break; 
            case 9: sort(hd); display(hd); break;
            case 10: flag = search(hd); 
                     if(flag == -1)
                        printf("Element not found in the list\n");
                     else
                        printf("Element %d is present at %d\n",x,flag);
                     break;
            case 11: reverse(hd); display(hd); break;

            default: printf("Invalid\n");  exit(0); 
        }
    }
}

node createnode()
{
    node nn = (node)malloc(sizeof(struct Node));
    return nn;
}

void display(node ph)
{
    node tp = ph->rl;
    if(ph->info == 0)
      { printf("List is empty\n"); return; }
    printf("List is : \n");
    while(tp != ph)
    {
       printf("%d     ",tp->info);
       tp = tp->rl; 
    }
    printf("\n");
}

void insertfront(node ph)
{
  node tp,nn;
  nn = createnode();
  printf("Enter the new element : "); scanf("%d",&nn->info);
  tp = ph->rl;

  ph->rl = nn;
  nn->rl = tp;
  nn->ll = ph;
  tp->ll = nn;

  ph->info++;
}

void insertrear(node ph)
{
    node tp,nn;
    nn = createnode();
    printf("Enter the new element:  "); scanf("%d",&nn->info);
    tp = ph->ll;

    tp->rl = nn;
    nn->ll = tp;
    nn->rl = ph;
    ph->ll = nn;

    ph->info++;
}

void deletefront(node ph)
{
    node tp,dp;
    if(ph->info == 0)
        return ;  
    printf("Deleting %d...\n",ph->rl->info);
    tp = ph->rl;
    
    ph->rl = tp->rl;
    ph->rl->ll = ph;

    tp->rl = tp->ll = NULL;
    free(tp);

    ph->info--;
}

void deleterear(node ph)
{
    node tp;
    if(ph->info == 0)
         return; 
    printf("Deleting %d...\n",ph->ll->info);

    tp = ph->ll;

    ph->ll = tp->ll;
    tp->ll->rl = ph;

    ph->info--;
}

void insertbypos(node ph)
{
    node tp=ph,nn,ep;
    int i,pos;
    nn = createnode();
    printf("Enter the new element:  "); scanf("%d",&nn->info);
    do
    { printf("Enter them position from 1 to %d : \n",ph->info+1); scanf("%d",&pos);  }
    while (pos<1 || pos>ph->info+1);
    for(i=1 ; i<=pos-1 ; i++)
            tp = tp->rl;
    ep = tp->rl;

    nn->rl = tp->rl;
    tp->rl = nn;
    nn->ll = tp;
    ep->ll = nn;

    ph->info++;
}

void deletebypos(node ph)
{
    node tp=ph,ep;
    int i,pos;
    if(ph->info == 0)
         return;
    do
    { printf("Enter the position from 1 to %d\n",ph->info); scanf("%d",&pos); }
    while(pos<1 || pos>ph->info);
    printf("Deleting %d...\n",tp->rl->info);
    for(i=1 ; i<=pos-1 ; i++)
            tp = tp->rl;
    ep = tp->rl;

    tp->rl = ep->rl;
    ep->rl->ll = tp;
 
    ep->rl = ep->ll = NULL;
    free(ep);
    ph->info--;
}

void insertbyorder(node ph)
{
    node tp=ph,nn,ep;
    if(ph->info == 0)
       { printf("List is empty\n"); insertfront(tp); return; }
    nn = createnode();
    printf("Enter the new element :  "); scanf("%d",&nn->info);

    while(tp->rl->info < nn->info)
      {
       tp = tp->rl;
       if(tp->rl == ph)
         break;
      }

    ep = tp->rl;

    tp->rl = nn;
    nn->rl = ep;
    nn->ll = tp;
    ep->ll = nn; 

    ph->info++;
}

void deletebykey(node ph)
{
    node tp=ph,ep;
    int key;
    if(ph->info == 0)
     { printf("List is empty\n"); return; }
  L1:
    printf("Enter the valid key element:  "); scanf("%d",&key);

    while(tp->rl->info != key)
    {
        tp = tp->rl;
        if(tp->rl == ph)
          { printf("Entered element is not present in the list\n");  goto L1; }
    }

    ep = tp->rl;
 
    tp->rl = ep->rl;
    ep->rl->ll = tp;

    ep->rl=ep->ll=NULL;
    free(ep);
    ph->info--;
}

void sort(node ph)
{
    int i,j,temp;
    node tp;
    if(ph->info == 0)
      return ;
    for(i=0 ; i<ph->info ; i++)
    {
      tp = ph->rl;
      for(j=0 ; j<ph->info-1-i ; j++)
      {
        if(tp->rl->info < tp->info)
        {
            temp = tp->info;
            tp->info = tp->rl->info;
            tp->rl->info = temp;

            tp = tp->rl;
        }
      }
    }
}

int search(node ph)
{
   int i=1;
   node tp=ph;
   printf("Enter the element to be searched:  "); scanf("%d",&x);
   while(tp->rl->info != x)
     {
         tp = tp->rl;
         if(tp->rl == ph)
            { return -1; }
         i++;
     }
   return i;
}

void reverse(node ph)
{
    int temp,cnt;
    node sp=ph->rl,ep=ph->ll;
    for(cnt =1 ; cnt < (ph->info/2) ; cnt++)
    {
        temp = sp->info;
        sp->info = ep->info;
        ep->info = temp;

        sp = sp->rl;
        ep = ep->ll;
    }
}