#include<stdio.h>
#include<stdlib.h>

struct POLYNOMIAL
{
    int cf;
    int px,py,pz;
    struct POLYNOMIAL* llink;
    struct POLYNOMIAL* rlink;
};

typedef struct POLYNOMIAL * pl;


pl createnode();
void display(pl);
void read(pl);
void add(pl,pl,pl);

int fl2=0;

void main()
{
    pl ph1,ph2,ph3;
    ph1=(pl)malloc(sizeof(struct POLYNOMIAL));
    ph1->cf= ph1->px =ph1->py =ph1->pz = 0;
    ph1->llink = ph1->rlink = ph1 ;
    ph2=(pl)malloc(sizeof(struct POLYNOMIAL));
    ph2->cf= ph2->px =ph2->py =ph2->pz = 0;
    ph2->llink = ph2->rlink = ph2 ;
    ph3=(pl)malloc(sizeof(struct POLYNOMIAL));
    ph3->cf= ph3->px =ph3->py =ph3->pz = 0;
    ph3->llink = ph3->rlink = ph3 ;
    read(ph1);
    display(ph1);
    read(ph2);
    display(ph2);
    printf("Addition of two polynomials is : \n");
    add(ph1,ph2,ph3);
}

pl createnode()
{
   pl nn=(pl)malloc(sizeof(struct POLYNOMIAL));
   return nn;
}

void read(pl ph)
{
    pl tn,nn;
    for( ;  ; )
    {
        if(ph->cf == 0)
         { nn = createnode(); ph->rlink = nn; nn->llink = ph; nn->rlink = ph ; ph->llink = nn;  }
        printf("Enter the co-efficient:  "); 
        scanf("%d",&nn->cf); ;
        printf("Enter the power of x :  "); scanf("%d",&nn->px);
        printf("Enter the power of y :  "); scanf("%d",&nn->py);
        printf("Enter the power of z :  "); scanf("%d",&nn->pz);

        if( nn->px==0 && nn->py==0 && nn->pz==0)
         { break ; }
         
         tn = createnode();
         tn->rlink = ph;
         ph->llink = tn;
         tn->llink = nn;
         nn->rlink = tn;
         nn = tn;
         ph->cf++;
    }
}

void display(pl ph)
{
    pl tn = ph->rlink;
    while(tn != ph)
    {
        printf("  +(%d)x^%d y^%d z^%d",tn->cf,tn->px,tn->py,tn->pz);

        if( tn->px==0 && tn->py==0 && tn->pz==0)
         { break ; }
         tn = tn->rlink;
    }
    if(fl2==0)
    {  printf("\n"); }
    else
      printf("");
}


void add(pl ph1,pl ph2,pl ph3)
{
   int cnt=1,flag;
   pl tn1,tn2 = ph2->rlink,tn3,nn,ep,cp1,cp2;
for( ; ; )
{
   tn1 = ph1->rlink;
   flag = 0;
   while( tn1 != ph1)
   {

           if((tn2->px == tn1->px)&&(tn2->py == tn1->py)&&(tn2->pz == tn1->pz))
           {
           flag = 1;
            tn3 = createnode();
            tn3->cf = tn1->cf + tn2->cf;
            tn3->px = tn1->px ;
            tn3->py = tn1->py ;
            tn3->pz = tn1->pz ;

            ep = tn1->llink;
            ep->rlink = tn1->rlink ;
            ep->rlink->llink = ep;
           }
           tn1 = tn1->rlink;
   }
   if(flag==0)
   {   
      tn3 = createnode();
      tn3->cf = tn2->cf;
      tn3->px = tn2->px ;
      tn3->py = tn2->py ;
      tn3->pz = tn2->pz ;
   }
   if( cnt == 1)
    { ph3->rlink = tn3 ; tn3->rlink = ph3 ; tn3->llink = ph3; ph3->llink = tn3;   nn = tn3;  }
   else
   { 
     tn3->rlink  = ph3 ; ph3->llink = tn3 ; nn->rlink = tn3 ; tn3->llink=nn ; 
     nn = tn3;
    }
    display(ph1);
    cnt++;
  if(tn2->rlink == ph2)
  {  break ; }
  tn2 = tn2->rlink;
}
    tn1 = ph1->rlink;
    if(tn1 != ph1)
    {
        fl2=1;
        display(ph3);
        display(ph1);
    }
    else
        display(ph3);

 /*   display(ph1);
    tn1 = ph1->rlink;
    tn3 = ph3->llink;
    if(tn1 != ph1)
    {
      tn1->llink = NULL;
      ph1->rlink = NULL;
      cp1 = tn1;
      while(tn1->rlink != ph1)
          tn1 = tn1->rlink; 
      cp2 = tn1;
      tn1->rlink = NULL;
      ph1->llink = NULL;

      tn3->rlink = ph1->llink = NULL;
      tn3->rlink = cp1;
      cp1->llink = tn3;

      cp2->rlink = ph3;
      ph3->llink = cp2;
    }
    display(ph3);
    */
}

