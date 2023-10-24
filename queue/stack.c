#include "stdio.h"
#include "stdbool.h"
#define MAXSIZE 10
typedef struct{
    int data[MAXSIZE];  // 静态分配
    int top;
}SqStack;

void InitStack(SqStack* q){
    q->top=0;
}

bool isempty(SqStack q){
    if(q.top==0){
        return true;
    }
    return false;
}

bool Push(SqStack* q,int s){
    if (q->top==MAXSIZE-1){
        return false;
    }
    q->data[++(q->top)]=s;
    return true;
}

/* bool Push(SqStack &q,int s){
    if (q.top==MAXSIZE-1){
        return false;
    }
    q.data[++q.top]=s;
    return true;
} */

bool Pop(SqStack q,int &s){
    if (q.top==-1){
        return false;
    }
    s = q.data[q.top--];
    return true;
}

bool Gettop(SqStack q,int &s){
    if (q.top==-1){
        return false;
    }
    s = q.data[q.top];
    return true;
}

void testsq(){
    SqStack q;
}

bool Check(char str[],int length){
    SqStack q;
    InitStack(q);
    for(int i=0;i<length;i++){
        if(str[i]=='('||str[i]=='['||str[i]=='{'){
            Push(q,str[i]);
        }else{
            if(isempty(q)){
                retrun false;
            }

            char topElem;
            Pop(q,topElem);
            if(str[i]==')'&&topElem!='(') return false;
            if(str[i]=='['&&topElem!=']') return false;
            if(str[i]=='{'&&topElem!='}') return false;
        }
    }

    return isempty(q);
}