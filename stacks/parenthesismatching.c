
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
  char ca[20];
  int top;
};

typedef struct stack stk;

void check(char *,stk *);
void display(stk *);

void main()
{
  int size,i;
  char *exp;
  stk s;
  s.top = -1;
    for(i=0 ; i<20 ; i++)
     s.ca[i]='\0';

        printf("Enter size of character array:  "); scanf("%d",&size);
                exp = (char *)malloc((size+1)*(sizeof(char)));
                do
                {
                 printf("Enter expression: \n");
                 scanf("%s",exp);
                }
                while(strlen(exp)>size);
        printf("Expression is: \n");
                printf("%s\n",exp);
        printf("Checking expression \n");
                check(exp,&s);
                if(s.top == -1)
                   { printf("Valid expression\n"); }
                else
                   { printf("parenthesis are missing!!\n"); }

}

void check(char *pex,stk *ps)
{
  int i;
  display(ps);
  for(i=0 ; pex[i]!='\0' ; i++)
   {
      if(pex[i]=='(')
      {  ps->top++;  ps->ca[ps->top] = pex[i]; display(ps); }
      if(pex[i]==')')
      { ps->top--; display(ps); } 
   }
}

void display(stk *ps)
{
 for(int i=0; i<=ps->top ; i++)
   printf("%c",ps->ca[i]);
 printf("\n");
}





