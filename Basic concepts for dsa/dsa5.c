#include<stdio.h>

void main()
{
   int x,*p1,**p2,***p3;
   p1 = &x ;
   p2 = &p1 ;
   p3 = &p2 ;

   printf("Reading x using p1: \n");
   scanf("%d",p1);
   printf("Displaying x value using p1: \n");
   printf("%d\n",*p1);

   printf("Reading x value using p2: \n");
   scanf("%d",*p2);
   printf("Displaying x value using p2: \n");
   printf("%d\n",**p2);

   printf("Reading x value using p3: \n");
   scanf("%d",**p3);
   printf("Displaying value of x using p3: \n");
   printf("%d\n",***p3);

 return ;
}
   
   
