#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};
typedef struct node * sn;

sn createnode();
void display(sn );

void insertrear(sn );
void insertfront(sn );
void deletefront(sn );
void deleterear(sn );
void insertbypos(sn );
void deletebypos(sn );
void insertbyorder(sn );
void deletebykey(sn );
sn searchbypos(sn ,int );
int searchbykey(sn ,int );

void main()
{
    int choice,pos,key;
    sn sts,hd=createnode();
    hd->info=0,hd->link=hd;
    for( ; ; )
    {
     printf("Enter the choice\n1-Insert Rear\n2-Insert front\n3-Delete front\n4-Delete rear\n5-Insert by position\n6-Delete by position\n7-Insert by order\n8-Delete by key\n9-Search by position\n10-Search by key\n0-Exit\n");
     scanf("%d",&choice);
     switch(choice)
      {
        case 0 : printf("Terminating program!!\n"); exit(0);
        case 1 : insertrear(hd); display(hd); break;
        case 2 : insertfront(hd); display(hd); break;
        case 3 : deletefront(hd); display(hd); break;
        case 4 : deleterear(hd); display(hd); break;
        case 5 : insertbypos(hd); display(hd); break;
        case 6 : deletebypos(hd); display(hd); break;
        case 7 : insertbyorder(hd); display(hd); break;
        case 8 : deletebykey(hd); display(hd); break;
        case 9 : do{
                   printf("Enter valid position from 1 to %d\n",(hd->info));
                   scanf("%d",&pos);
                   if(pos<1 || pos>(hd->info+1))
                      printf("Invalid positiion!!\n");     
                   }while(pos<1 || pos>(hd->info+1));
                 sts = searchbypos(hd,pos); 
                 printf("Element present in %d is %d\n",pos,sts->info); 
                 display(hd); break;
        case 10 : printf("Enter the valid key :  \n");
                  scanf("%d",&key);
                  pos = searchbykey(hd , key);
                  if(pos >  hd->info )
                     { printf("Search Unsucceess!!\nElement %d not found in list\n",key); break; }
                  printf("Search Success !!%d present at position %d\n",key,pos);
                  display(hd); break;
        default : printf("Invalid choice\n"); break;
     }
    }
}

sn createnode()
{
    sn nn =(sn)malloc(sizeof(struct node));
    return nn;
}

void insertrear(sn hd)
{
   sn tp = hd;
   while(tp->link != hd)
      tp = tp->link;
  sn nn = createnode();
  nn->link = NULL;
  printf("Enter new info :  ");
  scanf("%d",&nn->info);
  tp->link = nn;
  nn->link = hd;
  hd->info++;
}

void insertfront(sn hd)
{
    sn nn=createnode();
    nn->link = NULL;
    printf("Enter new info :  ");
    scanf("%d",&nn->info);
    nn->link = hd->link;
    hd->link = nn;
    hd->info++;
}

void deletefront(sn hd)
{
    if(hd->info == 0)
       return;
    sn dp=hd->link;
    printf("Deleting %d..\n",dp->info);
    hd->link = dp->link;
    free(dp);
    hd->info--;
}

void deleterear(sn hd)
{
    if(hd->info == 0)
       return;
    sn tp=hd,fp=hd;
    while(tp->link != hd)
     { 
      fp = tp;
      tp = tp->link;
     }
    printf("Deleting %d..\n",tp->info);
    fp->link = hd;
    free(tp);
    hd->info--;
}

void insertbypos(sn hd)
{
    int pos,i;
    sn tp = hd;
    do{
        printf("Enter valid position from 1 to %d\n",(hd->info+1));
        scanf("%d",&pos);
        if(pos<1 || pos>(hd->info+1))
            printf("Invalid positiion!!\n");     
    }while(pos<1 || pos>(hd->info+1));

    for(i=1 ; i<pos ; i++)
        tp = tp->link;
    sn nn = createnode();
    printf("Enter new info :  ");
    scanf("%d",&nn->info);
    nn->link = tp->link;
    tp->link = nn;
    hd->info++;
}

void deletebypos(sn hd)
{
    if(hd->info == 0)
       return ;
    int pos,i;
    sn tp = hd;
    do{
        printf("Enter valid position from 1 to %d\n",(hd->info));
        scanf("%d",&pos);
        if(pos<1 || pos>(hd->info))
            printf("Invalid positiion!!\n");     
    }while(pos<1 || pos>(hd->info+1));

    for(i=1 ; i<pos ; i++)
        tp = tp->link; 
    sn dp = tp->link;
    printf("Deleting %d..\n",dp->info);   
    tp->link = dp->link;
    free(dp);
    hd->info--;
}

void insertbyorder(sn hd)
{
   sn tp=hd->link,fp = hd,nn=createnode();
   printf("Enter new info :  "); 
   scanf("%d",&nn->info);
   while((tp!=hd)&&(tp->info < nn->info))
       {
          fp = tp;
          tp = tp->link;
       }
    fp->link = nn;
    nn->link = tp;
    hd->info++;
}

void deletebykey(sn hd)
{
   if(hd->info == 0)
      return ;
   sn tp=hd->link,fp=hd;
   int key;
   printf("Enter the valid key :  ");
   scanf("%d",&key);
   while((tp!=hd)&&(tp->info != key))
       {
          fp = tp;
          tp = tp->link;
       }
   if(tp == hd)
     {
        printf("Element %d not found in list\n",key);
        return ;
     }
   fp->link = tp->link;
   printf("Deleting %d...\n",tp->info);
   free(tp);
   hd->info--;
}

int searchbykey(sn hd,int key)
{
   sn tp=hd->link;
   int cnt=1;
   while((tp!=hd)&&(tp->info != key))
    {  tp = tp->link; cnt++; }
   return (cnt);
}

void display(sn hd)
{
  if(hd->info == 0)
    { printf("List is empty!!\n"); return; }
  sn tp=hd->link;
  printf("Elements in the list are :  ");
  while (tp != hd)
  {
    printf("%d    ",tp->info);
    tp = tp->link;
  }
  printf("\n");
}

sn searchbypos(sn hd,int pos)
{
   sn tp=hd->link;
   int i;
   for(i=1 ; i<pos ; i++)
        tp = tp->link;
    return tp;
}