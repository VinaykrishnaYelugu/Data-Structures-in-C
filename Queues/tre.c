 
// BINARY SEARCH TREES 
// BiINARY SEARCH TREE 
 
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info,ll,rl;
};
typedef struct node sn;

void main()
{
    int choice;
    for( ; ; )
    {
        printf("Enter the choice: \n1-Insert\n2-Delete\n3-Display\n4-Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : 
            case 2 : 
            case 3 : 
            default: printf("Invalid choice !!\n"); break;
        }
    }
}

void insert(sn pf)
{
    sn tp;
      
}