#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student 
{
  int regno;
  char name[10];
  int  marks;
};

typedef struct student S;

int n,size;

S *check(S *);
void read(S *);
void display(S *);
void insertrear(S *);
void insertfront(S *);
void deletefront(S *);
void deleterear(S *);
void insertbypos(S *);
void insertbyorder(S *);
void deletebypos(S *);
void searchname(S *);
void sortmarks(S *);


void main()
{
  int ch;
  printf("Enter the size: \n");
  scanf("%d",&size);
  S st[n];
  S *st1 =st;
   st1=(S *)malloc(size*sizeof(S)); 

  for( ; ; )
  {
   printf("Enter the choice\n"); 
   printf("-1-READ\t0-DISPLAY\t1-INSERTREAR\t2-INSERTFRONT\t3-DELETEFRONT\t4-DELETE REAR\n5-INSERT BY POSITION\t6-INSERT BY OREDER\n");
   printf("7-DELETBYPOS\t8-SEARCH BY NAME\t9-SORT BY MARKS\t10-EXII\n");
   scanf("%d",&ch);
   switch(ch)
   {
    case -1 : read(st1); break;
    case 0 : display(st1); break;
    case 1: insertrear(st1); break;
    case 2: insertfront(st1); break;
    case 3: deletefront(st1); break;
    case 4: deleterear(st1); break;
    case 5: insertbypos(st1); break;
    case 6: insertbyorder(st1); break;
    case 7: deletebypos(st1);   break;
    case 8: searchname(st1); break;
    case 9: sortmarks(st1); break;
    default : exit (0);
    }
   }
}

void read(S * st1)
{
  int i;
  printf("Enter number of students: \n"); scanf("%d",&n);
  st1=check(st1);
  for(i=0 ; i<n ; i++)
  {
   printf("Enter student - %d details\n",i+1);
   printf("Enter registration number: \n"); scanf("%d",&(st1+i)->regno);
   printf("Enter name: \n"); scanf("%s",(st1+i)->name);
   printf("Enter total marks: \n"); scanf("%d",&(st1+i)->marks);
  }
}

void display(S * st1)
{
  int pos;
  //printf("Enter the  student roll no : \n"); scanf("%d",&pos);
   for(pos=1 ; pos<n+1 ; pos++)
   {
   printf("Registration number: %d",(st1+pos-1)->regno);
   printf("        Name: %s",(st1+pos-1)->name);
   printf("        Total marks: %d\n",(st1+pos-1)->marks);
   }
}

void insertrear(S *st1)
{
  st1=check(st1);
  printf("Inserting at rear...\n");
   printf("Enter student - %d details\n",n+1);
   n++;
   printf("Enter registration number: \n"); scanf("%d",&(st1+n-1)->regno);
   printf("Enter name: \n"); scanf("%s",(st1+n-1)->name);
   printf("Enter total marks: \n"); scanf("%d",&(st1+n-1)->marks);

}

void insertfront(S *st1)
{
  int i;
  st1=check(st1);
  printf("Inserting at front: \n");

   for( i=n-1; i>=0 ; i--)
     *(st1+i+1) = *(st1+i);

   printf("Enter stdudent - %d details\n",n+1);
   printf("Enter registration number: \n"); scanf("%d",&(st1)->regno);
   printf("Enter name: \n"); scanf("%s",(st1)->name);
   printf("Enter total marks: \n"); scanf("%d",&(st1)->marks);

   n++;
}

void deletefront(S *st1)
{
    int i;
    printf("Removing first student details: \n");
    for( i=0 ; i<n-1 ; i++)
    {
        *(st1+i) = *(st1+i+1);
    }
    (st1+i)->regno = -1;
    (st1+i)->marks = -1;
    strcpy((st1+i)->name,"REMOVED");
    n--;
}

void deleterear(S *st1)
{
    (st1+n-1)->regno = -1;
    (st1+n-1)->marks = -1;
    strcpy((st1+n-1)->name,"REMOVED");    
    n--;
}


void insertbypos(S *st1)
{
    int i,pos; 
    st1 = check(st1);
    printf("Enter positon of insertion: \n");
    scanf("%d",&pos);
    if((pos>0)&&(pos<n-1))
    {
    for(i=n-1 ; i>=pos-1 ; i--)
        *(st1+i+1) = *(st1+i);
    printf("Enter new student details: \n");
    printf("Enter Regno: \n"); scanf("%d",&(st1+ pos-1)->regno);
    printf("Enter name: \n"); scanf("%s",(st1+pos-1)->name);
    printf("Enter marks: \n"); scanf("%d",&(st1+pos-1)->marks);
    }
    else  
     printf("Enter correct position..\n");
    
    n++;
}

void insertbyorder(S *st1)
{
  int i,m,x;
  printf("Enter new student Regno: \n"); scanf("%d",&m);
  for( i=n-1 ; ((st1+i)->regno>=m)&&(i>=0)  ; i--)
  {
    if((st1+i)->regno>=m)
      *(st1+i+1) = *(st1+i);
  }     
  n++;
  if((st1+i+1)->regno==m)
   {
       for(x=i+2 ; x<n ; x++)
       (st1+x)->regno++;
   }

    printf("Enter new student details: \n");
    printf("Enter name: \n"); scanf("%s",(st1+i+1)->name);
    printf("Enter marks: \n"); scanf("%d",&(st1+i+1)->marks);
    (st1+i+1)->regno = m;
}

void deletebypos(S *st1)
{
    int i,pos;
    printf("Enter position of deletion; \n");
    scanf("%d",&pos);
    if((pos>0)&&(pos<n-1))
    {
    for(i=pos-1 ; i<n-1 ; i++)
      *(st1+i)=*(st1+i+1);
    
    (st1+n-1)->regno = 0;
    strcpy((st1+n-1)->name,"REMOVED");
    (st1+n-1)->marks = 0;
    n--;
    }
    else
     printf("Enter correct position: \n");
}

void searchname(S *st1)
{
  int i,flag=0;
  char keyname[10];
  printf("Enter name to be found: \n");
  scanf("%s",keyname);
  for(i=0 ; i<n ; i++)
  {
    if(strcmp((st1+i)->name,keyname)==0)
     { flag=1; break; }
  }
  if(flag==1)
  { printf("%d exists in the list of students: \n",i+1);
     printf("Student details\nName: %s\tReg no: %d\tMarks: %d\t",(st1+i)->name,(st1+i)->regno,(st1+i)->marks); }
  else
   printf("Student name is not present in the list.. !\n");
}

void sortmarks(S *st1)
{
  int i,j;
  S t;
  for(i=0 ; i<n ; i++)
  {
    for(j=0 ; j<n-i-1 ; j++)
    {
      if((st1+j)->marks < (st1+j+1)->marks)
        {
            t=*(st1+1+j);
            *(st1+j+1) = *(st1+j);
            *(st1+j) = t; 
        }
    }
  }
}

S *check(S *st1)
{
  printf("Reallocating");
  while(n>=size)
  {
    {
        printf("  ..");
        size = size *2 ;
        st1 = (S *)realloc(st1,size*sizeof(S));
    }
  }
  printf("\n");
  return st1;
}

