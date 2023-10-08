#include<stdio.h>
#include<stdlib.h>

struct time 
{
    int hr;
    int min;
    int sec;
};

typedef struct time T;
int n;

void read(T *);
void display(T *,T *);
void upgrade(T *);
T *sum(T *,T *);
T *diff(T *,T *);

void main()
{
  int ch;
  printf("Enter number of time zones: \n");
  scanf("%d",&n);
  T t[n],ts,*ta,*ts1;
  ta = &t[0];
  ts1= &ts ;
  for( ;  ; )
  {
   printf("Enter choice \n1-READ TIME\t2-DISPLAY TIME\t3-UPGRADE TIME\t4-ADDING TWO DIFFERENT TIMES\t5-DIFFERENCING TWO DIFFERENT TIMES\n");
   scanf("%d",&ch);
    
   switch(ch)
   {
     case 1: read(ta); break;
     case 2: display(ta,ts1); break;
     case 3: upgrade(ta); break;
     case 4: sum(ts1,ta); break;
     case 5: diff(ts1,ta); break;

     default: exit(0) ; break;
   }
  }
}

void read(T *ta)
{
  int i;
  for(i=0 ; i<n ; i++)
  {
   printf("Enter time zone %d details: \n",i+1);
   printf("Enter hours: \n"); scanf("%d",&(ta+i)->hr);
   printf("Enter minutes: \n"); scanf("%d",&(ta+i)->min);
   printf("Enter seconds: \n"); scanf("%d",&(ta+i)->sec);
  }
}

void display(T *ta,T *ts1)
{
  int i,ch;
  printf("Enter choice: \n100-Displaying time zone\n200-Display sum/difference between two time zones\n300-Exit\n"); scanf("%d",&ch);
  switch(ch)
  {
  case 100 :
     printf("Enter the time zone number: \n"); scanf("%d",&i);
     printf("Time-%d  :  %d : %d : %d \n",(i),(ta+i-1)->hr,(ta+i-1)->min,(ta+i-1)->sec);
     break;
  case 200 :
     printf("Equivalent Time  :  %d : %d : %d \n",(ts1)->hr,(ts1)->min,(ts1)->sec);
     break;
  default :
     exit(0);
  }
}

void upgrade(T *ta)
{
   int i; 
   printf("Enter the time zone number: \n"); scanf("%d",&i);
   (ta+i-1)->sec++;
   if((ta+i-1)->sec > 59)
     { 
       (ta+i-1)->min = (ta+i-1)->sec/60 + (ta+i-1)->min;
       (ta+i-1)->sec = ((ta+i-1)->sec %60) ;
     }
   if((ta+i-1)->min > 59)
     {
       (ta+i-1)->hr = (ta+i-1)->min/60 + (ta+i-1)->hr;          
       (ta+i-1)->min = ((ta+i-1)->min %60);
     }
   if((ta+i-1)->hr >=24)
     {
      (ta+i-1)->hr = (ta+i-1)->hr/24 ;
     }
         
}

T *sum(T *ts1,T *ta)   
{
  int i,j;
  printf("Enter the two time variables to be entered: \n");
  scanf("%d%d",&i,&j);
  (ts1)->hr = (ta+i-1)->hr + (ta+j-1)->hr;
  (ts1)->min = (ta+i-1)->min + (ta+j-1)->min;
  (ts1)->sec = (ta+i-1)->sec + (ta+j-1)->sec; 

     if((ts1)->sec > 59)
     { 
       (ts1)->min = (ts1)->sec/60 + (ts1)->min;
       (ts1)->sec = ((ts1)->sec %60) ;
     }
     if((ts1)->min > 59)
     {
       (ts1)->hr = (ts1)->min/60 + (ts1)->hr;          
       (ts1)->min = ((ts1)->min %60);
     }
    if((ts1)->hr >=24)
     {
       (ts1)->hr = (ts1)->hr%24  ;
     } 

  return (ts1);
}

T* diff(T *ts1,T *ta)
{
  int i,j;
  printf("Enter the two time in two time zones: \n");
  scanf("%d%d",&i,&j);
  (ts1)->hr = (ta+i-1)->hr - (ta+j-1)->hr;
  (ts1)->min = (ta+i-1)->min - (ta+j-1)->min;
  (ts1)->sec = (ta+i-1)->sec - (ta+j-1)->sec; 

    if(ts1->sec < 0)
    {
     ts1->sec = (60+ts1->sec);
     ts1->min = ts1->min -1;
    }
    if(ts1->min <0)
     {
       ts1->min = (60+ts1->min);
       ts1->hr = ts1->hr -1;
     }
   if(ts1->min <0)
     {
       ts1->min = (60+ts1->min);
       ts1->hr = ts1->hr -1;
     }    
  return ts1;
}


