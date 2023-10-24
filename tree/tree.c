
// 双亲表示法(顺序存储)
#define MAXSIZE 200
typedef struct{
    int vlaue;
    int parent;
}PTNode;

typedef struct{
    PTNode nodes[MAXSIZE];
    int num;
}PTree;
/*
优点： 查指定结点的双亲很方便
缺陷： 查指定结点的孩子只能从头遍历
*/

// 孩子表示法
typedef struct{
    int value;
}Elemtype;
struct CTNode{
    int child;
    struct CTNode *next;
};
typedef struct{
    Elemtype data;
    struct CTNode *firstChild;
}CTBox;

typedef struct{
    CTBox nodes[MAXSIZE];
    int n,r;
}CTree;

// 孩子兄弟表示法(链式)
typedef struct CSNode{
    Elemtype data;
    struct CSNode *firstchild,*nextibling;
}CSNode,*CSTree;  