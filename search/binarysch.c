#include "stdio.h"
// 二分查找
#include "stdlib.h"
typedef struct{
    int *elem;
    int Tablelen;
}SSTable;

int Binary_Search(SSTable L,int key){
    int low=0,high=L.Tablelen-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(L.elem[mid]==key){
            return mid;
        }else if (L.elem[mid]>key){
            high=mid-1;
        }else{
            high=mid+1;
        }
    }
    return -1;
}

// 分块查找
typedef struct{
    int maxValue;
    int low,high;
}Index; // 索引表

int List[100];

int IndexSearch(){
    for(int i=0;i<100;++i){
        List[i]=i+1;
    }

    Index IndexTable[10];
    int blockSize = 100/10;
    for(int i=0;i<blockSize;++i){
        IndexTable[i].low = i * blockSize;
        IndexTable[i].high = (i+1)*blockSize-1;
        IndexTable[i].maxValue = List[IndexTable[i].high];
    }
    for (int i = 0; i < 10; ++i) {
        printf("索引表 %d: maxValue = %d, low = %d, high = %d\n", i, IndexTable[i].maxValue, IndexTable[i].low, IndexTable[i].high);
    }

    return 0;
}


int blockSearch(int arr[],int n,int target){
    int blockSize = 3;
    int blockCount=(n+blockSize-1)/blockSize;

    int *indexArr = (int *)malloc(blockCount * sizeof(int));
    for(int i=0;i<blockCount;++i){
        indexArr[i]=arr[i*blockSize];
    }

    int left = 0,right=blockCount-1;
    while(left<=right){
        int mid = left+(right-left)/2;
        if(indexArr[mid]==target){
            free(indexArr);
            return mid*blockSize;
        }else if(indexArr[mid]<target){
            left = mid+1;
        }else{
            right=mid-1;
        }
    }

    int start = (left-1)*blockSize;
    int end=(left-1)*blockSize+blockSize-1;
    for(int i=start;i<=end;++i){
        if(arr[i]==target){
            free(indexArr);
            return i;
        }
    }
    
    free(indexArr);
    return -1;
}

int main() {
    int arr[] = {1, 5, 6, 34, 65, 32, 54, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 34;

    int index = blockSearch(arr, n, target);
    if (index != -1) {
        printf("目标元素 %d 的下标是 %d\n", target, index);
    } else {
        printf("目标元素 %d 不存在\n", target);
    }
    IndexSearch();
    return 0;
}