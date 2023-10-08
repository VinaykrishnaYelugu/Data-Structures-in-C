#include<stdio.h>
#include<stdlib.h>

#define size 6

struct Queue
{
    int ar[size],r,f;
};
typedef struct Queue Q;

void insert_rear(Q *);
void delete_front(Q *);
void insert_front(Q *);
void delete_rear(Q *);

void display(Q *);

void main()
{
    int choice;
    Q q;
    q.f = 0,q.r = -1;
    for( ; ; )
    {
        printf("Enter the choice\n1-Insert rear\n2-Delete front\n3-Insert front\n4-Delete rear\n5-Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : insert_rear(&q); display(&q); break;
            case 2 : delete_front(&q); display(&q); break;
            case 3 : insert_front(&q); display(&q); break;
            case 4 : delete_rear(&q); display(&q); break;
            case 5 : printf("Terminating Program !! \n"); exit(0);
            default: printf("Invalid choice !!\n"); break; 
        }
    }
}


void insert_rear(Q * pq)
{
    if(pq->r == size-1)
    { printf("Queue is full!!"); return;  }
    printf("Enter the new info :  "); 
    scanf("%d",&pq->ar[++pq->r]);
}

void delete_front(Q * pq)
{
    if(pq->f > pq->r)
      return;
    printf("Deleteing %d...\n",pq->ar[pq->f++]);

    if(pq->f > pq->r)
       pq->f = 0,pq->r = -1;
}

void insert_front(Q * pq)
{
    if((pq->f == 0)&&(pq->r != -1))
     { printf("Front insertion is not possible !!\n"); return; }
    int item;
    printf("Enter the new info :  ");
    scanf("%d",&item);

    if((pq->f == 0)&&(pq->r == -1))
        pq->ar[++pq->r] = item;  
    else
       pq->ar[--pq->f] = item;
}

void delete_rear(Q * pq)
{
    if((pq->f == 0)&&(pq->r == -1))
      return;
    printf("Deleting %d from the Queue...\n",pq->ar[pq->r--]);

    if(pq->f > pq->r)
      pq->f = 0,pq->r = -1;
}

void display(Q * pq)
{
    if(pq->f > pq->r)
     {
        printf("Queue is Empty !!\n");
        return;
     }
    printf("Elements in the Queue are : \n");
    
    for( int i = pq->f ; i<= pq->r ; i++)
        printf("%d       ",pq->ar[i]);
    printf("\n");
}