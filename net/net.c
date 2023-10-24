
// 邻接矩阵法
#define MaxVertexNum 100
typedef struct{
    char Vex[MaxVertexNum]; // 顶点表
    int Edge[MaxVertexNum][MaxVertexNum];   // 矩阵
    int vexnum,arcnum;           // 图的当前定点数和边数/狐数
}MGraph;

// 邻接矩阵法存储带权图
#define MAXVERTEXNUM 100;
#define INFINITY;  // 宏定义常量无穷
typedef char VertexType;    // 顶点的数据类型
typedef int EdgeType;      // 权值的数据类型
typedef struct{ 
    VertexType Vex[MAXVERTEXNUM];               // 顶点
    EdgeType Edge[MAXVERTEXNUM][MAXVERTEXNUM];  // 边的权
    int vexnum,arcnum;
}MGraph_2;

// 邻接表  与孩子表示法相似
#define MAX_NUM 20;
// 边，弧
typedef struct ArcNode{
    int adjvex;                // 指向哪个结点
    struct ArcNode *next;     // 指向下一条弧的指针
}ArcNode;
// 顶点
typedef struct VNode{
    VertexType data;      // 顶点信息
    ArcNode *first;       // 第一条边
}VNode,AdjList[MaxVertexNum];
// 图
typedef struct{
    AdjList vertices;
    int vexnum,arcnum;
}ALGraph;