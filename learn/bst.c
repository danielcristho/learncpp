#include<stdio.h>
#include<stdlib.h>

struct Tree

{   int data;
    struct Tree *lptr; // pointer to left child
    struct Tree *rptr; // pointer to right child
};                // will be pointing to NULL in case of leaf nodes
typedef struct Tree node;
//Function prototypes
 node  *createtree(node  *root);
 node *insert(int n,node *root);
 void search(int n,node *root);
 node *delet(int n,node *root);
 int isLeft(node *parent,node *p);
 int isRight(node *parent,node *p);
 void main()

{
  node *root=NULL; //initially initialize root to null
  int n,n1,ch;
  while(1)
{
  printf("\n\n\t\tMENU");
  printf("\n\t1: CREATE\n\t2: INSERTION\n\t3: DELETION\n\t4: SEARCH");
  printf("\n\t5: EXIT");
  printf("\n\n\tEnter your choice\t");
  scanf("%d",&ch);
  switch(ch)

{
case 1:root=NULL;
  root=createtree(root);
  break;
case 2: printf("\n Enter Number");
  scanf("%d",&n);
  root=insert(n,root);
  break;
case 3:printf("\nEnter number to be deleted:");
  scanf("%d",&n1);
  root=delet(n1,root);
  break;
case 4: printf("\nEnter no to be searched:");
  scanf("%d",&n);
  search(n,root);
  break;
case 5: exit(0);
  break;
  default: printf("\n Invalid choice press between 1 and 8 only");
}//end  switch
}//end while
}//end main

 node *createtree(node *root)
{
   int n;
    do{ printf("\nEnter number<0 to stop>:");
     scanf("%d",&n);
     if(n!=0)
root= insert(n,root);
  }while(n!=0);
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
  //in the appropriate place. If this is the first node to be created
  //then this is the root of the tree.
  if(root==NULL)
  root=p;
  else
  // We will use temp1 for traversing the tree.
  // Temp2 will be traversing parent
  // p is the new node we have created.
{  temp1=root;
   while(temp1!=NULL)
   { temp2=temp1; // store it as parent
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
    }//end else
   } //end of while
     // we have traversed to the end of tree
  // node ready for insertion

   if(temp1 == NULL)

   { // attach either as left son or right son of parent temp2
 if(p->data<temp2->data)
    temp2->lptr=p; // attach as left son
    else
    temp2->rptr=p; // attach as right son
   }
   printf("\n successful insertion\n");

 }//end of else
     return(root);

 }//end of create tree
void search(int n,node *root)
{

  node *p;
  p=root; //initially assign p to root
  while(n!=p->data)
  {  if(n<p->data) //if n is less than curr node data
      p=p->lptr; //traverse the left sub tree
        else
p=p->rptr; //else if n is greater than curr node data
          //travel right subtree

if(p==NULL) //if temp1 points to null it implies no value  in the tree
  break;       //so exit loop

  }
  if(p==NULL)
   printf("value is not present in the tree\n");
  else
   printf("\n value found");
}
node *delet(int n,node *root)
{
node *temp1=NULL; //
node *temp2=NULL; // temp1 and temp2 are used for traversing the tree
node *p=NULL;  // p node indicates current node that has to be deleted
int val;
int ans;
      temp1=root;   //initialize temp1 to root
    while(n!= temp1->data)
     {
      temp2=temp1;   //store temp1 in temp2
    if(n<temp1->data) //if n is less than curr node data
    temp1=temp1->lptr; //traverse the left sub tree
    else
     temp1=temp1->rptr; //else if n is greater than curr node data
                               //travel right subtree
     if(temp1==NULL)    //if temp1 points to null it implies value not present in the tree
     break;            //so exit loop
     }
/*after the successful completion of the above loop temp1 will be pointing to the node having the data
and temp2 will be pointing to the parent of this node, please note in case temp1 is pointing to root then

temp2 will be pointing to NULL as root has no parent*/
   if(temp1==NULL)
    printf("\n value not present in the tree");
   else
   {   // store in p, the node to be deleted
      p= temp1;
      //checking if node to be deleted is a leaf node
      if(p->lptr==NULL && p->rptr==NULL)
 {
    printf("\n Deleting leaf node with value: %d",p->data);
    //if the leaf node is root of the tree no need to check if it is left or
   //right son
    if(temp2==NULL)
    printf("\n Deleting root of the tree which is a leaf node");
   // check if leaf node is left son or right son of parent
    else

     {
       ans=isLeft(temp2,p);
      if(ans==0)  // p is the left son
       temp2->lptr=NULL;
       ans=isRight(temp2,p);
     if(ans==0) // p is the right son
       temp2->rptr=NULL;
      }
       free(p);
              }//end of if deletion of leaf node
             //checking if node to be deleted is a non leaf node with one child
    else
     if(p->lptr==NULL || p->rptr==NULL)
        {
        printf("\n Deleting node with one child with value %d",p->data);
        if(p->lptr !=NULL)//implies left child is present
        {
   if(temp2==0)
      { printf("\n Deleting root with only left subtree");
         root=p->lptr;
       }//end of if

else

 {
    ans=isLeft(temp2,p);
    if(ans==0)    // p is left son of parent
    // assign left pointer of parent to left pointer of p
    temp2->lptr=p->lptr;
    ans=isRight(temp2,p);
    if(ans==0)  // p is  right son of parent
    // assign right pointer of parent to left pointer of p
temp2->rptr=p->lptr;
}//end of else
}//end of if
if(p->rptr !=NULL)//implies right child is present

{  if(temp2==0)

    {
    printf("\n Deleting root with only right subtree");
    root=p->rptr;
    }//end of if
    else
      {
      ans=isLeft(temp2,p);
      if(ans==0) // p is left son of parent
// assign left pointer of parent to right pointer of p
   temp2->lptr=p->rptr;
   ans=isRight(temp2,p);
   if(ans==0) // p is right son of parent
      // assign right pointer of parent to right pointer of p
       temp2->rptr=p->rptr;
}//end of else
  }//end of if
   free(p);
 }//end of else if
  //checking if node to be deleted is non leaf node with two children
 else if(p->lptr!=NULL && p->rptr!=NULL)
  {
    printf("\n Deleting node with two children with value=%d",p->data);
    //finding node with least value in the right tree of the node
    printf("\n Finding minimum value in right sub tree\n");
    temp1=p->rptr;
  while(temp1->lptr !=NULL)
        temp1=temp1->lptr;
 // temp now points to least value in right sub tree of node p
   printf("\n min value=%d",temp1->data);
   printf("\n Deleting and re-adjusting");
    val=temp1->data;
    delet(val,root); // recursive call
    p->data=val;
    }
    printf("\n successful deletion\n");
   }//end of else
   return(root);
}//end of delete
//This routine checks if a node is the left child of the parent
//arguments passed are the parent and current node pointers

//returns 0 if successful else returns 1
 int isLeft(node *parent,node *p)
 {
  int ans;
  if(parent->lptr==p)
   ans=0;
  else
   ans=1;
  return ans;
 }
//This routine checks if a node is the right child of the parent
//arguments passed are the parent and current node pointers
//returns 0 if successful else returns 1
 int isRight(node *parent,node *p)
 {
  int ans;
  if(parent->rptr==p)
    ans=0;
  else
    ans=1;
  return ans;
}