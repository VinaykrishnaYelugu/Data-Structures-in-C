//Infix to prefix/postfix

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

# define size 30

struct stacks
{
    char  ar[size];
    int top;
};
typedef struct stacks stk;

char*  inf2pof(char* );
char* inf2prf(char *);

int isoperand(char );
int prec(char);
char* rev(char* );
void push(stk* , char);
char pop(stk *);

void main()
{
    int choice;
    char * poexp,*prexp;

    for( ; ; )
    {
        char inexp[30];
        printf("Enter the choice: \n1-Infix to postfix\n2-Infix to prefix\n3-Exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
              
            case 1: printf("Enter the valid infix expression : \n");
                    scanf("%s",inexp);
                    poexp = inf2pof(inexp);
                    printf("\nPostfix expression is: %s\n\n",poexp);
                    break;
            case 2: printf("Enter the valid infix expression : \n");
                    scanf("%s",inexp);
                    prexp = inf2prf(inexp); 
                    printf("\nPrefix expression is: %s\n\n",prexp);
                    break;

            case 3: printf("Terminating the program!!\n"); exit(0);
            default : printf("Invalid choice\n"); break;
        }
    }
}

char* inf2pof(char* exp)
{
   stk s;
   s.top= -1;
   char *poexp=(char *)calloc(30,sizeof(char)),c;
   int i,k=0;
   for(i=0 ; i<strlen(exp); i++)
   {
    if(isoperand(*(exp+i)))
    {
       printf("Entering %c into the postfix expression..\n",*(exp+i));
       poexp[k++] = *(exp+i);
    }
    else
    {
        if(*(exp+i) == '(')
        {   push(&s,*(exp+i));   }

        else if(*(exp+i) == ')')
        {
            while(s.ar[s.top] != '(')
            { 
               c = pop(&s);
               printf("Entering %c into the postfix expression..\n",c);
               poexp[k++] = c;
            }
            c = pop(&s);
        }

        else if(s.top == -1)
           {  push(&s,*(exp+i));  }

        else // else if (s.top != -1)
        {
            if(prec(*(exp+i)) > prec(s.ar[s.top]) )
            {  push(&s,*(exp+i)); }

            else //( prec(*(exp+i)) <= prec(s.ar[s.top]) )
            {
                while(  prec(*(exp+i)) <= prec(s.ar[s.top])  )
                {
                    c = pop(&s);
                    printf("Entering %c into the postfix expression..\n",c);
                    poexp[k++] = c;

                    if(s.top == -1)
                       break;
                }
                push(&s,*(exp+i));
            }
        }
    }
   }
   if(s.top != -1)
   {
    while(s.top != -1)
      poexp[k++]=pop(&s);
   }
  return poexp;
}

char* inf2prf(char* oexp)
{
  char* exp = rev(oexp);

   stk s;
   s.top= -1;
   char *poexp=(char *)calloc(30,sizeof(char)),c;
   int i,k=0;
   for(i=0 ; i<strlen(exp); i++)
   {
    if(isoperand(*(exp+i)))
    {
       printf("Entering %c into the postfix expression..\n",*(exp+i));
       poexp[k++] = *(exp+i);
    }
    else
    {
        if(*(exp+i) == '(')
        {   push(&s,*(exp+i));   }

        else if(*(exp+i) == ')')
        {
            while(s.ar[s.top] != '(')
            { 
               c = pop(&s);
               printf("Entering %c into the postfix expression..\n",c);
               poexp[k++] = c;
            }
            c = pop(&s);
        }

        else if(s.top == -1)
           {  push(&s,*(exp+i));  }

        else // else if (s.top != -1)
        {
            if(prec(*(exp+i)) >= prec(s.ar[s.top]) )
            {  push(&s,*(exp+i)); }

            else //( prec(*(exp+i)) <= prec(s.ar[s.top]) )
            {
                while(  prec(*(exp+i)) < prec(s.ar[s.top])  )
                {
                    c = pop(&s);
                    printf("Entering %c into the postfix expression..\n",c);
                    poexp[k++] = c;

                    if(s.top == -1)
                       break;
                }
                push(&s,*(exp+i));
            }
        }
    }
   }
   if(s.top != -1)
   {
    while(s.top != -1)
      poexp[k++]=pop(&s);
   }


   exp = rev(poexp);
   return exp;
}

int isoperand(char c)
{
   switch(c)
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

int prec(char c)
{
    switch(c)
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

char* rev(char* exp)
{
    int i,k=0;
    char* rexp = (char* )calloc(30,sizeof(char));

    for(i=strlen(exp)-1 ; i>=0 ; i--)
    {
        if(*(exp+i) == '(')
          rexp[k++] = ')';
        else if(*(exp+i) == ')')
          rexp[k++] = '(';
        else
          rexp[k++] = *(exp+i);
    }

    return rexp;
}

void push(stk* ps,char c)
{
    printf("Pushing %c into the stack..\n",c);
    ps->ar[++ps->top] = c;
}

char pop(stk* ps)
{
    printf("Poping %c out of the stack..\n",ps->ar[ps->top]);
    ps->top--;
    return ps->ar[ps->top+1];
}
