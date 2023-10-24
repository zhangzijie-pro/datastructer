#include "stdbool.h"

#define MAX_VERTEX_NUM 20
bool visited[MAX_VERTEX_NUM];
#define MaxVertexNum 100
typedef struct{
    char Vex[MaxVertexNum]; // 顶点表
    int Edge[MaxVertexNum][MaxVertexNum];   // 矩阵
    int vexnum,arcnum;           // 图的当前定点数和边数/狐数
}MGraph;

typedef struct{
    char data[MaxVertexNum];
    int front,rear;
}SqQueue;

void InitQueue(SqQueue &s){
    s.size=s.front=s.rear=0;
}
// 入队操作
bool EnQueue(SqQueue &s,int x){
    if((s.rear+1)%MaxVertexNum==s.front){
        return false;
    }
    s.data[s.rear]=x;
    s.rear=(s.rear+1)%MaxVertexNum;
    s.size++;
    s.tag=1;
    return true;
}
bool OutQueue(SqQueue &s,int &x){
    if(s.rear==s.front){
        return false;
    }
    x=s.data[s.front];
    q.front=(q.front+1)%MaxVertexNum;
    s.size--;
    s.tag=0;
    return true;
}

void visit(MGraph *G){
    
}

void BFSTraverse(MGraph G){
    SqQueue Q;
    for(int i=0;i<G.vexnum;++i)
        visited[i]=false;
    InitQueue(Q);
    for(int i=0;i<G.vexnum;++i)
        if(!visited[i])
            BFS(G,i,Q);
}

void BFS(MGraph G,int v,SqQueue Q){
    visit(v);
    visited[v]=true;
    Enqueue(Q,v);
    while(!isEmpty(Q)){
        Dequeue(Q,v);
        for(int w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w))
            if(!visited[w]){
                visit(w);
                visited[w]=true;
                EnQueue(Q,w);
            }
    }
}

// 深度遍历
void DFS(MGraph G,int v){
    visit(G);
    visited[v] = true;
    for(int w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w))
        if(!visited[w]){
            DFS(G,w);
        }
}

// 最短路径问题  1,无向无权图 广度优先遍历
void BFS_MIN_Distance(MGraph G,int u){
    for(int i=0;i<G.vexnum;++i){
        d[i]=~;
        path[i]=-1;
    }
    d[u]=0;
    visited[u]=true;
    EnQueue(Q,u);
    while(!isEmpty(Q)){
        OutQueue(Q,u);
        for(int w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,u,w))
            if(!visited[w]){
                d[w]=d[u]+1;
                path[w]=u;
                visited[w]=true;
                OutQueue(Q,w);
            }
    }
}

// 2,Dijstra算法， 带权图，无权图
bool final[5]  // 标记各顶点是否已找到最短路径
int dist[5]   // 最短路径长度
int path[5]   // 路径上的前驱


// 3,Floyd算法 带权图，无权图  动态规划

