#include<stdio.h>
#include<stdlib.h>

struct student
{
  int regno ;
  char name[10];
  int m[3];
  float average;
};

typedef struct student STD ;

void Read(STD *);
void Display(STD *);
void avg(STD *);

int n;

void main()
{
  int ch;
  printf("Enter the number of students: \n");
  scanf("%d",&n);
  STD s[n];
  STD *p=s;
  for( ; ; )
  {
   printf("1.READ\n2.DISPLAY\n");
   printf("Enter choice: \n");
   scanf("%d",&ch);
   switch(ch)
   {
     case 1: Read(p); break;
     case 2: Display(p); break;
     default: exit (0);
   }
  }
}

void Read(STD *p)
{
   int i,j;
   for( i=0 ; i<n ; i++)
   {
    printf("Enter student - %d details\n",i+1);
    printf("Enter reg no : \n"); scanf("%d",&(p+i)->regno);
    printf("Enter name: \n"); scanf("%s",(p+i)->name);
    for( j=0 ; j<3 ; j++)
    {
      printf("Enter Test-%d marks: \n",j+1); scanf("%d",&(p+i)->m[j]);
    }
    avg(p+i);
   }
}

void Display(STD *p)
{
   int i,j;
   for( i=0 ; i<n ; i++)
   {
    printf("Regno : %d\tName : %s\n",(p+i)->regno,(p+i)->name);
    for( j=0 ; j<3 ; j++)
     printf("Test-%d\tMarks:%d\n",(j+1),(p+i)->m[j]);
    printf("Average of best 2: %f\n",(p+i)->average);

    printf("\n");
   }
}

void avg(STD *p)
{
  int j,min,sum=0;
    min = (p)->m[0];
    for( j=0 ; j<n ; j++)
    {
     if((p)->m[j] < min)
        min = (p)->m[j] ;
     sum = sum+ p->m[j] ;
    }
  (p)->average = (sum-min)/2.0;
}