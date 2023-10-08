#include<stdio.h>
#include<stdlib.h>

struct Queue
{
  int f,r,cnt;
  int * ar;
};
typedef struct Queue Q;

void insert(Q *);
void delete(Q* );
void display(Q *);

int size;

void main()
{
    Q q;
    q.f = 0; 
    q.r = -1;
    q.cnt = 0;
    int choice;
    printf("Enter size of the circular array: \n"); scanf("%d",&size);
    q.ar = (int *)calloc(size,sizeof(int));
    for( ; ; )
    {
        printf("Enter the choice\n1-Insert\n2-Delete\n3-Display\n4-Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insert(&q); break;
            case 2: delete(&q); break;
            case 3: display(&q); break;
            case 4: printf("Thank you!!\n"); exit(0);
            default : printf("Invalid!!\n"); 
        }
    }
}

void insert(Q * pq)
{
  if(pq->cnt == size)
    { printf("Queue is full !!\n");  return; }
  pq->r = (pq->r+1)%size;
  printf("Enter the new element: \n"); scanf("%d",&pq->ar[pq->r]);
  pq->cnt++;
}

void delete(Q * pq)
{
    if(pq->cnt == 0 )
      { printf("Queue is empty !!\n"); return; } 
    printf("Deleted %d \n",pq->ar[pq->f]); 
    pq->f = (pq->f+1)%size; 
    pq->cnt--;
}

void display(Q * pq)
{
    int t;
    if(pq->cnt == 0)
     { printf("Queue is empty !!\n"); return; }
    printf("Elements of the Queue : \n");
    t = (pq->f);
    for(int i=0 ; i<=pq->cnt-1 ; i++)
    {
        printf("%d\t",pq->ar[t]);
        t = (t+1)%size;
    }
    printf("\n");
}
