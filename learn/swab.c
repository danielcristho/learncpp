//SWAB TREE
#include<stdio.h>
#include<stdlib.h>

struct Tree
{
  int data;
  struct Tree *lptr;
  struct Tree *rptr;

};

typedef struct Tree node;
node *stk[30];
int tos=-1;    //stack data structure
node *createtree(node *root);
node *insert(int n,node *root);
void inorder(node *root);
void swap(node *root);
void main()
{
node *root=NULL;
root=createtree(root);
printf("inorder traversal before swapping: ");
    inorder(root);
    swap(root);
    printf("\ninorder traversal after swapping: ");
    inorder(root);
}
void swap(node *root)
{
  node *temp,*p;
  int flag=0,flag1=0;
  p=root;
  tos++;
  stk[tos]=p;  //initially push root into the stack
  while(tos !=-1)//while stack is not empty
  {
   while(flag==0 && p->lptr!=NULL)
    {
    p=p->lptr;
    tos++;
    stk[tos]=p;
    flag1=1;
 }
     //while traversing the last leaf node is also pushed on the stack,so we use
     //flag1 to indicate if traversal has occured if flag1=1 it means that traversal
     //has occured and the node on the top of the stack is not a parent node but a  
     //leaf node which has to be removed
 if(flag1==1)
 {
  p=stk[tos];  //so remove it from the stack
  tos--;
  flag1=0; //reset flag1
 }
  p=stk[tos];  //retrive the last parent from the stack
  tos--;
    //swap the left and right children
      temp=p->lptr;
      p->lptr=p->rptr;
      p->rptr=temp;
    //after swapping if the left child exists then its children also have to be swapped
//so push left child onto stack
if(p->lptr !=NULL)
 {
 p=p->lptr;
 tos++;
 stk[tos]=p;
 flag=0;
 }
    //if left child does not exist then set flag=1 this disables traversing the tree again
    //and simply retrives the last parent from the stack and processes it

 else
      flag=1;
 }
 }
node *createtree(node *root)
 {
    int n;
    do{ printf("\nEnter number<0 to stop>:");
    scanf("%d",&n);
    if(n!=0)
    root= insert(n,root);
  }
  while(n!=0);
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
   } //enode of while
  // we have trvered to the enode of tree
  // anode ready for insetion

   if(temp1 == NULL)

   { // attach either as left son or right son of parent temp2
 if(p->data<temp2->data)
          temp2->lptr=p; // attach as left son
                 else
           temp2->rptr=p; // attach as right son
}
}//enode of else
     return(root);
 }//end of create tree
void inorder(node *root)//inorder function
{
if(root==NULL)
{printf("\n\tEMPTY TREE");
  exit(1);
}
if(root->lptr!=NULL)
inorder(root->lptr);
printf("%5d",root->data);
if(root->rptr!=NULL)
inorder(root->rptr);
}//end inorder