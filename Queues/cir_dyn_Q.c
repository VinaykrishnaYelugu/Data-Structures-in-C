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

void p_insert(Q *); 
void p_delete(Q *);
void p_display(Q *);

void insert_f(Q *);
void delete_r(Q *);

void main()
{
    int choice;
    for( ; ; )
    {
      l1:
    printf("Enter the size of the Queue :  ");
    scanf("%d",&size);
     printf("Enter 1-Priority  queue\t2-Circular Queue\n3-DE Queue\n4-Exit\n");
     scanf("%d",&choice);

      Q q;
      q.f = 0,q.r = -1,q.cnt = 0;
      q.ar = (int *)malloc(size*sizeof(int));
       if(choice==2)
       {
        for( ; ; )
        {
        printf("Enter the choice\n1-Insert\n2-Delete\n3-Display\n4-Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : insert(&q); display(&q); break;
            case 2 : delete(&q); display(&q); break;
            case 3 : display(&q); break;

            case 4 : printf("End of program!!\n"); goto l1;
            default: printf("Invalid choice!!\n"); break; 
        }
        }
       }
  
     else if(choice == 1)
     {
       for( ; ; )
       {
        printf("Enter the choice\n1-Insert\n2-Delete\n3-Display\n4-Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : p_insert(&q); p_display(&q); break;
            case 2 : p_delete(&q); p_display(&q); break;
            case 3 : p_display(&q); break;

            case 4 : printf("End of program!!\n"); goto l1;
            default: printf("Invalid choice!!\n"); break;  
        }  
       }  
     }
     else if(choice == 3)
     {
        for( ; ; )
        {
        printf("Enter the choice\n1-Insert rear\n2-Delete front\n3-Insert front\n4-Delete rear\n5-Display\n6-Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : p_insert(&q); p_display(&q); break;
            case 2 : p_delete(&q); p_display(&q); break;
            case 3 : insert_f(&q); p_display(&q); break;
            case 4 : delete_r(&q); p_display(&q); break;
            case 5 : p_display(&q); break;

            case 6 : printf("End of program!!\n"); goto l1;
            default: printf("Invalid choice!!\n"); break; 
        }
        }
     }
     else if(choice == 4)
     {
      printf("Terminating program!!\n"); exit(0);
     }
     else
     {
      printf("Invalid choice");
     }
   }
}

void insert_f(Q *pq)
{
  if((pq->f==0)&&(pq->r != -1))
  {
    printf("Front insertion is not possible!!\n");
    return;
  }
  if((pq->f == 0)&&(pq->r == -1))
  {
    printf("Enter new item :  ");
    scanf("%d",&pq->ar[++pq->r]);
    return;
  }
  printf("Enter new info :  ");
  scanf("%d",&pq->ar[--pq->f]);

  if(pq->f > pq->r)
  {
    pq->f=0,pq->r = -1;
  }
}

void delete_r(Q *pq)
{
  if(pq->f > pq->r)
  {
    printf("Queue is Empty!!\n");
    return;
  }
  printf("Deleting %d...\n",pq->ar[pq->r--]);
  if(pq->f > pq->r)
  { pq->f = 0,pq->r = -1; }
}

void insert(Q * pq)
{
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

    pq->r = (pq->r+1)%size;
    printf("Enter the new info : "); 
    scanf("%d",&pq->ar[pq->r]);
    pq->cnt++;
}

void delete(Q * pq)
{
    int j,i;
    if(pq->cnt == 0)
      {   return;   }
    printf("Deleting %d from the Queue..\n",pq->ar[pq->f]);
    pq->f = (pq->f + 1)%size;
    pq->cnt--;

    if(pq->cnt == 0)
    {    pq->f = 0,pq->r = -1;   }
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

void p_insert(Q * pq)
{
  if( pq->r == size-1 )
  {
    printf("Queue full\nReallocating..\n");
    size  = size*2;
    pq->ar = (int *)realloc(pq->ar,size*sizeof(int));
  }
 
 int item,i;
 printf("Enter new inffo :  ");
 scanf("%d",&item);
 i = pq->r;
 while( (i>=0)&&(item<pq->ar[i]))
  {
    pq->ar[i+1] = pq->ar[i];
    i--;
  }
  pq->ar[i+1] = item;
  pq->r++;
}

void p_delete(Q *pq)
{
   if(pq->f > pq->r)
   {
    printf("Queue is empty!!\nDeletion not posiible\n");
    return;
   }
   printf("Deleting %d..\n",pq->ar[pq->f++]);
   if(pq->f>pq->r)
   {
    pq->f = 0;
    pq->r = -1;
   }
}

void p_display(Q * pq)
{
  if((pq->f==0)&&(pq->r==-1))
  {
    printf("Queue is Empty!!\n");
    return;
  }
  int i=pq->f;
  printf("Elements in list are :  ");
  while(i<=pq->r)
  {
    printf("%d     ",pq->ar[i]);
    i++;
  }
  printf("\n");
}