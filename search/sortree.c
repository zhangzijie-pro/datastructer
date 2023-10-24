#include "stdlib.h"

typedef struct BSTNode{
    int key;
    struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;

BSTNode *BST_Search(BSTree T,int key){
    while(T!= NULL&&key!=T->key){
        if(key<T->key) T=T->lchild;
        else T=T->rchild;
    }
    return T;
}// O(1)

BSTNode *BSTSearch(BSTree T,int key){
    if(T==NULL)
        return NULL;
    if(T->key==key) return T;
    else if (key<T->key)
        return BSTSearch(T->lchild,key);
    else
        return BSTSearch(T->rchild,key);
}// O(h)

int BST_Insert(BSTree T,int k){
    if (T==NULL)
    {
        T=(BSTree)malloc(sizeof(BSTNode));
        T->key=k;
        T->lchild=T->rchild=NULL;
        return 1;
    }
    else if(k==T->key) return 0;
    else if(k<T->key) return BST_Insert(T->lchild,k);
    else return BST_Insert(T->rchild,k);
}

int BSTInsert(BSTree T,int key){
    while(T!= NULL&&key!=T->key){
        if(key<T->key) T=T->lchild;
        else T=T->rchild;
    }
    return 1;
}// O(1)

void Creat_BST(BSTree T,int str[],int n){
    T=NULL;
    int i=0;
    while(i<n){
        BST_Insert(T,str[i]);
        i++;
    }
}

BSTNode* deleteNode(BSTNode* root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->key) {
        root->lchild = deleteNode(root->lchild, key);
    } else if (key > root->key) {
        root->rchild = deleteNode(root->rchild, key);
    } else {
        if (root->lchild == NULL) {
            BSTNode* temp = root->rchild;
            free(root);
            return temp;
        } else if (root->rchild == NULL) {
            BSTNode* temp = root->lchild;
            free(root);
            return temp;
        } else {
            BSTNode* minNode = findMinNode(root->rchild);
            root->key = minNode->key;
            root->rchild = deleteNode(root->rchild, minNode->key);
        }
    }
    return root;
}