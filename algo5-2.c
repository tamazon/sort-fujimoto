#include "sort.h"

// ********
// アルゴリズム 5.2  挿入ソート
// ********
void insertionsort(
    int n,     // データの個数
    double D[] // データ D[0], ..., D[n-1]
)
{
    int i, j;
    double x;
    for (i = 1; i < n; i = i + 1)
    {
        x = D[i];
        j = i;
        while ((D[j - 1] > x) && (j > 0))
        {
            D[j] = D[j - 1];
            j = j - 1;
        }
        D[j] = x;
    }
}

// **** EOF
