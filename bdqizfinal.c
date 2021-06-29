#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

typedef struct AVLNode_t
{
    int data;
    struct AVLNode_t *left,*right;
    
    
    int height; 
}AVLNode;

typedef struct AVL_t
{
    AVLNode *_root;
    unsigned int _size;
}AVL;

AVLNode* _avl_createNode(int value) {
    AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
    newNode->data = value;
    newNode->height=1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

AVLNode* _search(AVLNode *root, int value) {
    while (root != NULL) {
        if (value < root->data)
            root = root->left;
        else if (value > root->data)
            root = root->right;
        else
            return root;
    }
    return root;
}

int _getHeight(AVLNode* node){
    if(node==NULL)
        return 0; 
    return node->height;
}

int _max(int a,int b){
    return (a > b)? a : b;
}


AVLNode* _rightRotate(AVLNode* pivotNode) {

    AVLNode* newParrent=pivotNode->left;

    pivotNode->left=newParrent->right;

    newParrent->right=pivotNode;

    pivotNode->height=_max(_getHeight(pivotNode->left),
                      _getHeight(pivotNode->right))+1;
    newParrent->height=_max(_getHeight(newParrent->left),
                       _getHeight(newParrent->right))+1;
    
    return newParrent;
}

AVLNode* _leftRotate(AVLNode* pivotNode) {

    AVLNode* newParrent=pivotNode->right;

    pivotNode->right=newParrent->left;

    newParrent->left=pivotNode;

    pivotNode->height=_max(_getHeight(pivotNode->left),
                      _getHeight(pivotNode->right))+1;
    newParrent->height=_max(_getHeight(newParrent->left),
                       _getHeight(newParrent->right))+1;
    
    return newParrent;
}

AVLNode* _leftCaseRotate(AVLNode* node){
    return _rightRotate(node);
}

AVLNode* _rightCaseRotate(AVLNode* node){
    return _leftRotate(node);
}


AVLNode* _leftRightCaseRotate(AVLNode* node){
    node->left=_leftRotate(node->left);
    return _rightRotate(node);
}


AVLNode* _rightLeftCaseRotate(AVLNode* node){
    node->right=_rightRotate(node->right);
    return _leftRotate(node);
}

int _getBalanceFactor(AVLNode* node){
    if(node==NULL)
        return 0;
    return _getHeight(node->left)-_getHeight(node->right);
}

AVLNode* _insert_AVL(AVL *avl,AVLNode* node,int value) {
    
    if(node==NULL) 
        return _avl_createNode(value);
    if(value < node->data)
        node->left = _insert_AVL(avl,node->left,value);
    else if(value > node->data)
        node->right = _insert_AVL(avl,node->right,value);
    
    node->height= 1 + _max(_getHeight(node->left),_getHeight(node->right)); 

    int balanceFactor=_getBalanceFactor(node);
    
    if(balanceFactor > 1 && value < node->left->data) // skewed kiri (left-left case)
        return _leftCaseRotate(node);

    if(balanceFactor > 1 && value > node->left->data) // 
        return _leftRightCaseRotate(node);

    if(balanceFactor < -1 && value > node->right->data)
        return _rightCaseRotate(node);
    
    if(balanceFactor < -1 && value < node->right->data)
        return _rightLeftCaseRotate(node);
    
    return node;
}

AVLNode* _findMinNode(AVLNode *node) {
    AVLNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    return currNode;
}

AVLNode* _remove_AVL(AVLNode* node,int value){
    if(node==NULL)
        return node;
    if(value > node->data)
        node->right=_remove_AVL(node->right,value);
    else if(value < node->data)
        node->left=_remove_AVL(node->left,value);
    else{
        AVLNode *temp;
        if((node->left==NULL)||(node->right==NULL)){
            temp=NULL;
            if(node->left==NULL) temp=node->right;  
            else if(node->right==NULL) temp=node->left;
            
            if(temp==NULL){
                temp=node;
                node=NULL;
            }
            else
                *node=*temp;   
            
            free(temp);
        }
        else{
            temp = _findMinNode(node->right);
            node->data=temp->data;
            node->right=_remove_AVL(node->right,temp->data);
        }    
    }

    if(node==NULL) return node;
    
    node->height=_max(_getHeight(node->left),_getHeight(node->right))+1;

    int balanceFactor= _getBalanceFactor(node);
    
    if(balanceFactor>1 && _getBalanceFactor(node->left)>=0) 
        return _leftCaseRotate(node);

    if(balanceFactor>1 && _getBalanceFactor(node->left)<0) 
        return _leftRightCaseRotate(node);
  
    if(balanceFactor < -1 && _getBalanceFactor(node->right)<=0) 
        return _rightCaseRotate(node);

    if(balanceFactor < -1 && _getBalanceFactor(node->right)>0) 
        return _rightLeftCaseRotate(node);
    
    return node;
}

void avl_init(AVL *avl) {
    avl->_root = NULL;
    avl->_size = 0u;
}

bool avl_isEmpty(AVL *avl) {
    return avl->_root == NULL;
}

bool avl_find(AVL *avl, int value) {
    AVLNode *temp = _search(avl->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->data == value)
        return true;
    else
        return false;
}

void avl_insert(AVL *avl,int value){
    if(!avl_find(avl,value)){
        avl->_root=_insert_AVL(avl,avl->_root,value);
        avl->_size++;
    }

}

void avl_remove(AVL *avl,int value){
    if(avl_find(avl,value)){
        avl->_root=_remove_AVL(avl->_root,value);
        avl->_size--;
    }

}

void __avl__preorder(AVLNode *root) {
    if (root) {
        printf("%d ", root->data);
        __avl__preorder(root->left);
        __avl__preorder(root->right);
    }
}

void __avl__inorder(AVLNode *root) {
    if (root) {
        __avl__inorder(root->left);
        printf("%d ", root->data);
        __avl__inorder(root->right);
    }
}

void __avl__postorder(AVLNode *root) {
    if (root) {
        __avl__postorder(root->left);
        __avl__postorder(root->right);
        printf("%d ", root->data);
    }
}

void __avl__levpreorder(AVLNode *root) {
    if (root) {
        printf("Data : %d || Height : %d\n", root->data, root->height);
        //printf("%d ", root->height);
        __avl__levpreorder(root->left);
        __avl__levpreorder(root->right);
    }
}

void __avl__levinorder(AVLNode *root) {
    if (root) {
        __avl__levinorder(root->left);
        printf("Data : %d || Height : %d\n", root->data, root->height);
        __avl__levinorder(root->right);
    }
}

void __avl__levpostorder(AVLNode *root) {
    if (root) {
        __avl__levpostorder(root->left);
        __avl__levpostorder(root->right);
        printf("Data : %d || Height : %d\n", root->data, root->height);
        //printf("%d ", root->data);
    }
}

void avl_levinorder(AVL *avl) {
    __avl__levinorder(avl->_root);
}

void avl_inorder(AVL *avl) {
    __avl__inorder(avl->_root);
}

void avl_postorder(AVL *avl) {
    __avl__postorder(avl->_root);
}

void avl_levpostorder(AVL *avl) {
    __avl__levpostorder(avl->_root);
}


void avl_preorder(AVL *avl) {
    __avl__preorder(avl->_root);
}

void avl_levpreorder(AVL *avl) {
    __avl__levpreorder(avl->_root);
}


 AVLNode* parentGear(AVLNode* node, int key)
{
    
    if(node==NULL || node->data==key) return NULL;

    /* Jika ditemukan sebuah node yang nilai anaknya sama dengan key, maka node tersebut di return */ 
    if((node->left != NULL && node->left->data == key) || (node->right != NULL && node->right->data == key))
        return node;
    
    // Traverse ke kiri
    AVLNode *l = parentGear(node->left, key);
    if(l != NULL) return l;
    
    // Traverse ke kanan
    l = parentGear(node->right, key);
    return l;
}

// DRIVER
AVLNode* parentlinger(AVL *avl, int key) 
{
    return parentGear(avl->_root, key);
}

// FUNC DEF : siblingGear dan siblinger adalah fungsi untuk mencari sibling dari sebuah node
// UTILITY
AVLNode* siblingGear(AVLNode* node, int key)
{
    /* Jika sudah sampai node terakhir atau ditemukan node sesuai dengan nilai yang diminta
     * return NULL */
    if(node == NULL || node->data == key) return NULL;
    
    if(node->left != NULL && node->left->data == key) return node->right;
    if(node->right != NULL && node->right->data == key) return node->left;

    AVLNode* l = siblingGear(node->left, key);

    if(l != NULL) return l;

    l = siblingGear(node->right, key);
    return l;

}

AVLNode* siblinger(AVL *avl, int key) 
{
    return siblingGear(avl->_root, key);
}


int rootGear(AVL* avl)
{
    return avl->_root->data;
}


void subtlinger(AVL *avl, int key)
{
   int num;
    // If root
    if(key == rootGear(avl)) printf("%d\n",key);

    else
    {
        // Get parent first
        AVLNode* parent = parentlinger(avl, key);

       // If parent is root 
       if(parent->data == rootGear(avl)) printf("%d\n",parent->data);

       else
       {
           if (parent!=NULL) num = parent->data;

           AVLNode* sibling = siblinger(avl, num);
           int sub = sibling->data - parent->data;

           printf("%d\n", abs(sub));
       }

    }
}

int main()
{

    // Init
    AVL AVLkaiser;
    avl_init(&AVLkaiser);

    //Baris pertama N M, dengan N merupakan jumlah node yang akan diinput dan T merupakan jumlah case yang akan dijalankan 
    int N,T;
    scanf("%d %d", &N, &T);
    //printf("N Entered : %d || T Entered : %d\n", N,T);
    
    //Baris kedua C sebanyak N berupa bilangan dalam AVL tree 
    int C;
    while(N--)
    {
        scanf("%d", &C);
        //printf("C Entered : %d\n", C);
        avl_insert(&AVLkaiser,C);
    }
    
    
    //T baris setelahnya berisi 1 bilangan x, berupa node yang akan dicek
    int x;
    while(T--)
    {
        scanf("%d", &x);
        //printf("x Entered : %d\n", x);
        subtlinger(&AVLkaiser, x);
    }

    //avl_inorder(&AVLkaiser);
    return 0;
}