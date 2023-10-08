#include<stdio.h>
#define n 2

struct student
{
    char name[10];
    float marks;
};

void main()
{
    int i;
    struct student S[n];
    struct student *ptr;
      ptr = S;
    //read
    for(ptr = S,i=0 ; ptr< S+n ; ptr++)
    {
        printf("Enter student %d data\n",i+1);
        printf("name : \n"); scanf("%s",ptr->name);
        printf("marks: \n"); scanf("%f",&ptr->marks);
        i++;
    }
    for(i=0 ; i<n ; i++)
    {
        ptr = S;
        printf("Enter student %d data\n",i+1);
        printf("name : \n"); scanf("%s",(ptr+i)->name);
        printf("marks: \n"); scanf("%f",&(ptr+i)->marks);
    }
    //display
    for(ptr = S,i=0 ; ptr< S+n ; ptr++)
    {
        printf("student %d data\n",i+1);
        printf("name : \n"); printf("%s\n",ptr->name);
        printf("marks: \n"); printf("%f\n",ptr->marks);
        i++;
    }
    for(i=0 ; i<n ; i++)
    {
        ptr = S;
        printf("student %d data\n",i+1);
        printf("name : \n"); printf("%s\n",(ptr+i)->name);
        printf("marks: \n"); printf("%f\n",(ptr+i)->marks);
    }
}