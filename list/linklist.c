#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

/*
struct LNode{
    ElemType data;
    struct LNode *next;
};
typedef struct LNode LNode;
typedef struct LNode *LinkList;
*/

// 带头结点的单链表
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
        return false;
    L->next = NULL;
    return true;
}

// 插入
bool ListInsert(LinkList L, int i, int e)
{
    if (i < 1)
        return false;
    /*
    LNode *p;   // 指针p指向当前扫描到的结点
    int j=0; // 当前p指向第几个结点
    p=L;    //L指向头结点，头结点是第0个结点
    while(p!=NULL && j<i-1){  // 找到i-1个结点
        p=p->next;
        j++;
    }
    */
    LNode *p = GetElem(L, i - 1);
    /*
        if(p==NULL) return false;
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s-> next=p->next;
        p->next=s;
        return true;
    */
    return InsertNextNode(p, e);
}

// 后插操作
bool InsertNextNode(LNode *p, int e)
{
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
        return false; // 内存分配失败
    s->data = e;      // 结点s保存数据元素e
    s->next = p->next;
    p->next = s; // 将结点s连接p后
    return true;
}

// 前插操作
bool InsertPriorNode(LNode *p, int e)
{
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
        return false;
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}

// 删除
bool ListDelete(LinkList &L, int i, int &e)
{
    if (i < 1)
        return false;
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;
    if (p->next == NULL)
        return false;
    LNode *q = p->next; // 令q指向被删除的结点
    e = q->data;        // 用e返回元素的值
    p->next = q->next;  // 将*q结点从链中“断开”
    free(q);            // 释放结点的存储空间
    return true;
}
// 指定结点的删除
bool DeleteNode(LNode *p)
{
    if (p == NULL)
        return false;
    LNode *q = p->next;      // 令q指向被删除的结点
    p->data = p->next->data; // 和后继结点交换数据域
    p->next = q->next;       // 将*q结点从链中“断开”
    free(q);
    return true;
}

bool Empty(LinkList L)
{
    return (L == NULL);
}

// 按位查找 O(n)
LNode *GetElem(LinkList L, int i)
{
    if (i < 0)
        return NULL;
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

// 按值查找
LNode *LocatElem(LinkList L, int e)
{
    if (Empty(L))
        return false;
    LNode *p = L->next;
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p;
}

int length(LinkList L)
{
    int len = 0;
    LNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

// 尾插法
LinkList list_Tailinsert(LinkList &L)
{
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

// 前插法
LinkList List_HeadInsert(LinkList &L){
    LNode *s;
    int x;
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    scanf("%d",&x);
    while(x!=9999){
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        s->next=L->next;
        L->next=s;
        scanf("%d",&x);
    }
    return L;
}

void test()
{
    LinkList L;
    InitList(L);
}

// 不带头结点的单链表
/* bool InitList(LinkList &L){
    L = NULL;
    return true;
}

bool ListInsert(LinkList L, int i, int e){
    if(i<1) return false;
    if(i==1){
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L=s;
        return true;
    }
    LNode *p;   // 指针p指向当前扫描到的结点
    int j=1; // 当前p指向第几个结点
    p=L;    //L指向头结点，头结点是第0个结点
    while(p!=NULL && j<i-1){  // 找到i-1个结点
        p=p->next;
        j++;
    }
    if(p==NULL) return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s-> next=p->next;
    p->next=s;
    return true;
}
 */


// 循环链表
typedef struct DNode{
    int data;//数据域
    struct DNode *prior,*next;
}DNode, *DLinkList;

// DLinkList == DNode *

bool InitDLinkList(DLinkList &L){
    L=(DNode *)malloc(sizeof(DNode));   // 分配一个头结点
    if(L==NULL) return false;
    L->prior=NULL;          // 头结点的prior永远指向NULL
    L->next=NULL;           // 初始化时头结点后没有结点
    return true;
}

// 插入，后插
bool InsertNextDNode(DNode *p,DNode *s){
    if(p==NULL||s==NULL) return false;
    s->next=p->next;
    if(p->next!=NULL)
        p->next->prior=s;
    s->prior=p;
    p->next=s;
}

bool DeleteNextDNode(DNode *p){
    if(p==NULL) return false;
    DNode *q = p-> next;
    if(q==NULL) return false;
    p->next=q->next;
    if(q->next==NULL) 
        q->next->prior=p;
    free(q);
    return true;
}

void DestoryList(DLinkList &L){
    while(L->next !=NULL)
        DeleteNextDNode(L);
    free(L);
    L=NULL;
}


// 遍历
// 后向遍历
while(p!=NULL){
    p=p->next;
}
// 前向遍历
while(p!=NULL){
    p=p->prior;
}


// 双链表的插入
bool InsertNextDNode(DNode *p,DNode *s){
    s->next = p->next;
    p->next->prior= s;
    s->prior =p;
    p->next=s;
}

// 双链表的删除
p->next = q->next;
q->next->prior=p;
free(q);

// 定义一个静态链表
#define MAXSIZE 10
typedef struct{
    int data;
    int next;
}SLinkList[MAXSIZE];

