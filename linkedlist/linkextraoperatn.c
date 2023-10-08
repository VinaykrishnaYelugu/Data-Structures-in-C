#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};

typedef struct node *sn;

sn Read(sn);
void Display(sn);
sn Reverse(sn);
sn Searchinsert(sn,int);
sn Insertleft(sn,int);
sn Insertright(sn,int);
sn Deleteinsert(sn,int);
sn Deletefrontofk(sn,int);
sn Deleterearofk(sn,int);
sn Createnode();

int n;

void main()
{
    int i,j;
    sn f=NULL;
    int ch,x,k;
    for( ; ; )
    {
    printf("Enter choice\n1-Read\t2-Display\t3-Reverse\t4-Search\t5-Insert Left\t6-Insert right\t7-Delete Insert\t8-Deletefrontofk\n");
    printf("9-Deleterearofk\tExit\n");
        scanf("%d",&ch);
        switch(ch)
        {
           case 1:
               f = Read(f); break;
           case 2:
               Display(f); break;
           case 3:
               f = Reverse(f); break;
            case 4:
               printf("Enter the key element: "); scanf("%d",&x);
               f = Searchinsert(f,x);
               break;
            case 5:
               do
               {
               printf("Enter the positon between 1 to %d:  ",n); scanf("%d",&k);
               } while ((k<1)||(k>n));
               f = Insertleft(f,k);
               break;
            case 6:
               do
               {
               printf("Enter the positon between 1 to %d:  ",n); scanf("%d",&k);
               } while ((k<1)||(k>n));
               f = Insertright(f,k);
               break;
            case 7 : 
               printf("Enter the valid element:  "); scanf("%d",&x);
               f = Deleteinsert(f,x);
               break;
            case 8 :
               do
               {
               printf("Enter the positon between 2 to %d:  ",n); scanf("%d",&k);
               } while ((k<2)||(k>n));
                f = Deletefrontofk(f,k);
              break;
            case 9:
               do
               {
               printf("Enter the positon between 1 to %d:  ",n-1); scanf("%d",&k);
               } while ((k<1)||(k>n-1));
                f = Deleterearofk(f,k);
               break;
            case 10:
               printf("Enter the respective 2 choices for addresses of specific elements: \n");
           default :
                exit(0);
        }
    }
}

sn Read(sn f)
{
  int i;
  sn tp=f,nn;
  for(i=1 ; i<=n ; i++)
  {
     nn = Createnode();
     printf("Enter the data %d: \n",i); scanf("%d",&nn->info);
     nn->link = NULL;
     if(f == NULL)
     {
       tp = nn;
       f = nn;
     }
     else
     {
       tp->link = nn;
       tp = tp->link;
     }
  }
  return f;
}


void Display(sn f)
{
    int i;
    sn tp =f;
    if(f == NULL)
        printf("Array is empty\n");
    for(i=1 ; i<=n ; i++)
    {
        printf("Data %d - %d\n",i,tp->info);
        tp = tp->link;
    }
}

sn Reverse(sn wn)
{
    printf("Reversing...\n");
    sn tn= wn,cn;
    if(n==0)
      { printf("Array is empty\n"); return wn; }
    if(n==1)
       return wn;
    wn = wn->link;
    tn->link =NULL;
    while(wn->link != NULL)
    {
        cn = wn;
        wn = wn->link;
        cn->link = tn;   /*  cn->link = NULL;  cn->link = tn;   i.e, same as cn->link=tn  */
        tn = cn;
    }
    wn->link = tn;
    return wn;
}

sn Searchinsert(sn f,int x)
{
    int fg=1,pos;
    sn tn=f,nn;
    printf("Searching...");
    pos = 1; 
    while(tn->info != x)
    {
     if(tn->link == NULL)
        {  fg=-1;  break; }
      tn = tn->link;
      pos++;
    }
    if(fg==-1)
    {
    printf("Element %d is not in list!!\n%d is added at the end of the list\n",x,x);
      nn = Createnode();
      nn->link = NULL;
      nn->info = x;
      while(tn->link != NULL)
         tn = tn->link;
      tn->link = nn;
      n++;
    
    Display(f);
    }
    else
    printf("Element %d is present in the list and positon is %d\n",x,pos,x);
    return f;
}

sn Insertleft(sn f, int k)
{
  int ne,i;
  sn tn=f,nn;
  printf("Enter new element: ");  scanf("%d",&ne);
 if(k>=2)
 {
  for( i=1 ; i<(k-1) ; i++ )
  {
    tn = tn->link;
  }
  nn = Createnode();
  nn->info = ne;
  nn->link = tn->link; 
  tn->link = nn;
  n++;
 }
 if(k==1)
 {
    nn = Createnode();
    nn->info = ne;
    nn->link = tn;
    f = nn;
    n++;
 }
  return f;
}

sn Insertright(sn f, int k)
{
  int ne,i;
  sn tn=f,nn;
  printf("Enter new element: ");  scanf("%d",&ne);
 // k = k-1; //as node is to be inserted left of 'k'th positon
  for( i=1 ; i<k ; i++ )
  {
    tn = tn->link;
  }
 if(k==n)
 {
  nn = Createnode();
  nn->info = ne;
  nn->link = NULL;
  tn->link = nn;
  n++;
 }
 else
 {
  nn = Createnode();
  nn->info = ne;
  nn->link = tn->link; 
  tn->link = nn;
  n++;
 }
  return f;
}

sn Deleteinsert(sn f,int x)
{
  sn tn,wn;
  tn=f;
  printf("Searching of %d....\n",x);
  if(tn->info != x)
  {
    while((tn->link)->info != x)
    {
    if((tn->link)->link == NULL)
      { printf("Element %d not found!!\n"); return f;  }
    tn = tn->link;
    }
   if((tn->link)->link != NULL)
   {
    wn = tn;
    wn = wn->link;
    tn->link = (tn->link)->link;
    wn->link = NULL;
    wn->link = f;
    f = wn;
    }
  else
  {
    wn = tn;
    wn = wn->link;
    tn->link = NULL;
    wn->link = f;
    f = wn;
  }
  }
  else
  {
    wn = tn;
    wn = wn->link;
    tn->link = NULL;
    tn->link = wn;
  }
  printf("Element %d is found !!\n",x);
  printf("Deleted %d node from it's position & placed in front of list\n",x);
  return f;
}

sn Deletefrontofk(sn f, int k)
{
  int i=0;
  sn tp=f,cp;
  if((k>2)||(k<=n))
  {
    for(i=1 ; i<k-2 ; i++)
    {
      tp = tp->link;
    }
    cp =tp;
    cp = tp->link;
    tp->link = cp->link;
    cp->link = NULL;
    free(cp);
    n--;
    return f;
  }
  if(k==2)
  {
    cp = tp;
    tp = tp->link;
    cp->link = NULL;
    n--;
    free(cp);
    return tp;
  }
}

sn Deleterearofk(sn f, int k)
{
  int i=1;
  sn tp=f,cp;
  for(i=2 ; i<=k ; i++)
   {
     tp = tp->link;
   }
  if(k<=n-2)
  {
    cp =tp;
    cp = cp->link;
    tp->link = (tp->link)->link;
    cp->link = NULL;
    free(cp);
    n--;
    return f;
  }
  if(k==n-1)
  {
    cp = tp;
    cp = cp->link;
    tp->link = NULL;
    free(cp);
    n--;
    return f;
  }
}


sn Createnode()
{
    sn nn = (sn)malloc(sizeof(struct node));
    return nn; 
}



















