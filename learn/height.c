//nodedepth.c
#include<stdio.h>
#include<stdlib.h>

struct Tree
{  int data;
   struct Tree *lptr;
   struct Tree *rptr;
};

typedef struct Tree node;
node *createtree(node *root);
node *insert(int n,node *root);

void finddepth(int n,node *root);
void main()
{
int n;
    node *root=NULL;
    root=createtree(root);
    printf("Enter node:");
    scanf("%d",&n);
    finddepth(n,root);
}
node *createtree(node *root)
{ 
int n;
do
{ 
  printf("\nEnter number<0 to stop>:");
  scanf("%d",&n);
  if(n!=0)
  root= insert(n,root);
}   while(n!=0);
return(root);
}
node *insert(int n,node *root)

{

   node *temp1=NULL;
   node *temp2=NULL;
   node *p=NULL;
        p=(node *)malloc (sizeof(node));//dynamic allocation of memory foe each element
        p->data=n;    //initialize contents of the structure
        p->lptr=NULL;
        p->rptr=NULL;
 //A new node has been created now our task is to insert this node
 //in the appropriate place.If this is the first node to be created

 //then this is the root of the tree.
 if(root==NULL)
 root=p;
 else
 // We will use temp1 for traversing the tree.
 // Temp2 will be traversing parent
 // p is the new node we have created.

{
  temp1=root;
  while(temp1!=NULL)
   {
    temp2=temp1; // store it as parent
    // Traverse through left or right sub tree
    if(p->data < temp1->data)
           temp1 = temp1->lptr;  // left subtree
    else
      if(p->data > temp1->data)
           temp1 = temp1->rptr; // right sub tree
    else
    {
    printf("\n\tDUPLICATE VALUE");
    free(p);
    break;
    }//enode else
   } //end of while

  // we have trvered to the end of tree

  // node ready for insetion

   if(temp1 == NULL)

   { // attach either as left son or right son of parent temp2
 if(p->data<temp2->data)
          temp2->lptr=p; // attach as left son
                 else
           temp2->rptr=p; // attach as right son
   }

}//end of else
     return(root);

 }//end of insert tree
void finddepth(int n,node *root)
{
   node *p=root;
   int i=0;
   while(p->data!=n)

   {
    if(p->data>n)
    p=p->lptr;
    else
    p=p->rptr;

  i++;
  if(p==NULL)
 {
  printf("node does not exist in the tree");
  exit(1);
    }
 }
  printf("Depth=%d",i);
} 