#include<stdio.h>
#include<stdlib.h>
void main()
{
    int i,n;
    printf("Enter number of integers: \n");
    scanf("%d",&n);

    int *ptr = (int *)malloc(n*sizeof(int));

    for(i=0 ;i<n ;i++)
       scanf("%d",ptr+i);
    for(i=0 ;i<n ;i++)
       printf("%d\t",*(ptr+i));
     free(ptr);
    for(i=0 ;i<n ;i++)
       printf("%d\t",*(ptr+i));
    
    return ;
}