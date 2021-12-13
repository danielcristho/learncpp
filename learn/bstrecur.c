//bstrecur.c
#include<stdio.h> //preprocessor
#include<stdlib.h>//preprocessor

struct node//structure definition
{
    int info;
    struct node *lptr,*rptr;
};

struct node *create(int,struct node *);
struct node *insert(struct node *);

//function declarations

int preorder(struct node *);
int inorder(struct node *);
int postorder(struct node *);
void main()//main function
{
    struct node *root=NULL;
    int n,c=0;
    while(c!=6)
    {
        printf("\n\n\t\tMENU");
        printf("\n\t1: CREATE\n\t2: INSERTION\n\t3: POSTORDER");
        printf("\n\t4: INORDER\n\t5: PREORDER\n\t6: EXIT");
        printf("\n\n\tEnter your choice\t");

        scanf("%d",&c);
        switch(c)
        {
                case 1: printf("\n\tHow many elements to enter\t");
                scanf("%d",&n);
                root=NULL;
                root=create(n,root);
                break;
                case 2: root=insert(root);
                break;
                case 3: postorder(root);
                break;
                case 5: preorder(root);
                break;
                case 4: inorder(root);
                break;
        }//end switch
    }//end while
}//end main

struct node *create(int n,struct node *root)//create function
{
    struct node *p,*parent,*temp;
    int i;
    for(i=1;i<=n;i++) 
    {
    p=(struct node *)malloc(sizeof(struct node));
    printf("Enter data\t");
    scanf("%d",&p->info);
    p->lptr=p->rptr=NULL;
    if(root==NULL)
            root=p;
else
{
temp=root;
while(temp!=NULL)
{parent=temp;
if(p->info < temp->info)
temp=temp->lptr;
else
if(p->info > temp->info)
temp=temp->rptr;
 else {
printf("\n\tDUPLICATE VALUE");
free(p);
break;
    }//end else
}//end while

if(temp==NULL)

{

if(p->info < parent->info)
parent->lptr=p;
else
parent->rptr=p;
 }//end if
}//end else
}//end for

return(root);
}//end function

struct node *insert(struct node *root) //insert function

{
struct node *p,*temp,*parent;

p=(struct node *)malloc(sizeof(struct node));

printf("\n\tEnter element\t");

scanf("%d",&p->info);//scan elements

p->lptr=p->rptr=NULL;

if(root==NULL)
root=p;
else

{
temp=root;
while(temp!=NULL)
{
parent=temp;
if(p->info < temp->info)
temp=temp->lptr;
else
if(p->info > temp->info)
temp=temp->rptr;
else
{
printf("\n\t DUPLICATE NODE\n");
free(p);
root=insert(root);
break;
}//end else
}//end while
if(temp==NULL)

{
if(p->info < parent->info)
parent->lptr=p;
else
if(p->info > parent->info)
parent->rptr=p;
}//end if
}//end else

return(root);
}//end function

int preorder(struct node *root)//preorder function

{
if(root==NULL)

{
printf("\n\tEMPTY TREE");
return 0;
}//end if

printf("%5d",root->info);
if(root->lptr!=NULL)
preorder(root->lptr);
if(root->rptr!=NULL)
preorder(root->rptr);
return 0;

}//end preorder

int inorder(struct node *root)//inorder function
{
if(root==NULL)
{
printf("\n\tEMPTY TREE");
return 1;
}//end if
if(root->lptr!=NULL)
inorder(root->lptr);
printf("%5d",root->info);
if(root->rptr!=NULL)
inorder(root->rptr);
return 0;
}//end inorder
int  postorder(struct  node  *root)
{
if(root==NULL)

{
printf("\n\tEMPTY TREE");
return 0;
}//end if
if(root->lptr!=NULL)
postorder(root->lptr);
if(root->rptr!=NULL)
postorder(root->rptr);
printf("%5d",root->info);
return 0;
}//end postorder