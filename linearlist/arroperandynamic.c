#include<stdio.h>
#include<stdlib.h>

int * read(int *);
void display(int *);
int * insertfront(int *);
int * insertrear(int *);
int * insertbypos(int *);
int * insertorder(int *);
void deletefront(int *);
void deleterear(int *);
void deletebypos(int *);
int * re_alloc(int *);
void search(int *);
void sort(int *);
int * check(int *);

int n,size;

void main()
{
    int ch,a[size],*p;
    printf("Enter the size of the array: \n");
    scanf("%d",&size);
    p = a ;
    p = (int *)malloc(size*sizeof(int));
    if(p == NULL)
      {  printf("Memory is full in heap\n"); exit(0); }
    
    for( ; ;)
    {
     printf("1-READ\n2-DISPLAY\n3-INSERT FRONT\n4-INSERT REAR\n5-INSERT BY POSITION\n6-INSERT ORDER\n");
     printf("7-DELETE FRONT\n8-DELETE REAR\n9-DELETE BY POSITION\n10-SORT\n11-SEARCH\n12-EXIT\n");
     printf("Enter choice\n");
     scanf("%d",&ch);
     
     switch(ch)
      {
       case 1 : p = read(p); break; 
       case 2 : display(p); break;
       case 3 : p = insertfront(p); break; 
       case 4 : p = insertrear(p); break;
       case 5 : p = insertbypos(p); break;
       case 6 : p = insertorder(p); break;
       case 7 : deletefront(p); break;
       case 8 : deleterear(p); break;
       case 9 : deletebypos(p); break;
       case 10: sort(p) ; break;
       case 11: search(p) ; break;
       
       default : exit(0);    
      }
     }
}

int * read(int *p)
{  
   int i;
   printf("Enter the number of elements of array: \n");
   scanf("%d",&n);
   p=check(p);
   printf("Enter array elements:\n");
   for(i=0 ; i<n ; i++)
     scanf("%d",(p+i));

    return p;
}

void display(int *p)
{
   int i;
   printf("Array elements: \n");
   for(i=0 ; i<n ; i++)
     printf("%d\t",*(p+i));
   printf("\n");

   return ;
}

int *insertfront(int *p)
{
   int i,ne;
   p = check(p);
   printf("Enter new elements: \n");
   scanf("%d",&ne);
   for( i =n-1 ; i>=0 ; i--)
      *(p+i+1)=*(p+i);
   *(p)=ne;
   n++;

   return p;
}

int *insertrear(int *p)
{
   int ne;
   p = check(p);
   printf("Enter new element: \n");
   scanf("%d",&ne);
   *(p+n) = ne;
   n++;
  
   return p;
}

int * insertbypos(int *p)
{
   int ne,pos,i;
   p = check(p);
   printf("Enter new element : \n");
   scanf("%d",&ne);
   printf("Enter the position of insertion: \n");
   scanf("%d",&pos);
   for(i=n-1 ; i>=pos-1; i--)
    {  if((pos==n+1))
         i++; 
      *(p+i+1) = *(p+i);
    }
   if(pos>n+1)
    { printf("Enter valid position... \n"); return p; }
   *(p+i+1) = ne;
   n++;
  
   return p;
}

int * insertorder(int *p)
{
  int i,ne;
  p = check(p);
  sort(p);
  printf("Enter new element : \n");
  scanf("%d",&ne);
  for( i=n-1 ; (i>=0)&&(*(p+i)>=ne) ; i--)
    *(p+i+1) = *(p+i);
  *(p+i+1) = ne ;
  n++;

  return p;
}

void deletefront(int *p)
{
    int i;
    for(i=0 ; i<n-1 ; i++)
      *(p+i) = *(p+i+1);
    n--;
}

void deleterear(int*p)
{
    n--;   
}

void deletebypos(int *p)
{
    int i,pos;
    printf("Enter position of deletion: \n");
    scanf("%d",&pos);
    for( i=pos-1 ; i<n-1 ; i++)
      *(p+i) = *(p+i+1);
    if(pos>n)
      { printf("Enter valid position... \n"); return ; }
    n--;

    return ;
}


int * check(int*p)
{
   if(n>=size)
    {
     printf("Reallocating... \n");
     p = (int *)realloc(p,size*2*sizeof(int));     
     return p;
    }
   else 
    return p;
}

void search(int *p)
{
  int i,f=0,k;
  printf("Enter key element: \n");
  scanf("%d",&k);
  for(i=0 ; i<n ; i++)
    if(*(p+i)==k)
      { f=1 ; break; }
    if(f==1)
     printf("Element exist...\n%d position is %d\n",k,i+1);
    else
    printf("Element is not there in array! \n");
  
  return ;
}

void sort(int *p)
{
   int i,j,t;
   for(i=0 ; i<n ; i++)
   {
     for(j=0 ; j<n-i-1 ; j++)
     {
      if(*(p+j+1)<=*(p+j))
       {
         t=*(p+j);
         *(p+j)=*(p+j+1);
         *(p+j+1)=t ;
       }
     }
   }

   return ;
}