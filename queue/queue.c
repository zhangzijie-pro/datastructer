#include "stdbool.h"
#include "stdlib.h"
#include "stdio.h"
#define MAXSIZE 10

typedef struct{
    char data[MAXSIZE];
    int front,rear;
    int size;  // 记录队列的长度
    int tag;   // 记录最近的操作是插入还是删除  1/0
}SqQueue;


void InitQueue(SqQueue &s){
    s.size=s.front=s.rear=0;
}
// 入队操作
bool EnQueue(SqQueue &s,int x){
    if((s.rear+1)%MAXSIZE==s.front){
        return false;
    }
    s.data[s.rear]=x;
    s.rear=(s.rear+1)%MAXSIZE;
    s.size++;
    s.tag=1;
    return true;
}

bool QueueEmpty(SqQueue s){
    if(s.rear==s.front){
        return false;
    }else{
        return true;
    }
}

bool OutQueue(SqQueue &s,int &x){
    if(s.rear==s.front){
        return false;
    }
    x=s.data[s.front];
    q.front=(q.front+1)%MAXSIZE;
    s.size--;
    s.tag=0;
    return true;
}

bool GetHead(SqQueue s, int &x){
    if(s.rear==s.front){
        return false;
    }
    x = s.data[s.front];
    return true;
}


// 链式实现
typedef struct LinkNode{
    char data;
    struct LinkNode* next;
}LinkNode;

typedef struct{
    LinkNode *front,*rear;
}LinkQueue;

// 带头结点
void InitQueue(LinkQueue &q){
    q.front=q.rear=(LinkNode*)malloc(sizeof(LinkNode));
    q.front->next = NULL;
}

bool IsEmpty(LinkQueue q){
    if(q.front=q.rear){
        return true;
    }
    return false;
}

void EnQueue(LinkQueue &q,int x){
    LinkNode *s=(LinkNode*)malloc(sizeof(LinkNode))
    s->data=x;
    s->next=NULL;
    q.rear->next=s;
    q.rear=s;
}

// 出队
bool OutQueue(LinkQueue &q,char &x){
    if(q.front==q.rear){
        return false;  // 空队
    }

    LinkNode *p=q.front->next;   // 新建一个指针指向这个队列
    x=p->next;                  // 将p的next赋值给x   用变量x返回对头元素
    p.front->next=p->next;      // 修改头结点的next指针
    if(q.rear==p) q.front==q.rear;   // 如果是最后一个结点删除
    free(p);
    return true;
}


/*  不带头结点 
void InitQueue(LinkQueue &q){
    q.front=NULL;
    q.rear=NULL;
}
bool IsEmpty(LinkQueue q){
    if(q.front=NULL){
        return true;
    }
    return false;
} 

void EnQueue(LinkQueue &q,int x){
    LinkNode *s=(LinkNode*)malloc(sizeof(LinkNode))
    s->data=x;
    s->next=NULL;
    if(q.front==NULL){
        q.front=s;
        q.rear=s;
    }else{
        q.rear->next=s;
        q.rear=s;
    }
}

bool DelQueue(LinkQueue &q,char &x){
    if(q.front==NULL){
        return false;
    }

    LinkNode *p=p.front;  // p指向出队的结点
    x=p->data;
    q.front=p->next;
    if(q.rear==p){
        q.front=NULL;
        q.rear==NULL;
    }
    free(p);
    return true;
}
*/