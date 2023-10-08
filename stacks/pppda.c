#include<stdio.h>
#include<stdlib.h>

int size;

struct stack
{
    int *item;
    int top;
};

typedef struct stack STK;

void push(STK*);
void pop(STK*);
void peek(STK*);
void display(STK);

void main()
{
    STK s;
    s.top = -1;
    printf("Enter size of stack: \n");
    scanf("%d",&size);
    s.item = (int *)malloc(size*sizeof(int));
    int choice;
    for( ; ; )
    {
        printf("Enter the choice\n1-push\n2-pop\npeek\n4-display\n"); scanf("%d",&choice);
        switch(choice)
        {
            case 1 : push(&s); break;
            case 2 : pop(&s);  break;
            case 3 : peek(&s); break;
            case 4 : display(s); break;
        
            default : printf("Invalid! \n"); exit(0);
        }
    }
}

void push(STK* ps)
{
  if(ps->top == size-1)
   {
     printf("List is full!\nReallocating...\n");  
     size = size*2;
     ps->item = (int *)realloc(ps->item,size*sizeof(int));
   } 
   int item;
   printf("Enter the new item:  "); scanf("%d",&item);
   ps->top++;
   ps->item[ps->top] = item;
}

void pop(STK* ps)
{
    if(ps->top == -1)
    { printf("List is empty \n"); return; }
    printf("Deleting the %d\n",ps->item[ps->top]);
    ps->top--;
}

void peek(STK* ps)
{
  if(ps->top == -1)
   { printf("Array is empty \n"); return; }
  printf("Element present in the top = %d\n",ps->item[ps->top]);
}

void display(STK s)
{
    if(s.top == -1)
    { printf("List is empty\n"); return ; }
    printf("Elements are: \n");
    while(s.top != -1)
     { printf("%d         ",s.item[s.top]); s.top--; }
    printf("\n");
}