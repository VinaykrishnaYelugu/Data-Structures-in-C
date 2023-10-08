#include<stdio.h>
#include<stdlib.h>

struct node
{
  int info;
  struct node * link ;
};

typedef struct node N;

void createnode(N *);

int n;

void main()
{
  N *fn1,*fn;
   createnode(fn1);
  fn = fn1;
  printf("Enter the data 1: "); scanf("%d",&fn->info);
    createnode(fn->link);
  printf("Enter the data 2: "); scanf("%d",&(fn)->info);
   createnode(fn->link);
  printf("Enter data 3: "); scanf("%d",&(fn)->info);
  fn->link =NULL;

  printf("Entered data 1: %d\t",fn1->info);
  fn1 = fn1->link;
  printf("Entered data 2: %d\t",(fn1)->info);
  fn1 = fn1->link;
  printf("Entered data 3: %d\n",(fn1)->info);
  fn1->link = NULL;
  
 /*
 int i;
 N  *fn,*op;
 printf("Enter number of elements: "); scanf("%d",&n);
 i=0 ;
 while(i<3)
 {
  if(i==0)
  {
    fn = createnode(fn);
    op=fn;
  }
  printf("Enter data %d: ",i+1); scanf("%d",&fn->info);
  if(i==2)
   {fn->link = NULL; break; }
  fn = createnode(fn->link); 
  i++;
 }

i=0;
 while(i<3)
 {
  printf("Data %d   : ",i+1); printf("%d\t",op->info);
  op = op->link;
  i++;
 }
 */
}

void createnode(N *f)
{
  f = (N *)malloc(sizeof(N));
  return ;
}