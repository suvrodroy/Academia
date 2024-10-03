#include "bits/stdc++.h"
using namespace std;
int main()
{
    int a,n,m,b;
    cout << "Entering First Matrix:\n";
    cout << "Enter row: "; cin >> a;
    cout << "Enter column: "; cin >> n;
    cout << "Enter matrix:\n";
    int A[a][n];
    for(int i = 0;i < a;i ++) {
        for(int j = 0;j < n;j++)
            cin >> A[i][j];
    }
    cout << "Entering Second Matrix:\n";
    cout << "Enter row: "; cin >> m;
    cout << "Enter column: "; cin >> b;
    cout << "Enter matrix:\n";
    int B[m][b];
    for(int i = 0;i < m;i ++) {
        for(int j = 0;j < b;j++)
            cin >> B[i][j];
    }
    clock_t start = clock();
    if (n != m) {
        cout << "Matrix cannot be multiplied\n";
        clock_t ending = clock();
        double time = ending - start;
        cout << "execution time = " << time << endl;
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
    cout << "After Multiplication:\n";
    for(int i =0;i < a;i++)
    {
        for(int j = 0;j<b;j++)
        {
            cout << setw(4) << res[i][j];
        }
        cout << endl;
    }
    clock_t ending = clock();
    double time = double(ending - start)/CLOCKS_PER_SEC;
    cout << "execution time = " << time << endl;
}
/*
3 4 1 2 3 4 5 6 7 8 9 10 11 12
3 4 1 2 3 4 5 6 7 8 9 10 11 12
4 3 1 2 3 4 5 6 7 8 9 10 11 12
*/
