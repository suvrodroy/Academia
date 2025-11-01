#include "bits/stdc++.h"
using namespace std;

typedef vector<int> vint;
vector<vint> add(vector<vint> &a, vector<vint> &b)
{
    int n = a.size();
    vector<vint> c(n, vint(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    return c;
}
vector<vint> multi(vector<vint> &a, vector<vint> &b)
{
    int n = a.size();
    vector<vint> c(n, vint(n));

    if (n == 1)
    {
        c[0][0] = a[0][0] * b[0][0];
        return c;
    }

    int new_n = n / 2;
    vector<vint> a11(new_n, vint(new_n)), a12, a21, a22, b11, b12, b21, b22;
    a12 = a21 = a22 = b11 = b12 = b21 = b22 = a11;
    for (int i = 0; i < new_n; i++)
    {
        for (int j = 0; j < new_n; j++)
        {
            a11[i][j] = a[i][j];
            a12[i][j] = a[i][j + new_n];
            a21[i][j] = a[i + new_n][j];
            a22[i][j] = a[i + new_n][j + new_n];

            b11[i][j] = b[i][j];
            b12[i][j] = b[i][j + new_n];
            b21[i][j] = b[i + new_n][j];
            b22[i][j] = b[i + new_n][j + new_n];
        }
    }
    vector<vint> m1 = multi(a11,b11), m2 = multi(a12,b21);
    vector<vint> c11 = add(m1,m2);
    m1 = multi(a11,b12), m2 = multi(a12,b22);
    vector<vint> c12 = add(m1,m2);
    m1 = multi(a21,b11), m2 = multi(a22,b21);
    vector<vint> c21 = add(m1,m2);
    m1 = multi(a21,b12), m2 = multi(a22,b22);
    vector<vint> c22 = add(m1,m2);

    for (int i = 0; i < new_n; i++)
    {
        for (int j = 0; j < new_n; j++)
        {
            c[i][j] = c11[i][j];
            c[i][j + new_n] = c12[i][j];
            c[i + new_n][j] = c21[i][j];
            c[i + new_n][j + new_n] = c22[i][j];
        }
    }

    return c;
}

signed main()
{
    int n;
    cin >> n;

    vector<vint> a(n, vint(n));
    vector<vint> b(n, vint(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> b[i][j];

    vector<vint> c = multi(a, b);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << c[i][j] << " ";
        cout << "\n";
    }
}
