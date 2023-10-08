#include<stdio.h>

void main()
{
  int *p,i,n;
  printf("Enter number of array elements: \n");
  scanf("%d",&n);
  int a[n];
  
  p = a;
//INDEXING
  printf("Reading values by indexing: \n");
  for(i=0 ; i<n ;i++)
    scanf("%d",&a[i]);
  printf("Displaying array elements by indexing method: \n");
     for(i=0 ; i<n ;i++)
       printf("%d\t",a[i]);
       printf("\n");
//POINTER ACCESSING
  printf("Reading values by pointer accesing: \n");
  //KEEPING POINTER VALUE CONSTANT
   printf("Reading array elements by pointer accessing keeping pointer constant :\n");
   for(i=0 ;i<n ;i++)
     scanf("%d",(p+i));
   printf("Reading array elements by pointer accessing keeping pointer constant: \n");
   for(i=0 ; i<n ; i++)
     printf("%d\t",*(p+i));
     printf("\n");
   //BY INCREMENTING POINTER VALUE
    printf("Reading array elements by pointer accessing by changing pointer value: \n");
     for(p=a ; p<a+n ;p++)
       scanf("%d",p);
    printf("Displaying array elements by pointer accessing by changing pointer value: \n");
      for(p=a ; p<a+n ; p++)
        printf("%d\t",*p);

 return ;
}
     
   
