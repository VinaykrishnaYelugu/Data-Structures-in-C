// infix to postfix
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
    int top;
    char st[20];
};
typedef struct stack stk;

void inf2posf(char *);
int isoperand(char);
void push(stk *, char);
char pop(stk *);
int prec(char );

void main()
{
  char inexp[30];
  printf("Enter the infix expresssion: \n"); scanf("%s",inexp);
  printf("Converting from infix to postfix: \n");
  inf2posf(inexp);
}

void inf2posf(char* exp)
{
   char* posexp = (char *)calloc(30,sizeof(char));
   stk s;
   stk* ps=&s;
   ps->top = -1;
   
   int i,k=0;
   for(i=0 ; i<strlen(exp) ; i++)
   {
    if(isoperand(*(exp+i)))
    {    posexp[k++] = *(exp+i);   }

    else 
    {
       if( *(exp+i)=='(' )
       {   push(ps,*(exp+i));  }
       else if( *(exp+i)==')' )
       {
        while( ps->st[ps->top] != '(' )
        {
           printf("Passing %c into postfix expression\n",ps->st[ps->top]);
           posexp[k++] = pop(ps);
        }
        pop(ps);
       }
       else if(ps->top == -1)
       {  push(ps,*(exp+i));  }
       else                //  else if(ps->top != -1)
       {
         if(prec(*(exp+i))>prec(ps->st[ps->top]))
         {   push(ps,*(exp+i));  }
         else                      //else if((  prec(*(exp+i)) <= prec(ps->st[ps->top]) ))
          {
              while( (ps->top != -1) && (prec(*(exp+i)) <= prec(ps->st[ps->top])))
              {   posexp[k++] = pop(ps);  }
               push(ps, *(exp+i));
          }
       }  
    }
   }
   while( ps->top != -1)
   {  posexp[k++] = pop(ps);  }

   printf("POST FIX EXPRESSION IS:  \n");
   printf("%s",posexp);
}

int isoperand(char ch)
{
  switch(ch)
  {
    case '+': 
    case '-':
    case '*':
    case '/':
    case '$':
    case '(':
    case ')': return 0;
    default : return 1;
  }
}

void push(stk  *ps,char ch)
{
    printf("Pushing %c into stack\n",ch);
    ps->st[++ps->top] = ch;
}

char pop(stk *ps)
{
    printf("Poping  %c out of stack\n",ps->st[ps->top--]);
    return(ps->st[ps->top+1]);
}

int prec(char ch)
{
    switch(ch)
    {
        case '+' :
        case '-' : return 1;
        case '*' :
        case '/' : return 2;
        case '$' : return 3;
        case '(' :
        case ')' : return 0;
    }
}


/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
    int top;
    char ast[25];
};
typedef struct stack stk;

void push(char);
void pop();
int prec(char);
char* inf2posf(char*);
int isoperator(char);

stk s;
void main()
{
   s.top = -1;
   int i;
   char *inexp,* poexp,ch;
   inexp = (char *)calloc(30,sizeof(char));
   printf("Enter infix expression : \n");  scanf("%s",inexp);
   poexp = inf2posf(inexp);
   printf("\npostfix expression is: \n");
   for(i=0 ; i<strlen(poexp); i++)
     printf("%c",poexp[i]);
}

char* inf2posf(char* exp)
{
    int i,j,k=0;
    char *poexp;
    poexp = (char *)calloc(30,sizeof(char));
    for( i=0 ; i<strlen(exp) ; i++)
    {
      if(isoperator(*(exp+i)))
      {
        if(*(exp+i) == '(')
         {
            push(*(exp+i));
         }

        else if(*(exp+i) == ')')
         {
            while(s.ast[s.top] != '(')
            {
                printf("Pushing %c into postfix expression\t",s.ast[s.top]);
                poexp[k++] = s.ast[s.top];
                pop();
                printf("\n");
            }
            pop();
         }
        else if(s.top == -1)
          {
            push(*(exp+i));
            printf("Stack status %d\t",s.top);
          }
        else if((s.top!= -1) && prec(*(exp+i)) > prec(s.ast[s.top]))
          {
            push(*(exp+i));
            printf("Stack status %d\t",s.top);
          }
        else
          {
           while((s.top!=-1)&&(prec(*(exp+i)) <= prec(s.ast[s.top])))
           { 
             printf("Pushing %c into postfix expression..pop\t",s.ast[s.top]);
             poexp[k++] = s.ast[s.top];
             pop(); 
           }
           push(*(exp+i));
          }
      }
    else
      {
         printf("Pushing %c into postfix expression\t",*(exp+i));
         poexp[k++] = *(exp+i);
      }
      printf("\n");
  }

  while(s.top!=-1)
  {
    printf("Pushing %c into postfix expression\n",s.ast[s.top]);
    poexp[k++] = s.ast[s.top];
    pop();
  }
  return poexp;
}

int isoperator(char ch)
{
  switch(ch)
  {
     case '+': 
     case '-':
     case '*':
     case '/':
     case '$':
     case '(':
     case ')': return 1;
     default : return 0;
  }
}

int prec(char ch)
{
  switch(ch)
  {
     case '+': 
     case '-': return 1;
     case '*':
     case '/': return 2;
     case '$': return 3;
     case '(':
     case ')': return 0; 
  }
}


void push(char ch)
{
   printf("Pushing %c into stack\t",ch);
   s.ast[++s.top] = ch;
   printf("Stack status %d\t",s.top);
}

void pop()
{
  printf("Poping %c out of stack\t",s.ast[s.top--]);
  printf("Stack status %d\t",s.top);
}
*/
