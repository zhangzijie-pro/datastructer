// 败者树
#include "stdio.h"
#define MAX_NODE 100
#define MAX_VALUE 10000000

int tree[MAX_NODE];
int leaves[MAX_NODE];
int num_nodes;

void init_tree(){
    for(int i=0;i<num_nodes; i++){
        tree[i] = -1;
    }
}

void updata(int node){
    int winner = node;
    while(winner>0){
        int parent = (winner + num_nodes)/2;
        if(tree[parent]==-1 || leaves[winner]<leaves[tree[parent]]){
            int tmp = winner;
            winner = tree[parent];
            tree[parent]=tmp;
        }
        else{
            break;
        }
    }
    tree[0]=winner;
}

void insert(int value){
    leaves[num_nodes]=value;
    updata(num_nodes);
    num_nodes++;
}

int get_min(){
    return leaves[tree[0]];
}

int main() {
    // 初始化
    num_nodes = 0;
    init_tree();

    // 插入叶子节点
    insert(5);
    insert(3);
    insert(7);
    insert(1);

    // 获取最小值
    printf("Min Value: %d\n", get_min());

    return 0;
}