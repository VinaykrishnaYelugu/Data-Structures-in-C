#include<stdio.h>
#include<string.h>

void Read(char *);
void Display(char *);
void Remove(char *);

void main()
{
    char s[10],*p;
    p=s;
    Read(p);
    Remove(p);
    Display(p);
    
    return ;
}

void Read(char *q)
{
   printf("Enter string: \n");
   scanf("%s",q);

   return ;
}

void Display(char *q)
{
    printf("String is : \n");
    printf("%s",q);

    return ;
}

void Remove(char *q)
{
    char *r,m;
    r = q;
    printf("Enter char: \n");
    scanf("%c",&m);

    while(*q != '\0')
    {
        r=q ;
        while(*r != '\0') 
        {
            if(*r == m)
             *r = *(++r);
        }
    }
}
