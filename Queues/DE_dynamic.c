#include<stdio.h>
#include<stdlib.h>

struct Queue 
{
    int *ar,f,r;
};

typedef struct Queue Q;

int size;

void insert_rear(Q *);
void delete_front( Q *);
void insert_front(Q *);
void delete_rear(Q *);
void display(Q *);

void main()
{
    int choice;
    Q q;
    q.f = 0 ,q.r = -1;
   printf("Enter the size :  ");
   scanf("%d",&size);
   q.ar = (int *)malloc(size*sizeof(int));
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
        case 5 : printf("Terminating the program !!\n"); exit(0);
        default: printf("Invalid choice\n"); break;
    }
   }
}

void insert_rear(Q * pq)
{
    if( pq->r == size-1)
     {
        printf("Queue is full in rear\nReallocating in rear...\n");
        size  = size*2;
        pq->ar = (int *)realloc(pq->ar,size*sizeof(int));
     }
    printf("Enter new info :  ");
    scanf("%d",&pq->ar[++pq->r]);
    printf("Front = %d\tRear = %d\n",pq->f,pq->r);
}

void delete_front(Q * pq)
{
  if(pq->f > pq->r )
    return;
  printf("Deleting %d...\n",pq->ar[pq->f++]);   
  printf("Front = %d\tRear = %d\n",pq->f,pq->r);

  if(pq->f > pq->r)
    pq->f = 0,pq->r = -1;
    printf("Front = %d\tRear = %d\n",pq->f,pq->r);

}

void delete_rear(Q * pq)
{
    if(pq->f > pq->r)
     return;
    printf("Deleting %d....\n",pq->ar[pq->r--]);
    printf("Front = %d\tRear = %d\n",pq->f,pq->r);

    if(pq->f > pq->r)
     pq->f = 0,pq->r = -1;
    printf("Front = %d\tRear = %d\n",pq->f,pq->r);

}

void insert_front(Q * pq)
{
     int item,i,osize;
     printf("Enter the new info :  ");
     scanf("%d",&item);

     if((pq->f == 0)&&(pq->r != -1))
     {
        printf("Queue is full in front\nReallocating in front...\n");
        osize = size;
        size  = size*2;
        pq->ar = (int *)realloc(pq->ar,size*sizeof(int));
      
        for( i=0 ; i<=pq->r ; i++)
            pq->ar[osize+i] = pq->ar[i];
        pq->f = osize;
        pq->r = osize+pq->r;
        pq->ar[--pq->f] = item;
    printf("Front = %d\tRear = %d\n",pq->f,pq->r);
     }
     else if((pq->f == 0)&&(pq->r == -1))
         pq->ar[++pq->r] = item;
     else //else if(pq->f != 0)
         pq->ar[--pq->f] = item;
    printf("Front = %d\tRear = %d\n",pq->f,pq->r);

}

void display(Q * pq)
{
    if( pq->f > pq->r)
     {
        printf("Queue is empty !!\n");
        return;
     }
    printf("Element in the Queue are :  \n");
    for(int i = pq->f ; i<= pq->r ; i++)
       printf("%d      ",pq->ar[i]);
    printf("\n\n");
}

