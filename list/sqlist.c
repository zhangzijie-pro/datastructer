#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>


// 静态分配的数组需要加长时比较麻烦，直接放弃治疗，该用为动态数组
#define MaxSize 10
typedef struct{
    int data[MaxSize];
    int length;
}SeqList;

void InitList(SeqList L){
    L.length = 0;
}

// 按位查找
int  GetElem(SeqList L,int i){
    return L.data[i-1];
}

//对于静态分配数组的插入操作
bool ListInsert(SeqList L,int i,int e){
    if(i<1 || i>L.length+1){   //判断i是否合法
        exit(404);
    }
    if(L.length>=MaxSize){    //判断存储空间是否满
        exit(999);
    }
    for(int j=L.length;j<=i;j--){
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;
    L.length++;
    return true;
}

bool ListDelete(SeqList L,int i,int e){
    if(i<1||i>L.length){
        return false;
    }
    e=L.data[i-1];
    for(int j=i;i<L.length;j++)
        L.data[j-1]=L.data[j];
    L.length--;
    return true;
}


int main(){
    SeqList L;  // 声明一个顺序表
    InitList(L);    // 初始化
    int e= -1;
    if(ListDelete(L,3,e)){
        printf("删除成功 %d\n",e);
    }else{
        printf("删除失败");
    }
    return 0;
}

/*
    动态数组

#define InitSize 10  // 默认最大长度

typedef struct
{
    int *data; // 指示动态分配数组的指针
    int MaxSize;
    int length; // 当前长度
}SeqList;

void InitList(SeqList &L){
    // 用malloc函数申请一片连续的存储空间
    L.data=(int *)malloc(InitSize*sizeof(int));
    if(!L.data) exit(OVERFLOW);
    L.length=0;
    L.MaxSize=InitSize;
}

bool ListDelete(SeqList &L,int i,int e){
    if(i<1||i>L.length){
        return false;
    }
    e=L.data[i-1];
    for(int j=i;i<L.length;j++)
        L.data[j-1]=L.data[j];
    L.length--;
    return true;
}


int GetElem(SeqList &L,int i){
    return L.data[i-1];
}

// 按值查找
int LocateElem(SeqList &L,int i, int e){
    for(int i=0;i<L.length;i++){
        if(L.data[i]==e){
            return i+1;
        }
    }
    return 0;
}

bool ListDelete(SeqList &L,int i,int e){
    if(i<1||i>L.length){
        return false;
    }
    e=L.data[i-1];
    for(int j=i;i<L.length;j++)
        L.data[j-1]=L.data[j];
    L.length--;
    return true;
}

// 增加动态数组长度
void IncreaseSize(SeqList &L,int len){
    int *p = L.data;
    L.data=(int *)malloc((L.MaxSize+len)*sizeof(int));
    for (int i=0;i<L.length;i++){
        L.data[i]=p[i];  // 将数据复制到新区域  时间开销大
    }
    L.MaxSize=L.MaxSize+len;
    free(p);  // 释放原来的内存空间
}

int ListInsert(Seqlist &L,int i, int e){
    if ((i < 1) || (i > L.Length + 1)) {
        return -1;//插入位置不合法，返回-1
    }
    if(L.length>=L.listsize){
        newbase = (int *)realloc(L.data,(L.length+Initsize)*sizeof(int));
        if(!newbase) exit(OVERFLOW);
        L.data=newbase;   //重新分配内存空间
        L.listsize+=Initsize;    //扩容
    }
    q = &(L.data[i-1]);
    for(p=&(L.data[L.length-1]);p>=q;--p) *(p+1)=*p;

    *q = e;
    ++L.length;

    return 0;
}
int main(){
    SeqList L;  // 声明一个顺序表
    InitList(L);    // 初始化
    int e= -1;
    if(ListDelete(L,3,e)){
        printf("删除成功 %d\n",e);
    }else{
        printf("删除失败");
    }
    return 0;
}
*/



#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>

#define InitSize 10  // 默认最大长度

typedef struct {
    int *data;      // 指示动态分配数组的指针
    int MaxSize;
    int length;     // 当前长度
} SeqList;

void InitList(SeqList *L) {
    // 用malloc函数申请一片连续的存储空间
    L->data = (int *)malloc(InitSize * sizeof(int));
    if (!L->data) exit(-1);
    L->length = 0;
    L->MaxSize = InitSize;
}

bool ListDelete(SeqList *L, int i, int e) {
    if (i < 1 || i > L->length) {
        return false;
    }
    e = L->data[i - 1];
    for (int j = i; j < L->length; j++) {
        L->data[j - 1] = L->data[j];
    }
    L->length--;
    return true;
}

int GetElem(SeqList *L, int i) {
    return L->data[i - 1];
}

// 按值查找
int LocateElem(SeqList *L, int i, int e) {
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] == e) {
            return i + 1;
        }
    }
    return 0;
}

// 增加动态数组长度
void IncreaseSize(SeqList *L, int len) {
    int *p = L->data;
    L->data = (int *)malloc((L->MaxSize + len) * sizeof(int));
    for (int i = 0; i < L->length; i++) {
        L->data[i] = p[i];  // 将数据复制到新区域  时间开销大
    }
    L->MaxSize = L->MaxSize + len;
    free(p);  // 释放原来的内存空间
}

int ListInsert(SeqList *L, int i, int e) {
    if ((i < 1) || (i > L->length + 1)) {
        return -1;//插入位置不合法，返回-1
    }
    if (L->length >= L->MaxSize) {  // 判断是否需要扩容
        int *newbase = (int *)realloc(L->data, (L->MaxSize + InitSize) * sizeof(int));
        if (!newbase) exit(-1);
        L->data = newbase;   // 重新分配内存空间
        L->MaxSize += InitSize;    // 扩容
    }

    int *q = &(L->data[i - 1]);
    for (int *p = &(L->data[L->length - 1]); p >= q; --p) {
        *(p+1) = *p;
    }
    *q = e;
    L->length++;

    return 0;
}

int main() {
    SeqList L;  // 声明一个顺序表
    InitList(&L);    // 初始化
    ListInsert(&L,1,5);
    printf("%d",L.data[0]);
    return 0;
}

