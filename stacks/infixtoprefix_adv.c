//infix to prefix
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
   char ar[30];
   int top;
};
typedef struct stack S;

void inf2prf(char *);
void push(S *, char);
char pop(S *);
int prec(char c);
int isoperand(char c);


int main()
{
    char inf[30];
    printf("Enter the infix expression : ");
    scanf("%s",inf);

    inf2prf(inf);

    return 0;
}

void inf2prf(char* exp)
{
   int i,k=-1;
   char ch;
   S s;
   s.top = -1;

  char* prf = (char* )calloc(30,sizeof(char));

// in this prefix conversion we don't reverse istead we will convert from last to first
  for(i=strlen(exp)-1 ; i>=0;  i--)
   {
     if(  isoperand( *(exp+i) ) )
       {
          printf("Entering %c into the prefix exp\n",*(exp+i));
          prf[++k] = *(exp+i);
          //printf("%s",prf);
       }
     else
       {
         if(*(exp+i) == ')') // here ')' in prefix is taken instead of '(' used in postfix
          {
            push(&s ,'(');  // here '(' is pushed for ')' 
          }

          else if(*(exp+i) == '(') // here '(' is taken instead of ')' used in postfix
          {
             while(s.ar[s.top] != '(')  // here '(' is searched instead of ')' as we havw pushed '(' initially in line 52
             {
                ch = pop(&s);
                printf("Entering the %c into the prefix exp ",ch);
                prf[++k] = ch;
             }
             pop(&s);
          }

          else if(s.top == -1)
             push(&s,*(exp+i));

          else
          {
            if( prec(*(exp+i)) >= prec(s.ar[s.top]) )
               push(&s,*(exp+i));
            else
            {
               while( (s.top!=-1) && ( prec(*(exp+i)) < prec(s.ar[s.top]) ) )
               {
                 ch = pop(&s);
                 printf("Entering %c into the pre fix expression: \n",ch);
                 prf[++k] = ch;
               }
               push(&s,*(exp+i));
            }
          }
       } 
   }
  while(s.top != -1)
   {
    ch = pop(&s);
    printf("Entering %c into the pre fix expression: \n",ch);
    prf[++k] = ch;
   } 
   
   printf("Pre fix expresion is : ");
   for(i= strlen(prf)-1 ; i>=0 ; i--)
     printf("%c",*(prf+i));
}

int isoperand(char c)
{
    switch(c)
    {
        case '+' :  
        case '-' :
        case '*' :
        case '/' :
        case '$' :
        case '(' :
        case ')' : return 0;
        default  : return 1; 
    }
}

void push(S * ps,char c)
{
    printf("Pushing %c into the stack : \n",c);
    ps->ar[++ps->top] = c ;
    return;
}

char pop(S * ps)
{
    printf("Poping %c out of the stack !!\n",ps->ar[ps->top--]);
    return ps->ar[ps->top+1];
}

int prec(char c)
{
    switch(c)
    {
        case '+'  :
        case '-'  : return 1;
        case  '*' :
        case  '/' : return 2;
        case  '$' : return 3;
        case  '(' :
        case  ')' : return 0;
    }
}