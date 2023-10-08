#include<stdio.h>
#include<stdlib.h>

struct NODE 
{
    int info;
    struct NODE *ll;
    struct NODE *rl;
};

typedef struct NODE * node;

node createnode();
void display(node);
void insertrear(node);
void insertleftofk(node,int);
void insertrightofk(node,int);
int insertleftofkey(node,int);
void deletesuccesser(node,int);
void deletepredeccesser(node,int);

void main()
{
  int choice,pos,key,flg;
  node hd;
  hd = createnode();
  hd->ll = hd->rl = hd;
  hd->info = 0;
  for( ; ; )
  {
    printf("Enter the valid choice\n");
    printf("1=Insert rear\n2=Insert left of kth node\n3=Insert right of kthnode\n4=Insert left of key\n");
    printf("5=Delete successer of kth node\n6=Delete predecceser of kth node\nExit\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1 : insertrear(hd); display(hd); break;
        case 2 : do
                 {  printf("Enter the position from 1 to %d: \n",hd->info); scanf("%d",&pos); }
                 while(pos<1 || pos>hd->info);
                 insertleftofk(hd,pos); display(hd); break;
        case 3 :do
                {
                { printf("Enter the position from 1 to %d: \n",hd->info); scanf("%d",&pos); }  
                } while (pos<1 || pos>hd->info);
                insertrightofk(hd,pos); display(hd); break;
        case 4 :do
                {
                  printf("Enter the valid key\n"); scanf("%d",&key); 
                  flg = insertleftofkey(hd,key);
                }while(flg == -1);
                 display(hd); break;
        case 5 :do
                {
                  printf("Enter positon from 1 to %d: \n",hd->info); scanf("%d",&pos);
                } while (pos<1 ||pos>hd->info);
                deletesuccesser(hd,pos);
                display(hd); break;
        case 6 :do
                {
                  printf("Enter positon from 1 to %d: \n",hd->info); scanf("%d",&pos);
                } while (pos<1 || pos>hd->info);
                deletepredeccesser(hd,pos);
                display(hd); break;
        
        
        default : printf("Invalid\n\n"); exit(0);
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
    if(hd->info == 0)
    { printf("List is empty\n"); return ; }
    printf("Elements in list are: \n");
    tp = tp->rl;
    while(tp != hd)
    {
        printf("%d     ",tp->info);
        tp = tp->rl;
    }
    printf("\n\n");
}

void insertrear(node hd)
{
    node tp=hd,nn,ep;
    nn = createnode();
    printf("Enter new element: \n"); scanf("%d",&nn->info);
    nn->rl = nn->ll = NULL;

    ep = hd->ll;
    
    ep->rl = nn;
    nn->rl = hd;
    nn->ll = ep;
    hd->ll = nn;

    hd->info++;
}

void insertleftofk(node hd,int pos)
{
    int i;
    node tp=hd,nn,cp;
    nn = createnode();
    printf("Enter new element: \n"); scanf("%d",&nn->info);
    nn->rl = nn->ll = NULL;

    for(i=1 ; i<=pos-1 ; i++) 
        tp = tp->rl;

    cp = tp->rl;

    tp->rl = nn;
    nn->rl = cp;
    cp->ll = nn;
    nn->ll = tp;
   
    hd->info++;
}

void insertrightofk(node hd,int pos)
{
    int i;
    node tp=hd,nn,cp;
    nn = createnode();
    printf("Enter new element: \n"); scanf("%d",&nn->info);
    nn->rl = nn->ll = NULL;

    for(i=1 ; i<=pos ; i++) 
        tp = tp->rl;

    cp = tp->rl;

    tp->rl = nn;
    nn->rl = cp;
    cp->ll = nn;
    nn->ll = tp;
   
    hd->info++;
}

int insertleftofkey(node hd,int key)
{
    node tp=hd,nn,cp;
    nn = createnode();
    printf("Enter new element: \n"); scanf("%d",&nn->info);
    nn->rl = nn->ll = NULL;

    while(tp->rl->info != key)
       {
         tp = tp->rl;
         if(tp==hd)
         {  printf("Key not found \n"); return -1; }
       }
    cp = tp->rl;

    tp->rl = nn;
    nn->rl = cp;
    cp->ll = nn;
    nn->ll = tp;
   
    hd->info++;
    return 1;
}

void deletesuccesser(node hd,int pos)
{
    int i;
    node tp=hd,dp;

    for(i=1 ; i<=pos ; i++) 
        tp = tp->rl;
    if(tp->rl == hd)
    {  printf("Succeser of %d is Header node\nDeletion not possible\n",tp->info); return; }
    dp = tp->rl;
 
    tp->rl = dp->rl;
    dp->rl->ll = tp;

    free(dp);
    hd->info--;
}

void deletepredeccesser(node hd,int pos)
{
    int i;
    node tp=hd,dp;

    for(i=1 ; i<=pos-1 ; i++) 
        tp = tp->rl;
    if(tp == hd)
    {  printf("Predecceser of %d is Header node\nDeletion not possible\n",tp->rl->info); return; }
    dp = tp;
    tp = tp->ll;
 
    tp->rl = dp->rl;
    dp->rl->ll = tp;

    free(dp);
    hd->info--;
}

