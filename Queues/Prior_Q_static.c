#include<stdio.h>
#include<stdlib.h>

#define size 5

struct Queue
{
    int ar[size],f,r;
};
typedef struct Queue Q;

void insert(Q *);
void delete(Q *);
void insert_h_p(Q *);
void insert_l_p(Q *);
void delete_h_p(Q *);
void delete_l_p(Q *);

void display(Q * );

void main()
{
    int choice;
    Q q;
    q.f = 0, q.r = -1;
    for( ; ; )
    {
        printf("Enter the choice\n1-Insert by high priority\n2-Insert by low priority\n3-Delete\n4-Insert\n5-Delete by high priority\n6-Delete by low priority\n7-Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : insert_h_p(&q); display(&q); break;
            case 2 : insert_l_p(&q); display(&q); break;
            case 3 : delete(&q); display(&q); break;
            case 4 : insert(&q); display(&q); break;
            case 5 : delete_h_p(&q); display(&q); break;
            case 6 : delete_l_p(&q); display(&q); break;
            case 7 : printf("Terminating the program !!\n"); exit(0);
            default : printf("Invalid choice !!\n"); break;
        }
    }
}

void insert(Q * pq)
{
    if( pq->r == size-1 )
     { printf("Queue is full !!\n"); return; }
    printf("Enter the new info :  "); 
    scanf("%d",&pq->ar[++pq->r]);
}

void delete(Q * pq)
{
    if(pq->f > pq->r)
       return;
    printf("Deleting %d from the Queue\n",pq->ar[pq->f++]);

    if(pq->f > pq->r)
    { pq->f = 0, pq->r = -1; }
}

void insert_h_p(Q * pq)
{
    if( pq->r == size-1 )
     { printf("Queue is full !!\n"); return; }

    int i = pq->r,item;
    printf("Enter new info :  "); 
    scanf("%d",&item);
    while( i>= pq->f)
    {
       if(pq->ar[i] > item)
        { break; }
       else
       { 
        pq->ar[i+1] = pq->ar[i];
        i--;
       }
    }
    pq->ar[i+1] = item;
    pq->r++; 
}

void insert_l_p(Q * pq)
{
    if(pq->r == size-1)
      { printf("Queue is Full !! \n"); return; }
    int i=pq->r,j,item;
    printf("Enter the new info :  "); 
    scanf("%d",&item);

    while( i >= pq->f )
    {
       if( pq->ar[i] < item)
          break;
       else
       {
          pq->ar[i+1] =  pq->ar[i];
          i--;
       }
    }
    pq->ar[i+1] = item;
    pq->r++;
}

void delete_h_p(Q *pq)
{ 
   if(pq->f > pq->r)
      { return; }
   int high,hi=0,i;

   high = pq->ar[0];
   
   for( i = pq->f ; i<= pq->r ; i++)
   {
      if( pq->ar[i] > high )
       {
        high = pq->ar[i];
        hi = i;
       }
   }
   printf("Highest element index :  %d\n",hi);
   for( i = hi ; i > pq->f ; i--)
      pq->ar[i] = pq->ar[i-1];
   pq->f++;

    if(pq->f > pq->r)
    { pq->f = 0, pq->r = -1; }
}

void delete_l_p(Q *pq)
{ 
   if(pq->f > pq->r)
      { return; }
   int low,li=0,i;

   low = pq->ar[0];
   
   for( i = pq->f ; i<= pq->r ; i++)
   {
      if( pq->ar[i] < low )
       {
        low = pq->ar[i];
        li = i;
       }
   }

   printf("Lowest element index :  %d\n",li);
   for( i = li ; i > pq->f ; i--)
      pq->ar[i] = pq->ar[i-1];
   pq->f++;

    if(pq->f > pq->r)
    { pq->f = 0, pq->r = -1; }
}

void display(Q * pq)
{
    if(pq->f > pq->r)
      { printf("Queue is Empty !!\n"); return; }
    printf("Elements in the Queue are :  \n");
    for(int i= pq->f ; i<= pq->r ; i++)
        printf("%d       ",pq->ar[i]);
    printf("\n");
}
