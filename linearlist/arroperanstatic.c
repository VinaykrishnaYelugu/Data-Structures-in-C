#include<stdio.h>
#include<stdlib.h>
# define size 10

void Read(int *);
void Dspla(int *);
void Insrtfrnt(int *p);
void Insrtbak(int *p);
void Deletfrnt(int *p);
void Deletbak(int *p);
void Insrtmidl(int *p);
void Deletmidl(int *p);
void Insrtordr(int *p);
int Search(int *p);
void Sort(int *p);

int n;

void main()
{
    int i,f,Oc,A[size];

 for( ; ; )
 {
    printf("Enter Operation code to be performed: \n");
    printf("1.Read\n2.Display\n3.Insert front\n4.Insert Back\n5.Delete front\n6.Delete back\n7.Insert middle\n8.Delete middle\n");
    printf("9.Insert in order\n10.Search\n11.Sort\n");
    scanf("%d",&Oc);

    switch(Oc)
    {
      case 1 :
       { Read(A) ;  break;  }

      case 2 :
      {   Dspla(A); break; }

      case 3 :
       { Insrtfrnt(A);  break; }

      case 4 :
       { Insrtbak(A); break;  }

      case 5 :
      {  Deletfrnt(A) ; break; }

      case 6 :
      {  Deletbak(A); break; }

      case 7 :
      { Insrtmidl(A); break; }

      case 8 :
      { Deletmidl(A); break; }

      case 9 :
      { Insrtordr(A); break; }

      case 10 :
      { 
        f = Search(A);
        if(f!=-1)
          printf("%d is position of element in the array\n",f);
        else
          printf("Element not found in array\n");
        break; 
      }

      case 11 :
      { Sort(A); break; }

       default :
         exit (0);
    }
 }   
    return ;
}

 void Read(int *p)
 {
    int i;
    printf("Enter array size : \n");
    scanf("%d",&n);
    printf("Enter array elements:\n");
    for(i=0 ; i<n ; i++)
      scanf("%d",(p+i));
    return ;
 }

 void Dspla(int *p)
 {
    int i;
    printf("Array elemenets are: \n");
    for(i=0 ; i<n ; i++)
      printf("%d\t",*(p+i));
    printf("\n");
    return ;
 }

 void Insrtfrnt(int *p)
 {
    int i,m;

    if(n == size)
    { printf("Array full\n"); }
    else
    {
      printf("Enter new number:\n"); scanf("%d",&m);
      for(i=n ; i>0 ; i--)
        *(p+i) = *(p+i-1);
      *(p+i) = m ;
      n++;
    }
    return ;
 }

 void Insrtbak(int *p)
 {
   int i,m;
   if(n==size)
    printf("Array is full\n");
   else
   {
    printf("Enter new number: \n");
    scanf("%d",&m);
    *(p+n)=m;
    n++;
   }
   return ;
 }

 void Deletfrnt(int *p)
 {
  int i;
  if( n==0 )
    printf("Array is empty\n");
  else
   {
    printf("Removing %d\n",*p);
    for(i=0 ; i<n-1 ; i++)
      *(p+i)=*(p+i+1);
    n--;
   }
   return ;
 }

 void Deletbak(int *p)
 {
  if(n==0)
    printf("Array is empty");
  else
    {
      printf("Removing %d\n",*(p+n-1));
      n--;
    }
    return ;
 }
    
void Insrtmidl(int *p)
{
  int i,m,pos;
  if(n==size)
    printf("Enter array is full\n");
  else
  {
    printf("Enter element to be inserted: \n");
    scanf("%d",&m);
    printf("Enter the position of insertion in arrray: \n");
    scanf("%d",&pos);
    for(i=n ; i>pos-1 ; i--)
     *(p+i) = *(p+i-1);
    *(p+i)=m ;
    n++;
  }
  return ;
}

void Deletmidl(int *p)
{
  int i,pos;
  if(n==0)
   printf("Array is empty\n");
  else
  {
    printf("Enter the position of deletion: \n");
    scanf("%d",&pos);
    for(i=pos-1 ; i<n-1 ; i++)
      *(p+i)=*(p+i+1);
    n--;
  }
  return ;
}

void Insrtordr(int *p)
{
  int m,i,pos;
  if(n==size)
   printf("Array is full\n");
  else
  {
    printf("Enter element to be inserted: \n");
    scanf("%d",&m);
    for( i = n-1 ; (i>=0)&&(*(p+i)>=m) ; i--)
        *(p+i+1)=*(p+i);
    *(p+i+1) = m;   
    n++;
  }
  return ;
}

int Search(int *p)
{
  int m,i;
  printf("Enter element to be found: \n");
  scanf("%d",&m);
  for(i=0 ; i<n ; i++)
  {
    if(*(p+i)==m)
     return i+1 ;
  }
  return -1;
}

void Sort(int *p)
{
  int i,j,t;
  for(i=0 ; i<n-1 ; i++)
  {
    for(j=0 ; j<n-i-1 ; j++)
    {
      if( *(p+j+1) <= *(p+j) )
         {
          t= *(p+j);
         *(p+j) = *(p+j+1) ;
         *(p+j+1) = t ;
         }
    }
  }
}
