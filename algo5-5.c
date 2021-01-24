﻿#include "sort.h"
#include "stdio.h"
// ヒープを表す２分木の配列のサイズ
int      size;

double push_heap(
    double T[],
    double x
)
{
    size=size+1;
    T[size]=x;
    int k=size;
    while((T[k]>T[k/2])&&(k>1)) {
        swap(&T[k],&T[k/2]);
        k=k/2;
    }
}

// ********
// ヒープから最大値を取り出す
// ********
double delete_maximum(
    double  T[]     // ヒープを表す２分木の配列 T[1], ..., T[N]
)
{
    int     k, big;
    double  max;

    // 根にある最大値を取り出す
    if( size > 0 ) {
        max = T[1];
    }
    else {
        printf( "size = 0 in delete_maximum()." );
        return( 0.0 );  // この戻り値は意味がない値
    }

    // ヒープの再構成
    T[1] = T[size]; // ヒープの最後のデータを根に移動して移動データとする
    size--;         // ヒープのサイズを１だけ減らす
    k = 1;          // 移動データの位置 k を設定
    while( 2*k <= size ) {  // 移動データが子を持つ場合　
        // **** 子が１つの場合
        if( 2*k == size ) {
            // 親子の値の比較と交換
            if( T[k] < T[2*k] ) {           // 移動データ T[k] と子の値 T[2*k] を比較
                swap( &(T[k]), &(T[2*k]) ); // 移動データ T[k] のほうが小さければ交換
                k = 2*k;                    // 子の位置 2*k を移動データの新たな位置 k にする
            }
            else {
                break;                      // アルゴリズムを終了
            }
        }
        // **** 子が２つの場合
        else {
            // 子兄弟の値のうちで大きなほうを選ぶ
            if( T[2*k] > T[2*k+1] ) {       // 子兄弟の値を比較
                big = 2*k;                  // 左側の子を選ぶ
            }
            else {
                big = 2*k+1;                // 右側の子を選ぶ
            }
            // 親子の値の比較と交換
            if( T[k] < T[big] ) {           // 移動データ T[k] と選ばれた子の値 T[big] を比較
                swap( &(T[k]), &(T[big]) ); // 移動データ T[k] のほうが小さければ交換
                k = big;                    // 選ばれた子の位置 big を移動データの新たな位置 k にする
            }
            else {
                break;                      // アルゴリズムを終了
            }
        }
    }

    // 最初に取り出した最大値を戻り値として出力
    return( max );
}
// ********
// アルゴリズム 5.5  ヒープソート
// ********
void heapsort_fujimoto(
    int     n,      // データの個数
    double  D[]     // データ D[0], ..., D[n-1]
)
{
    int i;
    double T[N];
    int size=0;
    for(i=0; i<n; i=i+1) {push_heap(T,D[i]);}
    for(i=n-1; i>=0; i=i-1) {D[i]=delete_maximum(T);}

}

// **** EOF
