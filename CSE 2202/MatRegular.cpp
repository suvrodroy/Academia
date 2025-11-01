#include "bits/stdc++.h"
using namespace std;
int main()
{
    int a,n,m,b;
    int A[a][n];
    for(int i = 0;i < a;i ++) {
        for(int j = 0;j < n;j++)
            cin >> A[i][j];
    }
    int B[m][b];
    for(int i = 0;i < m;i ++) {
        for(int j = 0;j < b;j++)
            cin >> B[i][j];
    }
    if (n != m) {
        return 0;
    }
    int res[a][b];
    for(int i =0;i<a;i++)
    {
        for(int j = 0;j < b;j++)
        {
            int sum = 0;
            for(int k =0;k < n;k++) {
                sum += A[i][k] * B[k][j];
            }
            res[i][j] = sum;
        }
    }
    for(int i =0;i < a;i++)
    {
        for(int j = 0;j<b;j++)
        {
            cout << setw(4) << res[i][j];
        }
        cout << endl;
    }
}

