#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *rl,*ll;
};
typedef struct node* sn;

sn insertion(sn );
void display(sn );
void inorder(sn );
void preorder(sn );
void postorder(sn );
void max(sn );
void min(sn );
int total_nodes(sn );
int non_leaf(sn );
int leaf(sn );
int h_tree(sn );
int d_node(sn ,int );
sn search(sn ,int);
sn delete(sn , int);

void main()
{
    int choice,key,sts;
    sn root=NULL,pn,cn;
    for( ; ; )
    {
       printf("Enter the choice : \n1-Insertion\n2-Display\n3-Search\n4-Delete\n5-Maximum element\n6-Minimum element\n7-Total number of nodes\n");
       printf("8-Number of non leaf nodes\n9-Number of leaf nodes\n10-Height of node\n11-Depth of node\n12-Height/Depth of tree\n0-Exit\n");
       scanf("%d",&choice);
       switch(choice)
       {
          case 0 :  printf(" Terminating program !!\n"); exit(0);
          case 1 :  root = insertion(root); break;
          case 2 :  display(root); break;
          case 3 :  printf("Enter the key element :  ");
                    scanf("%d",&key);
                    pn = search(root,key);
                    if( pn == NULL)
                       {
                         printf("Key element %d not found in Tree!!\n",key);
                         break;
                       }
                    else if(pn->info == key)
                       {
                         printf("Key element %d is root node!!\n",pn->info);
                         break;
                       }
                    else if(key < pn->info)
                       cn = pn->ll;
                    else
                       cn = pn->rl;
                    printf("Key node info = %d\nParent node of the key = %d\n",cn->info,pn->info);
                    break; 
          case 4 :  printf("Enter the valid key element to be deleted :  ");
                    scanf("%d",&key);
                    root = delete(root,key);
                    break;
          case 5 :  max(root); break;
          case 6 :  min(root); break;
          case 7 :  printf("Total number of nodes in Tree :  %d\n",total_nodes(root)); break;
          case 8 :  printf("Number of non leaf nodes :  %d\n",non_leaf(root)); break;
          case 9 :  printf("Number of leaf nodes :  %d\n",leaf(root)); break;
          case 10:   printf("Enter the node's info :  ");
                    scanf("%d",&key);
                    sts = d_node(root,key);
                    if(sts == -1)
                      { printf("Invalid node info!!\n"); break;  }
                    printf("Height of node is = %d\n",h_tree(root)-1-sts); break;
          case 11:  printf("Enter the node's info :  ");
                    scanf("%d",&key);
                    sts = d_node(root,key);
                    if(sts == -1)
                      { printf("Invalid node info!!\n"); break;  }
                    printf("Depth of node is = %d\n",sts); break;
          case 12:  printf("Height/Depth of tree is = %d\n",h_tree(root)-1); break;
          default:  printf("Invalid program!!\n"); break;
       }
    }
}

sn createnode()
{
    sn nn = (sn)malloc(sizeof(struct node));
    return nn;
} 

sn insertion(sn r)
{
    int ch;
    for( ; ; )
    {
      printf("Enter any number to insert or -1 to stop insertion");
      scanf("%d",&ch);
      if( ch == -1)
        return r;
      sn nn = createnode();
      nn->rl = nn->ll = NULL;
      printf("Enter the new info : "); scanf("%d",&nn->info);
      if(r == NULL)
       {
         r = nn;
         continue;
       }
      sn p = r,fp = NULL;
      while(p != NULL)
      {
        if(nn->info < p->info )
          {
            fp = p;
            p = p->ll;
          }
        else //if(nn->info >= p->info )
          {
            fp = p;
            p = p->rl;
          }
      }
      if(nn->info < fp->info )
         fp->ll = nn;
      else // if(nn->info >= fp->info )
         fp->rl = nn; 
    }
    return r;
}

void display(sn r)
{
    sn p=r,pf=NULL;
    if( r == NULL)
      {
       printf("Tree is empty!!\n"); 
       return;
      }
    printf("Inorder   : ");
    inorder(r);
    printf("\n");
    printf("Preorder  : ");
    preorder(r);
    printf("\n");
    printf("Postorder : ");
    postorder(r);
    printf("\n");
}

void inorder(sn p)
{
    if(p == NULL)
      return;
    // p != NULL
    inorder(p->ll);
    printf("%d   ",p->info);
    inorder(p->rl);
    return;
}

void preorder(sn p)
{
    if (p == NULL)
       return;
    
    printf("%d   ",p->info);
    preorder(p->ll);
    preorder(p->rl);
    return;
}

void postorder(sn p)
{
    if(p == NULL)
      return;

    postorder(p->ll);
    postorder(p->rl);
    printf("%d   ",p->info);
}

sn search(sn p,int key)
{
  sn fp = p;
  if( p == NULL)
     return p;
//  if( p->info == key )
//       return p;
  else if(key < p->info)
   {  
      //fp = p;
      p = p->ll;
   //  if( p == NULL)
   //      return p;
   //   if(p->info == key)
   //      return fp;
   //   fp = search(p,key);
   //   return fp;
   }
  else if(key > p->info)
   {  
      //fp = p;
      p = p->rl;
     // if( p == NULL)
     //     return p;
     // if(p->info == key)
     //    return fp;
    //  fp = search(p,key);
    //  return fp;
   }
  else if( key == p->info) 
     return fp;  
     
 if( p == NULL)
    return p;
 if(p->info == key)
    return fp;
 fp = search(p,key);
     return fp;
 // else
   //  fp = NULL;
 // return fp;
}

sn delete(sn r, int key)
{
  sn pn,cn,gn,fp,p;
  int flag;
  pn = search(r,key);
  if(pn == NULL)
    {
      printf("Element %d not found in the tree!!\n",key);
      return r;
    }
  else if( key == r->info )
    {
      cn = pn;
    }
  else if( key < pn->info )
      cn = pn->ll;
  else //if( key >= pn->info )
      cn = pn->rl;

  // if node is an leaf node
  if(( cn->ll == NULL) &&( cn->rl == NULL ))
    {
      flag = 0;
      if( r->info == key )
            flag = 1;

      if(key < pn->info)
        pn->ll =  NULL;
      else // if(key >= pn->info)
        pn->rl = NULL ;
      printf("Deleted %d..\n",cn->info);
      free(cn);
      if( flag == 1 )
         return NULL;
      return r;
    }
  
  // if deleting node is a non leaf node with only 1 child
  else if( (cn->ll == NULL)||(cn->rl == NULL) )
    {
      flag = 0;
      if( r->info == key )
            flag = 1;

        if(cn->rl == NULL)
          gn = cn->ll;
        if(cn->ll == NULL)
          gn = cn->rl;

      if(cn == pn->ll)
      {
       // if(cn->rl == NULL)
       //   gn = cn->ll;
       // if(cn->ll == NULL)
       //   gn = cn->rl;
        pn->ll = gn;
      }

      else
      {
       // if(cn->rl == NULL)
       //   gn = cn->ll;
       // if(cn->ll == NULL)
       //   gn = cn->rl;
        pn->rl = gn;
      }
      printf("Deleted %d...\n",cn->info);
      free(cn);
      if(flag == 1)
          return gn;
      return r;
    }
// if deleting node is having 2 childeren
else if((cn->ll != NULL) && (cn->rl != NULL))
{
// Finding inorder successor
   // 'cn' is deletable node
   fp = cn;
   p = cn->rl;

   while(p->ll != NULL)
   {
    fp = p;
    p = p->ll;  
   }              // p points to inorder successor,fp will be consecutive predecessor of p
   
 // removing the inorder successor from it's position and placing it inplace deleting node  
   if( cn->rl == p)   // if inorder successor is consecutive to deleting node i.e consective successor of deleting node is having 1 or no children
     fp->rl = p->rl;  // for joining predeccessor and child of inorder successor 
   else //if inorder successor is not consecutive to deleting node i.e,consecutive successor of deleting node is having 2 children
     fp->ll = p->rl;  // for joining predeccessor and child of inorder successor 
   p->rl = NULL;  // removing inorder successor from it's position

   p->rl = cn->rl; // -|
                   //  |=> linking predeccessor with children of the deleting node
   p->ll = cn->ll; // -|
   
   flag = 1;       // To find whetherdeleting node is an root node or not

   if(cn != r)         // if deleting node is not a root node then linking parent of deleting node with inorder successor i.e 'p'
   {
     if(pn->rl == cn)
       pn->rl = p;
     if(pn->ll == cn)
       pn->ll = p;
     flag = 0;
   } 

   cn->ll = cn->rl = NULL; //removing the deletable node 'cn'
   free(cn);               //deleting the deletable node 'cn' 

   if(flag == 1)
     return p;     // if root node is deleted the inorder successor 'p' will be new root
   else
     return r;
  }

}

void max(sn r)
{
  if( r == NULL )
    {
      printf("Tree is empty!!\n");
      return;
    }
  sn p=r;
  while(p->rl != NULL)
     p = p->rl;
  printf("Maximum element in the tree is :  %d\n",p->info);
  return;
}

void min(sn r)
{
  if( r == NULL )
   {
    printf("Tree is empty!!\n");
    return;
   }
  sn p = r;
  while(p->ll != NULL)
    p = p->ll;
  printf("Minimum element in the tree is :  %d\n",p->info);
  return;
}

int total_nodes(sn p)
{
  if( p == NULL)
    return 0;
  int cnt = 0;
  cnt = 1+ total_nodes(p->ll)+total_nodes(p->rl);
  return cnt;
}

int non_leaf(sn p)
{
  if(p == NULL)
    return 0;
  int cnt=0;
  cnt = non_leaf(p->ll) + non_leaf(p->rl);
  if( !((p->ll==NULL)&&(p->rl==NULL)) )
    cnt++;
  return cnt;
}

int leaf(sn p)
{
   if( p== NULL )
      return 0;
   int cnt = 0;
   cnt = leaf(p->ll) + leaf(p->rl);
   if( (p->rl == NULL)&&(p->ll == NULL) )
     cnt++;
   return cnt;
}

int h_tree(sn p)
{
  if(p == NULL)
    return 0;
  int h1,h2,h;
  h1 = h2 = h = 0;

  h1 = h_tree(p->ll);
  h2 = h_tree(p->rl);

  if( (p->ll==NULL) && (p->rl==NULL) )
      return 1;
  if(h1>h2)
    h = h1;
  else 
    h = h2;
  return ++h;
}

int d_node(sn p,int key)
{
   sn fp = p;
   int cnt = 0;
  if( p == NULL)
     return -1;
  else if(key < p->info)
      {
        p = p->ll;
      }
  else if(key > p->info)
      {
        p = p->rl;
      }
  else if( key == p->info) 
     {
      return 0;  
     }
          
 if( p == NULL)
    return -1;
 if(p->info == key)
    return 1;
 cnt = d_node(p,key);
 if(cnt == -1)
     return -1;
     return ++cnt;
}