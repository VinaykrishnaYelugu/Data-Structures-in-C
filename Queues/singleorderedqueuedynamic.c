#include<stdio.h>
#include<stdlib.h>

struct Queue
{
  int *ar;
  int f,r;
};

typedef struct Queue Q;

void insert(Q * );
void delete(Q * );
void display(Q * );

int size,is;

void main()
{
    int choice;
    Q q;
    q.f = 0;
    q.r = -1;
    printf("Enter the size of Queue:  ");
    scanf("%d",&size);
    is = size;
    q.ar = (int *)malloc(size*sizeof(int));

   for( ; ; )
   {
    printf("Enter the choice :   \n1-Insert\n2-Delete\n3-Display\n4-Exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1 : insert(&q); display(&q); break;
        case 2 : delete(&q); display(&q); break;
        case 3 : display(&q); break;
        case 4 : printf("Terminating the program!!\n"); exit(0);
        default: printf("Invalid choice !!\n"); break;
    }
   }
}

void insert(Q * pq)
{
    if(pq->r == size-1)
     {
        printf("Queue is full !!\nReallocating...\n");
        size = size*2;
        pq->ar = (int *)realloc(pq->ar,size*sizeof(int)); 
     }

     printf("Enter new info :   "); 
     scanf("%d",& pq->ar[++pq->r]);
}

void delete(Q * pq)
{
    if(pq->f > pq->r)
      return ; 
    printf("Deleting %d from the Queue\n",pq->ar[pq->f++]);
    if(pq->f > pq->r)
    {
      pq->f = 0;
      pq->r = -1;
      size = is;
      pq->ar = (int *)realloc(pq->ar,size*sizeof(int)); 
    }
}

void display(Q * pq)
{
    if(pq->f > pq->r)
     { printf("Queue is Empty!!\n"); return; }
    printf("Elements of the array\n");
    int i;
    for( i= pq->f ; i<= pq->r ; i++)
       printf("%d      ",pq->ar[i]);
    printf("\n");
}