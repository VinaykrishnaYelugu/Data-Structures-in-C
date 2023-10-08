#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
    int top;
    char st[30];
};
typedef struct stack stk;

char * inf2prf(char* );
char * inf2posf(char* ,int );
char * revexp(char *);
int isoperand(char );
void push(stk  *,char );
char pop(stk *);
int prec(char );

void main()
{
    int choice;
    for( ; ; )
    {
        char inexp[30],* prexp = (char *)calloc(30,sizeof(char)),* poexp = (char *)calloc(30,sizeof(char));
        printf("Enter the choice\n1.INFIX TO PREFIX EXPRESSION\n2.INFIX TO POSTFIX EXPRESSION\n3-EXIT\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :     printf("Enter the infix expression: \n");
                         scanf("%s",inexp);
                         prexp=inf2prf(inexp);
                         printf("Prefix expression :   %s\n",prexp);
                         break;
            case 2 :     printf("Enter the infix expression: \n");
                         scanf("%s",inexp);
                         poexp=inf2posf(inexp,1);
                         printf("Postfix expression :   %s\n",poexp);
                         break;   
            case 3 :     printf("Thank you!!"); exit(0);
            default :    printf("Invalid\n"); break;
        }
    }

}

char * inf2prf(char * exp)
{
   exp = revexp(exp);
   char* prexp = (char *)calloc(30,sizeof(char));
   prexp = inf2posf(exp , 0) ;
   prexp = revexp(prexp); 
   return prexp;
} 

char * inf2posf(char* exp,int flag)
{
   char *posexp = (char *)calloc(30,sizeof(char));
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
              if(flag)
              {
                 while( (ps->top != -1) && (prec(*(exp+i)) <= prec(ps->st[ps->top])))  // for postfix
                  {   posexp[k++] = pop(ps);  }
                  push(ps, *(exp+i));
              }
              else
              {
                 while( (ps->top != -1) && (prec(*(exp+i)) < prec(ps->st[ps->top])))  // for prefix
                  {   posexp[k++] = pop(ps);  }
                  push(ps, *(exp+i));
              }
          }
       }  
    }
   }
   while( ps->top != -1)
   {  posexp[k++] = pop(ps);  }

   return posexp;

}


char * revexp(char * exp)
{
    int i,j=0;
    char * rexp = (char *)calloc(30,sizeof(char));
    for(i=strlen(exp)-1 ; i>=0 ; i--)
    {
        if(*(exp+i) ==  '(')
           *(rexp+j) = ')';
        else if(*(exp+i) == ')')
           *(rexp+j) = '(';
        else
           *(rexp+j) = *(exp+i);
        j++;
    }
    printf("reverse exp =  %s\n",rexp);
    return rexp;
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

