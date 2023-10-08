#include<stdio.h>
#include<stdlib.h>

struct Queue
{
  int f,r;
  int * ar;
};
typedef struct Queue Q;

int size;

int isfull(Q *);
int isempty(Q *);
void insert(Q *);
void delete(Q * );
void display(Q *);

void main()
{
   Q q;
   q.f = 0;
   q.r =-1;
   int choice;
   printf("Enter the size of the queue: \n"); scanf("%d",&size);
   q.ar = (int *)calloc(size,sizeof(int));
   for( ; ; )
   {
    printf("Enter the choice\n1-Insert\n2-Delete\n3-Display\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1 : insert(&q); break;
        case 2 : delete(&q); break;
        case 3 : display(&q); break;
        case 4 : printf("Thank you!!"); exit(0);

        default: printf("Invalid\n"); break;
    }
   }
}

void insert(Q * pq)
{
  if (isfull(pq))
  { printf("Insertion is not possible!!\n"); return;  }
  printf("Enter the new item:  "); scanf("%d",& pq->ar[++pq->r]);
}

void delete(Q * pq)
{
   if(isempty(pq))
    { printf("Deletion is not possible!!\n"); return; }
   printf("Deleting %d \n",pq->ar[pq->f++]); 
    if(pq->f > pq->r)
     { 
       printf("Size = %d\tRear=%d\tFront = %d\n",size,pq->r,pq->f); 
       if(pq->f != 0)
       { 
          pq->f = 0 ; 
          pq->r = -1; 
          printf("Size = %d\tRear=%d\tFront = %d\n",size,pq->r,pq->f); 
       }
     }
}

void display(Q * pq)
{
  if(isempty(pq))
    printf("Queue is empty\n");
  printf("Elements of the queue: \n");
  for(int i=pq->f ; i<=pq->r ; i++)
   { printf("%d\t",pq->ar[i]); }
   printf("\n");
}

int isempty(Q * pq)
{
    if(pq->f > pq->r)
     { 
       printf("Size = %d\tRear=%d\tFront = %d\n",size,pq->r,pq->f); 
       printf("Queue is empty!!\n"); 
       return 1;
     }
    return 0;
}

int isfull(Q * pq)
{
    if(pq->r == size-1)
     { 
       printf("Size = %d\tRear=%d\tFront = %d\n",size,pq->r,pq->f); 
       printf("Queue is full!!\n");
       return 1;
     }
     return 0;
}