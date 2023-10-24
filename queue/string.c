#include "stdlib.h"
#include "stdbool.h"
#include "string.h"
// 顺序存储
#define MAXSZIE 255
typedef struct{
    char ch[MAXSZIE]; //静态储存
    /* char *ch          动态储存(堆分配储存)*/
    int length;
}SString;

// 链式存储
typedef struct StringNode{
    char ch;
    struct StringNode *next;
}StringNode,*String;
// 存储密度低，一个ch占1B，而一个指针需要4B，为了提高存储密度，可以改为char ch[n];

bool SubString(SString Sub,SString S,int pos,int len){
    if(pos+len-1>S.length) return false;
    for(int i=pos;i<S.length;i++)
        Sub.ch[i-pos+1]=S.ch[i];
    Sub.length=len;
    return true;
}

int StrCompare(SString s,SString t){
    for(int i=1;i<=s.length && i<=t.length,i++){
        if(s.ch[i]!=t.ch[i]){
            return s.ch[i]-t.ch[i];
        }
    }
    return s.length-t.length;
}

/* 朴素匹配模式算法 */
int Index(SString s,SString t){
    int i=1;int n=strlen(s);int m=strlen(t);
    SString Sub;
    while(i<=n-m+1){
        SubString(Sub,s,i,m);
        if(StrCompare(Sub,t)!=0) ++i;
        else return i;
    }
    return -1;
}

int Index(SString S,SString T){
    int i=1,j=1;
    while (i<=S.length && j<=T.length)
    {
        if(S.ch[i]==T.ch[i]){
            ++i;++j;
        }else{
            i=i-j+2;
            j=1;
        }
    }
    if(j>T.length) return i-T.length;
    else return -1;
}

void get_next(SString t,int next[]){
    int i=1,j=0;
    next[1]=0;
    while(i<t.length){
        if(j==0||t.ch[i]==t.ch[j]){
            ++i;++j;
            next[i]=j;
        }
        else{
            j=next[i];
        }
    }
}

int Index_KMP(SString s,SString t){
    int i=1,j=1;
    int next[t.length+1];
    get_next(t,next);
    while(i<=s.length&&j<=t.length){
        if(j==0||s.ch[i]==t.ch[j]){
            ++i;++j;        // 比较后继字符
        }else{
            j=next[j];      // 模式串向右移动
        }
    }
    if(j>T.length) return i-T.length;
    else return -1;
}


