#include "stdlib.h"
#include "stdbool.h"

typedef struct{
    int value;
}ElemType;

typedef struct BiNode{
    ElemType data;
    struct BiNode *lchild,*rchild;
    struct BiNode *parent;
}BiNode,*BiTree;

// 链队列

typedef struct LinkNode{
    BiNode * data;
    struct LinkNode *next;
}LinkNode;

typedef struct{
    LinkNode *front,*rear;
}LinkQueue;

// 线索二叉树  线索链表
typedef struct ThreadNode{
    ElemType data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag;       // 左右线索标志
}ThreadNode,*ThreadTree;
// tag==0,表示指针指向孩子
// tag==1,表示指针是“线索”
BiNode *p;   // p指向目标结点
BiNode *pre_p=NULL;   // 指向当前访问结点的前驱
BiNode *final=NULL; // 用于记录最终结果


void visit_b(BiNode *q){
    if(q=p){            // 当前访问结点刚好是结点p
        final=pre_p;      // 找到p的前驱
    }else{
        pre_p=q;          // pre指向当前访问的结点
    }
}

// 前序遍历
void PreOrder(BiTree T){
    if(T!=NULL){
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

// 中序遍历  中序线索化二叉树
void CreateInThread(ThreadTree T){
    pre=NULL;           // pre初始化为NULL
    if(T!=NULL){        // 非空二叉树才能线索化
        InOrder(T);     // 中序线索化二叉树
        if(pre->rchild==NULL)
            pre->rtag=1;    // 处理遍历的最后一个结点
    }
}

ThreadNode *pre=NULL;
void visit(ThreadNode *q){
    if(q->lchild==NULL){    // 左子树为空，建立前驱线索
        q->lchild=pre;
        q->ltag=1;
    }
    if(pre!=NULL&&pre->rchild==NULL){
        pre->rchild=q;     // 建立前驱结点的后继线索
        pre->rtag=1
    }
    pre=q;
}

void InOrder(ThreadTree T){
    if(T!=NULL){
        PreOrder(T->lchild);
        visit(T);
        PreOrder(T->rchild);
    }
}
int treeDepth(BiTree T){
    if(T==NULL){
        return 0;
    }
    else{
        int l = treeDepth(T->lchild);
        int r = treeDepth(T->rchild);
        return l>r? l+1:r+1;
    }
}

// 层序遍历
void LevelOrder(BiTree T){
    LinkQueue Q;
    InitQueue(Q);
    BiTree p;
    EnQueue(Q,T);
    while(!IsEmpty(Q)){
        DeQueue(Q,p);
        visit(p);
        if(p->lchild!=NULL) EnQueue(Q,p->lchild);
        if(p->rchild!=NULL) EnQueue(Q,p->rchild);
    }
}

int main()
{
    BiTree root=NULL; // 声明一个空树

    root = (BiTree)malloc(sizeof(BiNode));
    root->data.value = 1;
    root->lchild=NULL;
    root->rchild=NULL;

    BiNode *p = (BiNode *)malloc(sizeof(BiNode));
    p->data.value = 2;
    p->lchild=NULL;
    p->rchild=NULL;
    p->parent=root;
    root->lchild=p;

    return 1;
}


//  找到p为根的子树中，第一个被中序遍历的结点
ThreadNode *Firstnode(ThreadNode *p){
    while(p->ltag==0) p=p->lchild;  // 找左下结点
    return p;
}

// 在中序线索二叉树中找到结点p的后继结点
ThreadNode *Nextnode(ThreadNode *p){
    // 右子树中最左下结点
    if(p->rtag==0) return Firstnode(p->rchild);
    else return p->rchild;   // rtag==1直接返回后继线索 NULL
}

// 对中序线索二叉树进行中序遍历
void Inorder(ThreadNode *T){
    for(ThreadNode *p=Firstnode(T);p!=NULL;p=Nextnode(p))
        visit(p);
}

//  找到p为根的子树中，最后一个被中序遍历的结点
ThreadNode *Lastnode(ThreadNode *p){
    while(p->rtag==0) p=p->rchild;  // 找右下结点
    return p;
}

// 在中序线索二叉树中找到结点p的前驱结点
ThreadNode *Prenode(ThreadNode *p){
    // 右子树中最右下结点
    if(p->ltag==0) return Lastnode(p->lchild);
    else return p->lchild;   // rtag==1直接返回前驱线索 NULL
}

// 对中序线索二叉树进行逆向中序遍历
void RevInorder(ThreadNode *T){
    for(ThreadNode *p=Lastnode(T);p!=NULL;p=Prenode(p))
        visit(p);
}