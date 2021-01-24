#include "sort.h"
#include "stdio.h"

// ********
// アルゴリズム 7.3  マージソート
// ********
void merge(
    double  D[],
    int     left,
    int     mid,
    int     right  
)
{
    int x=left;
    int y=mid+1;
    int i;
    double M[right-left+1];
    for (i=0; i<=right-left; i=i+1) {
        if(x==mid+1) {M[i] = D[y]; y=y+1;}
        else if(y==right+1) {M[i]=D[x]; x=x+1;}
        else if(D[x]<=D[y]) {M[i]=D[x]; x=x+1;}
        else {M[i]=D[y]; y=y+1;}

    }
    int j = left;
    // for(int j=0; j<N; j++) { printf("M[%d]: %lf\n", j, M[j]); }
    // printf("left:%d, mid:%d, right%d\n", left, mid, right);
    // for (int i=left; i<=right; i=i+1) {D[i]=M[i]; }
    for (i=0; i<=right-left; i=i+1) {D[j]=M[i];j++;}
    // printf("%lf, ",D[i]);
}
void mergesort_fujimoto(
    double  D[],    // データ D[left], ..., D[right]
    int     left,   // ソートの対象とする配列 D の左端の位置
    int     right   // ソートの対象とする配列 D の右端の位置
)
{
    int mid=(left + right)/2;
    // printf("%d, %d, %d\n",left, mid, right);
    if(left < mid) mergesort_fujimoto(D, left, mid);
    if(mid +1 < right) mergesort_fujimoto(D, mid+1, right);
    merge(D, left, mid, right);

    // printf("D[]: %lf, %lf, %lf, %lf, %lf\n",D[0],D[1],D[2],D[3],D[4]);
}

// **** EOF
