#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int info;
    struct Node *ll;
    struct Node *rl;
};

typedef struct Node * node;

void insertfront(node);
void insertrear(node);
void deletefront(node);
void deleterear(node);
void insertbypos(node);
void deletebypos(node);
void insertbyorder(node);
void deletebykey(node);
void sort(node);
int search(node);
void reverse(node);

node createnode();
void display(node);

int x;

void main()
{
    int choice,flag;
    node hd = createnode();
    hd->ll = hd;
    hd->rl = hd;
    hd->info = 0;
    for( ;  ; )
    {
        printf("Enter the choice\n1-Insert front\n2-Insert rear\n3-Delete front\n4-Delete rear\n5-Insert by position\n");
        printf("6-Delete by position\n7-Insert by order\n8-Delete by key\n9-sort\n10-Search\n11-Reverse\nexit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insertfront(hd);  display(hd);  break;
            case 2: insertrear(hd);  display(hd); break;
            case 3: deletefront(hd); display(hd); break;
            case 4: deleterear(hd); display(hd); break;
            case 5: insertbypos(hd); display(hd); break;
            case 6: deletebypos(hd); display(hd); break; 
            case 7: insertbyorder(hd); display(hd); break;
            case 8: deletebykey(hd); display(hd); break; 
            case 9: sort(hd); display(hd); break;
            case 10: flag = search(hd); 
                     if(flag == -1)
                        printf("Element not found in the list\n");
                     else
                        printf("Element %d is present at %d\n",x,flag);
                     break;
            case 11: reverse(hd); display(hd); break;

            default: printf("Invalid\n");  exit(0); 
        }
    }
}

node createnode()
{
    node nn = (node)malloc(sizeof(struct Node));
    return nn;
}

void display(node ph)
{
    node tp = ph->rl;
    if(ph->info == 0)
      { printf("List is empty\n"); return; }
    printf("List is : \n");
    while(tp != ph)
    {
       printf("%d     ",tp->info);
       tp = tp->rl; 
    }
    printf("\n");
}

void insertfront(node ph)
{
  node tp,nn;
  nn = createnode();
  printf("Enter the new element : "); scanf("%d",&nn->info);
  tp = ph->rl;

  ph->rl = nn;
  nn->rl = tp;
  nn->ll = ph;
  tp->ll = nn;

  ph->info++;
}

void insertrear(node ph)
{
    node tp,nn;
    nn = createnode();
    printf("Enter the new element:  "); scanf("%d",&nn->info);
    tp = ph->ll;

    tp->rl = nn;
    nn->ll = tp;
    nn->rl = ph;
    ph->ll = nn;

    ph->info++;
}

void deletefront(node ph)
{
    node tp,dp;
    if(ph->info == 0)
        return ;  
    printf("Deleting %d...\n",ph->rl->info);
    tp = ph->rl;
    
    ph->rl = tp->rl;
    ph->rl->ll = ph;

    tp->rl = tp->ll = NULL;
    free(tp);

    ph->info--;
}
