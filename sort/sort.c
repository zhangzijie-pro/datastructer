#include "stdbool.h"
// 插入排序    平均时间复杂度 O(n^2)
void InsertSort_0(int A[],int n){
    int i,j,temp;
    for(i=1;i<n;i++)
        if(A[i]<A[i-1]){  // 若A[i]关键字小于前驱
            temp = A[i];  // 用temp暂存A[i]
            for(j=i-1;i>=0&&A[j]>temp;--j) // 检查所有之前排好序的元素
                A[j+1]=A[j];    // 所有大于temp的元素向后挪
            A[j+1]=temp;    // 复制到插入位置
        }
}
// 最好时间复杂度 O(n)   最坏(平均)时间复杂度 O(n^2)

// 插入排序(带哨兵)
void InsertSort_1(int A[],int n){
    int i,j;
    for(i=2;i<n;i++)
        if(A[i]<A[i-1]){  // 若A[i]关键字小于前驱
            A[0] = A[i];  // 复制为哨兵，A[0]不存放元素
            for(j=i-1;A[0]<A[j];--j) // 从后往前找待插入位置
                A[j+1]=A[j];    // 向后挪
            A[j+1]=A[0];    // 复制到插入位置
        }
}

// 插入折半排序
void InsertSort(int A[],int n){
    int i,j,low,high,mid;
    for(i=2;i<=n;i++){
        A[0]=A[i];
        low=1;high=i-1;         // 设置折半查找的范围
        while(low<=high){
            mid=(low+high)/2;
            if(A[mid]>A[0]) high=mid-1; // 查找左子表
            else low=mid+1;             // 查找右子表
        }
        for(j=i-1;j>=high+1;--j)
            A[j+1]=A[j];                // 后移元素，空出插入位置
        A[high+1]=A[0];                 // 插入操作
    }
}

// 希尔排序
void ShellSort(int A[],int n){
    int d,i,j;
    for(d=n/2;d>=i;d=d/2){       // 步长变化
        for(i=d+1;i<=n;++i){
            if(A[i]<A[i-d]){       // 需将A[i]插入有序增量子表
                A[0]=A[i];          // 暂留在A[0]
                for(j=i-d;j>0&&A[0]<A[j];j-=d)
                    A[j+d]=A[j];    // 记录后移
                A[j+d]=A[0];        // 插入
            }
        }
    }
}
// 最好时间复杂度 O(n)   最坏(平均)时间复杂度 O(n^2)
// 空间复杂度 O(1)

// 冒泡排序
int swap(int a,int b){
    int temp = a;
    a=b;
    b=temp;
    return a,b;
}
void BubbleSort(int A[],int n){
    for(int i=0;i<n-1;i++){
        bool flag = false;
        for(int j=n-1;j>i;j--)
            if(A[j-1]>A[j]){
                swap(A[j-1],A[j]);
                flag = true;
            }
        if(flag==true) return;
    }
}

// 快速排序
int Partition(int A[],int low,int high){
    int pivot = A[low];
    while(low<high){
        while(low<high && A[high]>=pivot) --high;
        A[low]=A[high];
        while(low<high && A[low]<=pivot) ++low;
        A[high]=A[low];
    }
    A[low] = pivot;
    return low;
}

int QuickSort(int A[],int low,int high){
    if(low<high){
        int pivotpos = Partition(A,low,high);
        QuickSort(A,low,pivotpos-1);
        QuickSort(A,pivotpos+1,high);
    }
}

// 简单选择排序
void SelectSort(int A[],int n){
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+1;j<n;j++)
            if(A[j]<A[min]) min=j;
        if(min!=i) swap(A[i],A[min]);
    }
}

// 将以k为根的子树进行调整
void HeadAdjust(int A[],int k,int len){
    A[0]=A[k];          // A[0]暂存根结点
    for(int i=2*k;i<=len;i*=2){ // 沿k较大的子节点向下筛选
        if(i<len&&A[i]<A[i+1])
            i++;                // 取k较大的子节点的下标
        if(A[0]>=A[i]) break;   // 筛选结果
        else{
            A[k]=A[i];          // 将A[i]调整为双亲结点上
            k=i;                // 修改k值， 以便继续向下筛选
        }
    }
    A[k]=A[0];                  // 被筛选的值放入最终结点
}

// 建立大根堆
void BuildMaxHeap(int A[],int len){
    for(int i=len/2;i>0;i--){     // 从后往前调整所有非终端结点
        HeadAdjust(A,i,len);
    }
}

// 堆排序
void HeapSort(int A[],int len){
    BuildMaxHeap(A,len);
    for(int i=len;i>1;i--){
        swap(A[i],A[1]);
        HeadAdjust(A,1,i-1);
    }
}

// 归并排序


void Merge(int A[],int low,int mid,int high){
    int i,j,k;
    int *B = (int *)malloc(100*sizeof(int));
    for(k=low;k<=high;k++){
        B[k]=A[k];
    }
    for(i=low,j=mid+1,k=i;i<=mid&&j<=high;k++){
        if(B[i]<=B[j])
            A[k]=B[i++];
        else    
            A[k]=B[j++];
    }
    while(j<=mid) A[k++]=B[i++];
    while(j<=high) A[k++]=B[j++];
} 

void MergeSort(int A[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;       // 从中间划分
        MergeSort(A,low,mid);       // 从左边划分归并排序
        MergeSort(A,mid+1,high);    // 从右边划分归并排序
        Merge(A,low,mid,high);      // 归并
    }
}

int main(){
    int str[]={2,1,5,4,7};
    int len = 5;
    BubbleSort(str,len);
}
