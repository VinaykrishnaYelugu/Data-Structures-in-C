#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int *ar,r,f,cnt;
};
typedef struct Queue Q;

int size,osize;

void insert(Q *);
void delete(Q *);
void display(Q *);

void main()
{
    Q q;
    q.f = 0,q.r = -1,q.cnt = 0;
    int choice;
    printf("Enter the size of the Queue :  ");
    scanf("%d",&size);
    q.ar = (int *)malloc(size*sizeof(int));
    for( ; ; )
    {
        printf("Enter the choice\n1-Insert\n2-Delete\n3-Display\n4-Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : insert(&q); display(&q); break;
            case 2 : delete(&q); display(&q); break;
            case 3 : display(&q); break;

            case 4 : printf("Terminating the program!!\n"); exit(0);
            default: printf("Invalid choice!!\n"); break; 
        }
    }
}


void insert(Q * pq)
{
   // printf("Front = %d\nRear = %d\n",pq->f,pq->r);
    int i;
    if(pq->cnt == size)
      {
        printf("Stack Overflow!!\n");
        printf("Reallocating!!\n");
        osize  = size;
        size = size*2;
        pq->ar = (int *)realloc(pq->ar,size*sizeof(int));
        printf("Size = %d\n",size);
        if(pq->r != -1)
        {
         pq->r = osize-1;
         i=0;
         while(i != pq->f )
         {
            pq->r = (pq->r+1)%size;
            pq->ar[pq->r] = pq->ar[i];
            i = (i+1)%size;
         }
        }
      } 
   // printf("Front = %d\nRear = %d\n",pq->f,pq->r);

    pq->r = (pq->r+1)%size;
    printf("Enter the new info : "); 
    scanf("%d",&pq->ar[pq->r]);
    pq->cnt++;
  //  printf("Front = %d\nRear = %d\n",pq->f,pq->r);

}

void delete(Q * pq)
{
   // printf("Front = %d\nRear = %d\n",pq->f,pq->r);

    int j,i;
    if(pq->cnt == 0)
      {   return;   }
    printf("Deleting %d from the Queue..\n",pq->ar[pq->f]);
    pq->f = (pq->f + 1)%size;
    pq->cnt--;
  //  printf("Front = %d\nRear = %d\n",pq->f,pq->r);

    if(pq->cnt == 0)
    {    pq->f = 0,pq->r = -1;   }

    /*if( pq->cnt <= (size/3) )
    {
        printf("Number of elements %d is less than(or equal to) one third of total size = %d(size/3) !! \nDeallocating memory block\n",pq->cnt,(size/3));
        osize = size;
        size = (size/2);
        if( pq->r >= size )
        {
            j = pq->f;
            pq->r = -1;
            for( i=1 ; i<=pq->cnt ; i++)
            {
                pq->r = (pq->r+1)%(size);
                pq->ar[pq->r] = pq->ar[j];
                j = (j+1)%(osize);
            }
            pq->f = 0;
        }
            pq->ar = (int *)realloc(pq->ar,size*sizeof(int));
            printf("Size = %d\n",size);
    }*/
   // printf("Front = %d\nRear = %d\n",pq->f,pq->r);

}

void display(Q * pq)
{
    if(pq->cnt == 0)
      { printf("Queue is empty!!\n\n"); return;  }
    printf("Elements of the Queue are : \n");
    int j = pq->f;
    for(int i=1 ; i<=pq->cnt ; i++)
    {
         printf("%d      ",pq->ar[j]);
         j = (j+1)%size;
    }
    printf("\n\n");
}