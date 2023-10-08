#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
    char sa[50];
    int top;
};
typedef struct stack stk;

char* in2pf(stk* ,char *,char *);
int prec(char);
void push(stk *,char );
char pop(stk *);

void main()
{
    stk s;
    s.top = -1;
    char exp[50],pos[50],*pfex;
    printf("Enter infix expression: \n");
    scanf("%s",exp);
    pfex = in2pf(&s,exp,pos);
    printf("Post fix expression :\n");
    printf("%s",pfex);
}

char * in2pf(stk *ps,char* exp,char *poex)
{
   int i,j=0;
   char cp;
   for(i=0 ; i<strlen(exp); i++)
   {
       switch(exp[i])
       {
        case '(' : push(ps,exp[i]); break;
                   
        case ')' :while(ps->sa[ps->top]!='(');
                   { poex[j++] = pop(ps); } 
                  break;
        case '+' :
        case '-' :
        case '*' :
        case '/' :
        case '^' :
                   while((ps->top!=-1)&&(prec(ps->sa[ps->top])>=prec(exp[i])))
                   {  poex[j++]= pop(ps); }
                   push(ps,exp[i]);
                   break;
        default : poex[j++] = exp[i]; break;
       }
   }
   while(ps->sa[ps->top] != -1)
   {
     poex[j++]=pop(ps);
   }

   return poex;
}

int prec(char ch)
{
    switch(ch)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default : return 0; 
    }
}

void push(stk * ps,char ch)
{
    ps->sa[++ps->top] = ch;
}

char pop(stk *ps)
{
    char ch=ps->sa[ps->top];
    ps->top--;
    return ch;
}