#include<stdio.h>
#include<string.h>

void Read(char *);
void Display(char *);
void Remove(char *);

char s[10];
void main()
{
    char *p;
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
  int i,j;
  char src[2];
  printf("Enter key element: \n"); scanf("%s",src);
  
  
    for(i=0 ; s[i]!='\0' ; i++)
      {
        if(strcmp(src,s[i]) == 0 )
       {
        for(j=i ; s[j] = '\0' ; j++)
          s[j] = s[j+1];
       }
      }

 return ;
}