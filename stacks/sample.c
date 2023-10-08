
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
  int choice,size;
  char *exp;
  stk s;
  s.top = -1;
  s.ca[20] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
  printf("%c\n%c\n",s.ca[s.top],s.ca[1]);
  display(&s);
  for( ; ; )
  {
    printf("Enter the choice\n1-Read\n2-Display\n3-check\nexit\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:   printf("Enter size of character array:  "); scanf("%d",&size);
                exp = (char *)malloc((size+1)*(sizeof(char)));
                do
                {
                 printf("Enter expression: \n");
                 scanf("%s",exp);
                }
                while(strlen(exp)>size);
                break;
     case 2 :   printf("Expression is: \n");
                printf("%s\n",exp);
                break;
     case 3 :   printf("Checking expression \n");
                display(&s);
                check(exp,&s);
                if(s.top == -1)
                   { printf("Valid expression\n"); }
                else
                   { printf("parenthesis are missing!!\n"); }
                break;
 
     default : printf("Invalid!!\n"); exit(0);
   }
  }
}

void check(char *pex,stk *ps)
{
  int i;
  display(ps);
  for(i=0 ; pex[i]!='\0' ; i++)
   {
      if(pex[i]=='(')
      { printf("%c\n",pex[i]);  ps->top++;  ps->ca[ps->top] = pex[i]; display(ps); }
      else if(pex[i]==')')
      { printf("%c\n",pex[i]);  ps->top--; display(ps); } 
      else
      { }
   }
}

void display(stk *ps)
{
printf("Stack content: \n");
printf("%s\n",ps->ca);
}





