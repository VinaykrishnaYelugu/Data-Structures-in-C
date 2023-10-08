#include<stdio.h>
#include<stdlib.h>

struct node
{
  int info;
  struct node * link ;
};

typedef struct node N;

N* createnode(N *);

int n;

void main()
{

  N *fn,*op;
  fn = createnode(fn);
  op = fn;
  printf("Enter the data 1: "); scanf("%d",&(fn->info));
  fn = createnode(fn->link);
  printf("Enter the data 2: "); scanf("%d",&(fn->info));
  fn = createnode((fn->link));
  printf("Enter data 3: "); scanf("%d",&(fn->info));
  fn->link =NULL;

  printf("Entered data 1: %d\t",op->info);
  op = op->link;
  printf("Entered data 2: %d\t",(op)->info);
  op = op->link;
  printf("Entered data 3: %d\n",(op)->info);
}

N *createnode(N *f)
{
  f = (N *)malloc(sizeof(N));
  return f;
}