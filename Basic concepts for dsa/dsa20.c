#include<stdio.h>
#include<stdlib.h>

void main()
{
    int n,m,i;
    printf("Enter number of integers: \n");
    scanf("%d",&n);

    // memory allocation
    int *ptr=(int *)malloc(n*sizeof(int));
    if(ptr == NULL)
    {
        printf("Memory is full\n");
        exit(1);
    }

    printf("Enter to itegers: \n");
    for(i=0 ; i<n ; i++)
      scanf("%d",ptr+i);
    
    //adding extra 2 more integers to old block

    printf("Enter number extra integers to be added; \n");
    scanf("%d",&m);

    ptr = (int *)realloc(ptr, (n+m)*sizeof(int));
    if(ptr == NULL)
    {
        printf("Memory is full; \n");
        exit (1);
    }

    printf("Enter new integers: \n");
    for(i=n ; i<(n+m) ; i++)
      scanf("%d",ptr+i);

    printf("Entered integers: \n");
    for(i=0 ; i<(m+n) ; i++)
      printf("%d\t",*(ptr+i));
}