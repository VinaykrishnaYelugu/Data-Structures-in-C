#include<stdio.h>
#include<stdlib.h>

struct node
{
  int info;
  struct node *link;
};

typedef struct node * sn;

sn Read( sn );
void Display(sn);
sn Insertfront(sn );
void Insertrear(sn);
sn Insertbypos(sn);
sn Insertorder(sn);
sn Deletefront(sn);
void Deleterear(sn);
sn Deletebypos(sn);
sn Deletebykey(sn);
int Search(sn);
void Sort(sn);
sn Createnode();

int n;

void main()
{
  sn f=NULL;
  int ch,flag;
  for( ; ;)
  {
  printf("Enter choice: \n");
  printf("1-Read\t2-Display\t3-Insert front\t4-Insert rear\t5-Insert by position\t6-Insert by order\t7-Delete front\t8-Delete rear\n");
  printf("9-Delete by position\t10-Delete by key\t11-Search\t12-Sort\t13-Exit\n");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1 : 
      f = Read(f); break;
    case 2 :
      Display(f) ; break;
    case 3 :
      f = Insertfront(f); break;
    case 4:
          Insertrear(f); break;
    case 5:
      f = Insertbypos(f); break;
    case 6:
      f = Insertorder(f); break;
    case 7:
      f = Deletefront(f); break;
    case 8:
      Deleterear(f); break;
    case 9:
      f = Deletebypos(f); break;
    case 10:
      f = Deletebykey(f); break;
    case 11:
      flag = Search(f);
      if(flag == 0)
        printf("Element is not present\n");
      break;
    case 12:
       Sort(f); break;
    default :
      exit(0);
  }
  }
}

sn Read(sn f)
{
  int i;
  sn tp=f,nn;
  printf("Enter number of elements: \n"); scanf("%d",&n);
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

sn Insertfront(sn f)
{
 sn nn = Createnode();
 printf("Enter new element:  "); scanf("%d",&nn->info);
 nn->link = f ;
 f = nn;
 n++;
 return f;
}

void Insertrear(sn f)
{
  sn nn,tn;
  tn = f;
  nn = Createnode();
  printf("Enter new element :  "); scanf("%d",&nn->info);
  nn->link = NULL;
  while(tn->link!=NULL)
  {
    tn = tn->link;
  }
  tn->link = nn;
  n++;
}

sn Insertbypos(sn f)
{
  int pos,i;
  sn tn,nn;
  tn = f;
l:
  printf("Enter the position from 1 to %d : ",n+1); scanf("%d",&pos);
  if((pos<1)||(pos>n+1))
    goto l;
  nn = Createnode();
  printf("Enter the new element : "); scanf("%d",&nn->info);
  nn->link = NULL;

  if(pos==1)
  {
    nn->link = tn;
    f = nn;
    n++;
    return f;
  }

  for(i=1 ; i<pos-1 ; i++)
  {
    tn = tn->link;
  }
  nn->link = tn->link;
  tn->link = nn;
  n++;
  return f;
}

sn Insertorder(sn f)
{
  sn nn,tn;
  int i,count=1,pos;
  tn = f;
  nn = Createnode();
  printf("Enter the new element:  "); scanf("%d",&nn->info);
  nn->link =NULL;

  while(tn->info < nn->info)
  {
    count++;
    if(count==n+1)
      break;
    tn = tn->link;
  }
  pos = count;
  tn = f;

  if(pos==1)
  {
    nn->link = tn;
    f = nn;
    n++;
    return f;
  }

  for(i=1 ; i<pos-1 ; i++)
  {
    tn = tn->link;
  }
  nn->link = tn->link;
  tn->link = nn;
  n++;
  return f;

}

sn Deletefront(sn f)
{
  sn tn;
  tn=f;
  printf("Deleting %d element... \n",tn->info);
  f = tn->link;
  free(tn);
  n--;
  return f;
}

void Deleterear(sn f)
{
  sn tn;
  tn = f;
  while((tn->link != NULL)&&((tn->link)->link != NULL))
  {
    tn = tn->link;
  }
  free(tn->link);
  tn->link = NULL;
  n--;
  return ;
}

sn Deletebypos(sn f)
{
  int pos,count;
  sn tn,en;
  tn = f;
  l:
    printf("Enter the position between 1 and %d\n",n);
    scanf("%d",&pos);
    if(pos<1 || pos>n)
       goto l;
    for(count= 1 ; count<pos-1 ; count++)
    {
      tn = tn->link;
    }
    if(pos>1)
    {
     en = tn->link;
     tn->link = (tn->link)->link;
     free(en);
     n--;
     return f;
    }
    else
    {
      f = tn->link;
      free(tn);
      n--;
      return f;
    }
}

sn Deletebykey(sn f)
{
  int ne;
  sn tn,en;
  tn =f;
    printf("Enter the valid key element: \n"); scanf("%d",&ne);
    if(tn->info != ne)
    {
      while((tn->info != ne)&&((tn->link)->info != ne))
      {
        tn = tn->link;
        if(tn->link == NULL)
          {
            printf("Invalid key element!!\n");
            return f;
          }
      }
      en = tn->link;
      tn->link = (tn->link)->link;
      free(en);
      n--;
      return f;
    }
    else
    {
     f = tn->link;
     free(tn);
     n--;
     return f;
    }
}

int Search(sn f)
{
  int ne,count=1;
  sn tn;
  printf("Enter the key element : \n"); scanf("%d",&ne);
  tn = f;
  while(tn->info != ne)
  {
     if(tn->link == NULL)
      {  return 0 ;}
     tn = tn->link;
     count++;
  }
  printf("Element found!!\tPosition of %d is %d\n",tn->info,count);
  return 1;
}

void Sort(sn f)
{
  sn tn;
  int i,j,t;
  for(i=0 ;i<n ; i++)
  {
    tn = f;
    for(j=0 ; j<n-i-1 ; j++)
    {
      if((tn->link)->info < tn->info )
      {
       t = tn->info;
       tn->info = (tn->link)->info;
       (tn->link)->info = t; 
      } 
      tn = tn->link;
    }
  }
}

sn Createnode()
{
  sn nn;
  nn = (sn)malloc(sizeof(struct node));
  return nn;
}

