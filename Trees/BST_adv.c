#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *rl,*ll;
};
typedef struct node * sn;

sn insertion(sn );
sn deletion(sn ,int);
sn search(sn ,int );
int max(sn );
int min(sn );
int total_nodes(sn );
int leaf_nodes(sn );
int nonleaf_nodes(sn );
int h_tree(sn );
int d_node(sn ,sn );

void postorder(sn );
void preorder(sn );
void inorder(sn );
void display(sn );
sn createnode();

void main()
{
    int ch;
    int key;
    sn root=NULL,pn,cn;
    for( ; ; )
    {
        printf("Enter the choice : 1-Insertion\n2-Deletion\n3-Search\n4-Display\n5-Max element\n6-Minimum element\n");
        printf("7-Total number of nodes\n8-Number of leaf nodes\n9-Number of non-leaf nodes\n10-Height/Depth of Tree\n");
        printf("11-Depth of node\n12-Height of node\n12-0-Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0 : printf("Terminating program !!\n"); exit(0);
            case 1 : root = insertion(root); break;
            case 2 : printf("Enter the key info :  ");
                     scanf("%d",&key);
                     root = deletion(root,key); 
                     break;
            case 3 : printf("Enter the key info :  ");
                     scanf("%d",&key);
                     pn = search(root,key); 
                     if( pn == NULL)
                      {  printf("Element %d not found in the tree!!!\n",key); break; }
                     else if( pn->info == key )
                      {  printf("Element %d is the root node! \n",key); break; }
                     else 
                     {
                        if(key < pn->info)
                            cn = pn->ll;
                        else //if( key > pn->info)
                            cn = pn->rl;
                     }
                     printf("Element %d found!!\nIt's parent node info = %d\n",cn->info,pn->info);
                     break;
            case 4 : display(root); break;
            case 5 : key = max(root); printf("Maximum element in tree : %d\n",key); break;
            case 6 : key = min(root); printf("Minimum element in tree : %d\n",key); break;
            case 7 : printf("Total number of nodes : %d\n",total_nodes(root)); break;
            case 8 : printf("Total number of leaf nodes : %d\n",leaf_nodes(root)); break;
            case 9 : printf("Total number of non-leaf nodes : %d\n",nonleaf_nodes(root)); break;
            case 10: printf("Height/Depth of Tree : %d\n",(h_tree(root)-1)); break;
            case 11: printf("Enter the key info :  ");
                     scanf("%d",&key);
                     pn = search(root,key); 
                     if( pn == NULL)
                      {  printf("Element %d not found in the tree!!!\n",key); break; }
                     else if( pn->info == key )
                      {  cn = pn; }
                     else 
                     {
                        if(key < pn->info)
                            cn = pn->ll;
                        else //if( key > pn->info)
                            cn = pn->rl;
                     }
                     printf("Depth of node : %d\n",d_node(root,cn));
                     break;
            case 12: printf("Enter the key info :  ");
                     scanf("%d",&key);
                     pn = search(root,key); 
                     if( pn == NULL)
                      {  printf("Element %d not found in the tree!!!\n",key); break; }
                     else if( pn->info == key )
                      {  cn = pn; }
                     else 
                     {
                        if(key < pn->info)
                            cn = pn->ll;
                        else //if( key > pn->info)
                            cn = pn->rl;
                     }
                     printf("Height of node : %d\n",h_tree(root)-1-d_node(root,cn));
                     break; 

            default : printf("Invalid program !!\n"); break;
        }
    }
}

sn insertion(sn r)
{
    int ch;

    for( ; ; )
    {
    printf("Enter 1 to enter info or any other number to stop insertion..\n");
    scanf("%d",&ch);
    if(ch != 1)
      return r;

    
    sn nn,p,fp;
    nn = createnode();
    nn->rl = nn->ll = NULL;
    printf("Enter the new info :  "); 
    scanf("%d",&nn->info);
    if( r == NULL)
    {
       r = nn;
       continue; 
    }
    
    fp = NULL;
    p = r;
    while( p != NULL)
    {
        fp = p;
        if(nn->info < p->info)
          p = p->ll;
        else // nn->info>= p->info
          p = p->rl;
    }
    
    if(nn->info < fp->info )
      fp->ll = nn;
    else //if( nn->info < fp->info)
      fp->rl = nn;
    }     

    return r;
}

sn search(sn p,int key)
{
    if(p == NULL)
      return p;

    sn fp = p;
    if(key < p->info)
      p = p->ll;
    else if(key > p->info)  
      p = p->rl;
    else //if(key == p->info)        // for root node
      return p;
    
    if(p == NULL)
       return p;
    if(p->info == key)
       return fp;
    fp = search(p,key);
    return fp;
}

sn deletion(sn r,int key)
{
   if(r == NULL)
     return r;
   sn pn,cn,gn;
   int flag;
   pn = search(r,key); 
   if( pn == NULL)
    {  printf("Element %d not found in the tree!!!\n",key); return r; }
   else if( pn->info == key )
     {  cn = pn;  }
   else 
    {
     if(key < pn->info)
     cn = pn->ll;
     else //if( key > pn->info)
     cn = pn->rl;
    }

   // if deleting node is a leaf node
 if((cn->ll == NULL)&&(cn->rl == NULL))
  {
   if( cn == pn)
   { 
     printf("Deleting %d..\n",cn->info);
     free(cn);
     return NULL;
   }
   if(cn == pn->ll)
       pn->ll = NULL;
   else //if( cn == pn->rl)
      pn->rl = NULL;
    printf("Deleting %d..\n",cn->info);
    free(cn);
    return r;
  }

    //if deleting node is non leaf node having 2 children
    else if((cn->ll != NULL)&&(cn->rl != NULL))
    {
      sn fp,p;
      //finding inorder successor
      fp = cn;
      p = cn->rl;
      while( p->ll != NULL)
      {
        fp = p;
        p = p->ll;
      }

      if(cn->rl == p)
        fp->rl = p->rl;
      else
        fp->ll = p->rl;
      p->rl = NULL;

      
      p->ll = cn->ll;
      p->rl = cn->rl;


      if(pn == cn)
        r = p;
      else if(pn->ll == cn)
        pn->ll = p;
      else
        pn->rl = p;



        cn->rl = cn->ll = NULL;

      printf("Deleting %d...\n",cn->info);
      free(cn);
      return r ;
    }

    //if deleting node is non leaf node having only one child
    else //if((cn->ll != NULL )||(cn->rl != NULL))
    {
       flag = 0 ;
       if(cn->ll == NULL)
         gn = cn->rl;
       if(cn->rl == NULL)
         gn = cn->ll;

       if(pn->ll == cn)
          pn->ll = gn;
       else if(pn->rl == cn)
          pn->rl = gn;
       else 
          {  flag = 1; }

      cn->rl = cn->ll = NULL;
       printf("Deleting %d....\n",cn->info);
       free(cn);
       if(flag == 1)
          return gn;
       return r;
    }

}


void display(sn r)
{
    if( r== NULL)
    {
        printf("Tree is Empty!!\n");
        return ;
    }
    printf("In-order   : ");
    inorder(r);
    printf("\n");
    printf("Pre-order  : ");
    preorder(r);
    printf("\n");
    printf("Post-order : ");
    postorder(r);
    printf("\n");
}

int max(sn p)
{
  int Max;
  if( p->rl == NULL )
     return p->info;
  Max = max(p->rl);
  return Max;
}

int min(sn p)
{
  int Min;
  if(p->ll == NULL )
     return p->info;
  Min = min(p->ll);
  return Min;
}

int total_nodes(sn p)
{
   if( p == NULL )
      return 0;
   int cnt=0;
   cnt = 1 + total_nodes(p->ll) + total_nodes(p->rl);
   return cnt;
}

int leaf_nodes(sn p)
{
  if(p == NULL)
     return 0 ;
  int cnt=0;
  if((p->rl == NULL)&&(p->ll == NULL))
     return ++cnt;

  cnt = leaf_nodes(p->ll) + leaf_nodes(p->rl);
  printf("%d=>%d\n",p->info,cnt);
  return cnt;
}

int nonleaf_nodes(sn p)
{
  if(p == NULL)
     return 0;
  int cnt=0;
  if( !((p->rl == NULL)&&(p->ll == NULL)) )
      ++cnt;
  cnt = cnt + nonleaf_nodes(p->ll)+nonleaf_nodes(p->rl) ;
  printf("%d => %d\n",p->info,cnt);
  return cnt;
}

int h_tree(sn p)
{
  if(p == NULL)
     return 0 ;
  int h1,h2,h;
  h1 = h_tree(p->ll) ;
  h2 = h_tree(p->rl) ;
  if( h1>h2 )
    h = h1;
  else
    h = h2;
  return ++h;
}

int d_node(sn p,sn cn)
{
   if(p == cn)
    return 0;
   int d;
   if(cn->info < p->info)
      p = p->ll;
   else
      p = p->rl;
   d = d_node(p,cn);
   return ++d;
}

void inorder(sn p)
{
    if( p== NULL )
     return;
    inorder(p->ll);
    printf("%d   ",p->info);
    inorder(p->rl);
}


void preorder(sn p)
{
    if( p== NULL )
     return;
    printf("%d   ",p->info);
    preorder(p->ll);
    preorder(p->rl);
}

void postorder(sn p)
{
    if( p== NULL )
     return;
    postorder(p->ll);
    postorder(p->rl);
    printf("%d   ",p->info);
}

sn createnode()
{
    sn nn = (sn)malloc(sizeof(struct node));
    return nn;
}