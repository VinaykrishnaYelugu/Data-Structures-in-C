#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct opstack
{
    int top;
    float *ar;
};

typedef struct opstack ost;

void evaluate_postfix(char *);
void evaluate_prefix(char *);
int isoperand(char);
void push(ost * ,float);
void pop(ost *);
float compute(float ,float ,char );

void main()
{
    int choice;
    char *posexp = (char *)calloc(30,sizeof(char));

  for( ; ; )
  {
    printf("Enter choice: \n"); 
    printf("1-Evaluation of postfix\n2-2-Evaluation of prefix\n3-Exit\n"); 
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
              printf("Enter the valid postfix expression : \n");
              scanf("%s",posexp);
              evaluate_postfix(posexp);
              break;
      case 2:
              printf("Enter the valid prefix expression : \n");
              scanf("%s",posexp);
              evaluate_prefix(posexp);
              break;
      default: printf("Invalid choice!!\n"); exit(0);
    }
  }
}

void evaluate_postfix(char * exp)
{
   int i=0,t;
   float res,op1,op2,ci;
   ost s;
   ost* ps= &s;
   ps->top = -1;
   ps->ar = (float *)calloc(30,sizeof(char));

   for(i=0 ; i<strlen(exp) ; i++)
   {
     if(isoperand(*(exp+i)))
     {
        ci = *(exp+i)-'0';
        push(ps,ci);
   /*     t = 0;
        while(t<= ps->top)
          printf("%f\t",ps->ar[t--]); 
        printf("\n");*/
     }
     else
     {
        op2 = ps->ar[ps->top];
        pop(ps);
        op1 = ps->ar[ps->top]; 
        pop(ps);
        res = compute(op1,op2,*(exp+i));
        push(ps,res);

   /*     t = 0;
        while(t<= ps->top)
          printf("%f\t",ps->ar[t--]); 
        printf("\n");*/
     }
   }
   printf("Result = %f\n",ps->ar[ps->top]);
}

void evaluate_prefix(char * exp)
{
   int i=0,t;
   float res,ci,op1,op2;
   ost s;
   ost* ps= &s;
   ps->top = -1;
   ps->ar = (float *)calloc(30,sizeof(char));

   for(i=strlen(exp)-1 ; i>=0 ; i--)
   {
     if(isoperand(*(exp+i)))
     {
        ci = *(exp+i)-'0';
        push(ps,ci);
        t = 0;
        while(t <= ps->top)
          printf("%f\t",ps->ar[t++]); 
        printf("\n"); 
     }
     else
     {
        op1 = ps->ar[ps->top];
        pop(ps);
        op2 = ps->ar[ps->top]; 
        pop(ps);
        res = compute(op1,op2,*(exp+i));
        push(ps,res);

        t = 0;
        while(t <= ps->top)
          printf("%f\t",ps->ar[t++]); 
        printf("\n"); 
     }
   }
   printf("Result = %f\n",ps->ar[ps->top]);
}

int isoperand(char ch)
{
    switch(ch)
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

void push(ost * ps,float ch)
{
    printf("Pushing %f into the stack\n",ch);
    ps->ar[++ps->top] = ch;
}

void pop(ost * ps)
{
    printf("Popping %f out of the stack\n",ps->ar[ps->top--]);
}

float compute(float a,float b, char op)
{
    int i,r=1;
    switch(op)
    {
        case '+' : return(a+b);
        case '-' : return(a-b);
        case '*' : return(a*b);
        case '/' : return(a/b);
        case '$' : return (pow(a,b));
    }
}