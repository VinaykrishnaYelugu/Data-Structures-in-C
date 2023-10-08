#include<stdio.h>
#include<stdlib.h>

struct Queue 
{
    int f,r;
    int * ar;
};
typedef struct Queue Q;

void insertpwq(Q *);
void deletepwq(Q *);
void delete_rpwq(Q *);
void insertrq(Q *);
void display(Q *);

int size;

void main()
{
    int choice;
    Q qo,qr;
    qo.f = 0, qr.f = 0; 
    qo.r = -1, qr.r = -1;
    printf("Enter the size of Queue: \n"); scanf("%d",&size);
    qo.ar = (int *)calloc(size,sizeof(int));
    qr.ar = (int *)calloc(size,sizeof(int));
    for( ; ; )
    {
        printf("Enter the choice\n1-Inserting priority wise\n2-Deleting priority wise in order queque\n3-Inserting rear random queue\n");
        printf("4-Deleting priority wise in random queue\n5-Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : insertpwq(&qo); display(&qo); break;
            case 2 : deletepwq(&qo); display(&qo); break;
            case 3 : insertrq(&qr); display(&qr);  break;
            case 4 : delete_rpwq(&qr); display(&qr); break;
            case 5 : printf("Terminating program!!\n"); exit(0);
            default : printf("Invalid !!\n"); break;
        }
    }
}

void insertrq(Q * pq)
{
    if(pq->r == size-1)
     { printf("Queue is full!!\n"); return; }
    printf("Enter the new item: "); 
    scanf("%d",& pq->ar[++pq->r]);
}

void insertpwq(Q * pq)
{
  if(pq->r == size-1)
   { printf("Queue is full !!\nInsertion is not possible\n"); return; }
  int item,i;
  printf("Enter the new item: "); scanf("%d",&item);

  for( i=pq->r ; i>=pq->f ; i--)
  {
   if(item > pq->ar[i])
      break; 
    pq->ar[i+1] = pq->ar[i];
  }
  pq->ar[i+1] = item;

  pq->r++;
}

void deletepwq(Q * pq)
{
  if(pq->f > pq->r )
   { printf("Queue is empty!! \n"); return; }
  printf("Deleting %d\n",pq->ar[pq->f++]);
  if(pq->f > pq->r)
   { pq->f = 0; pq->r = -1; }
}

void delete_rpwq(Q * pq)
{
    if(pq->f > pq->r)
     { printf("Queue is empty!!\nDeletion not possible !!\n"); }
    int low = pq->f,i; 
    for( i=pq->f ; i<=pq->r ; i++)
       { 
         if(pq->ar[i] < pq->ar[low])
           low = i;
       }
    for( i=low ; i<=pq->r ; i++)
      {  pq->ar[i] = pq->ar[i+1]; }
    pq->r--;

    if(pq->f > pq->r)
    { pq->f = 0; pq->r = -1; }
}


void  display(Q * pq)
{
    if(pq->f > pq->r)
        { printf("Queue is empty !!\n"); return; }

    printf("Elements of the Queue: \n");
    for(int i=pq->f ; i<=pq->r ; i++)
    {
        printf("%d\t",pq->ar[i]);
    }
    printf("\n");
}