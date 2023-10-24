#include "limits.h"
#include "math.h"
int plusD(int A[],int a,int B[],int b,int C[],int c){
    int i=0,j=0,k=0;
    int min=INT_MIN;
    while(i<a&&j<b&&k<c){
        int D=abs(A[i]-B[j])+abs(B[j]-C[k])+abs(A[i]-C[k]);
        if(D>min){
            min=D;
        }
        if(A[i]<=B[j]&&A[i]<=C[k])
        {
            i++;
        }
        else if (B[j]<=A[i]&&B[j]<=C[k])
        {
            j++;
        }
        else{
            k++;
        }
    }

    return min;
}