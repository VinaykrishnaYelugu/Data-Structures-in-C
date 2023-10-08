#include<stdio.h>

void main()
{

  int x,*p1,*p2,*p3;
   
  p1 =&x;
  printf("Reading x using p1:\n");
  scanf("%d",p1);
  
  //changing value of x using pointer p1
  *p1 = *p1 + 20;
  printf("Dislaying modified value of x using pinter p1:\n");
  printf("%d\n",*p1);
 
  //Reading value of x using pointer p2,p3
  p2 = &x; 
  p3 = &x;
  
  //modifying x value using p2
  *p2 = *p2+5;
  printf("Displaying value of x using pointer p2:\n");
  printf("%d\n",*p2);
 
  //modifying x value using p3
  *p3 = *p3+8 ;
   printf("Displaying value of x using pointe p3: \n");
   printf("%d\n",*p3);

 return ;
}
        