// itertraves.c.A Program to demonstrate tree traversal using iteration
#include<stdio.h>
#include<stdlib.h>
struct Tree
{

  int data;

  Tree *lptr;

  Tree *rptr;

};

typedef struct Tree node;

node *stk[30];
int tos=-1;

//Routines associated with tree
node *createtree(node *root);
node *insert(int n,node *root);
void preorder(node * root);
void inorder(node * root);
void main()
{ 
  int ch;
  node *root=NULL;
  node *p=NULL;
    printf("Enter values to create tree\n");
  root=createtree(root);
    while(1)

  {  
    printf("\n1: Inorder\n2: Preorder\n3: Exit");
  printf("\nEnter Choice:");
 scanf("%d",&ch);
 switch(ch)

 {

    case 1: printf("\ninorder sequence");
       inorder(root);
                      break;
  case 2:printf("\npreorder sequence\n");
        preorder(root);
        break;
  case 3: exit(0);
        break;
             default : printf("\nenter choice between 1 and 3 only");
 }
  }//end of while
}//end of main

void preorder(node *root)

{   int flag=0;
node *p;
p=root;
while(1)
{
    while(p!=NULL)
    { 
      printf("\t%d",p->data);
  tos++;
        stk[tos]=p;     //push element onto stack
        if(p->lptr==NULL && p->rptr==NULL)
          flag=1;   //if left child is present for current node set flag to 1
        p=p->lptr;
    }

    if(flag==1)  //leaf node has been inserted into stack it so pop it out
    {
    p=stk[tos];
    tos--;
    flag=0;
    }

    if(tos==-1)
     break;
    p=stk[tos];  //get parent node from stack
    tos--;
p=p->rptr;   //now traverse to the right of parent
    }
}

void inorder(node * root)
{
    tos=-1;
    node *p;
  p=root;

  while(1)
{  
    while(p!=NULL)
    {
    tos++;
    stk[tos]=p;
        p=p->lptr;
    }
    if(tos==-1)
     break;
            p=stk[tos];
            tos--;
            printf("\t%d",p->data);
            p=p->rptr;
      }
}

node *createtree(node *root)
 { 
   int n;
          do{
              printf("\nEnter number<0 to stop>:");
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
    }//end else
   } //end of while

  // we have trvered to the enode of tree

  // anode ready for insetion
   if(temp1 == NULL)
   { // attach either as left son or right son of parent temp2
 if(p->data<temp2->data)
          temp2->lptr=p; // attach as left son
                 else
          temp2->rptr=p; // attach as right son
   }

}//end of else
   return(root);
}//end of create tree