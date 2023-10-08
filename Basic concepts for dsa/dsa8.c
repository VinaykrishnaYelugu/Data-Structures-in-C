#include<stdio.h>

void main()
{
    char s1[15],s2[15],*p1,*p2;
    printf("Enter string 1: \n");
    scanf("%s",s1);
    printf("Enter string 2: \n");
    scanf("%s",s2);
    p1 = s1;
    p2 = s2 ;
    //USING FOR LOOP
    /* 
    for(p1 = s1; *p1 != '\0' ; p1++)
      { }
    for(  ; *p2!=0 ; p2++)
      {
        *p1 = *p2 ;
        p1++ ;
      }
    */ 
   //USING WHILE LOOP
   while(*p1 != '\0')
   p1++;
   while(*p2 != '\0')
   {
    *p1 = *p2;
    p1++;
    p2++ ;
   }
    printf("String Concordinated is : %s",s1);
    return ;
}