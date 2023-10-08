#include<stdio.h>
#include<stdlib.h>

#define size 5

struct stack
{
    int item[size];
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
    int choice;
    for( ; ; )
    {
        printf("Enter the choice \n"); scanf("%d",&choice);
        switch(choice)
        {
            case 1: push(&s); display(s); break;
            case 2: pop(&s); display(s); break;
            case 3 :peek(&s); break;
        
            default : printf("Invalid! \n"); exit(0);
        }
    }
}

void push(STK* ps)
{
  if(ps->top == size-1)
   { printf("List is full! no space!\n"); return; }
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