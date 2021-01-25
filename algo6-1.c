#include "sort.h"

// ********
// アルゴリズム 6.1  クイックソート
// ********
int partition(
    double D[],
    int left,
    int right
)
{
    int k = (left + right)/2; // kの簡単な決め方の例
    // int k = right; // kの簡単な決め方の例
    swap(&D[k], &D[right]);
    int i = left;
    int j = right-1;
    while(i<=j){
        while(D[i]<D[right]) { i=i+1; }
        while(D[j]>=D[right] && j>=i) { j=j-1; }
        if(i<j) swap(&D[i], &D[j]);
    }
    swap(&D[i], &D[right]);
    return i;
}

void quicksort(
    double  D[],    // データ D[left], ..., D[right]
    int     left,   // ソートの対象とする配列 D の左端の位置
    int     right   // ソートの対象とする配列 D の右端の位置
)
{
    if(left<right) {
        int pivot_index=partition(D,left,right);
        quicksort(D,left,pivot_index-1);
        quicksort(D,pivot_index+1,right);
    }
}

// **** EOF
