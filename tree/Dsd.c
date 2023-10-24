#define MAXSIZE 200
typedef struct{
    int vlaue;
    int parent;
}PTNode;

typedef struct{
    PTNode nodes[MAXSIZE];
    int num;
}PTree;


int UFSet[MAXSIZE];
void InitTree(int S[]){
    for(int i=0;i<MAXSIZE;i++){
        S[i]=-1;
    }
}

int Find(int S[],int x){
    while(S[x]>=0){
        x=S[x];
    }
    return x;
}

int Find(int S[],int x){
    int root = x;
    while(S[root]>=0) root=S[root];
    while(x!=root){
        int t = s[x];
        s[x]=root;
        x=t;
    }
    return root;
}

void Union(int S[],int Root1,int Root2){
    if(Root2==Root1) return ;
    S[Root2]=Root1; 
}

// 区分小树合并到大树
void Union(int S[],int Root1,int Root2){
    if(Root1==Root2){
        return;
    }
    if(S[Root2]>S[Root1]){
        S[Root1] += S[Root2];
        S[Root2]=Root1;
    }else{
        S[Root2] += S[Root1];
        S[Root1]=Root2;
    }
}