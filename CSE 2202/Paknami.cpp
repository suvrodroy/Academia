#include "bits/stdc++.h"
using namespace std;

#define int long long
#define dub long double
typedef vector<int> vint;
typedef vector<string> vstr;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef unordered_map<int,int> umap;
#define rep(i,j,k) for(int i=j;i<k;i++)
#define all(a) a.begin(),a.end()
#define endl '\n'
#define INF 2147483647
//#define INF 9223372036854775807
#define null '\0'
const int N = 1e5 + 10, Mod = 1e9 + 7;
int n,m;

class matrix
{
public:
    int size;
    vector<vint> mat;

    matrix(int n)
    {
        size = n;
        mat = vector<vint>(n, vint(n, 0));
    }

    matrix operator*(const matrix& other)
    {
        return multiply_divide_conquer(*this, other);
    }

    matrix multiply_divide_conquer(const matrix& A, const matrix& B)
    {
        int n = A.size;
        matrix result(n);
        if(n == 1)
        {
            result.mat[0][0] = A.mat[0][0] * B.mat[0][0];
        }
        else
        {
            int k = n / 2;

            matrix A11(k), A12(k), A21(k), A22(k);
            matrix B11(k), B12(k), B21(k), B22(k);

            rep(i,0,k) rep(j,0,k)
            {
                A11.mat[i][j] = A.mat[i][j];
                A12.mat[i][j] = A.mat[i][j + k];
                A21.mat[i][j] = A.mat[i + k][j];
                A22.mat[i][j] = A.mat[i + k][j + k];

                B11.mat[i][j] = B.mat[i][j];
                B12.mat[i][j] = B.mat[i][j + k];
                B21.mat[i][j] = B.mat[i + k][j];
                B22.mat[i][j] = B.mat[i + k][j + k];
            }

            matrix C11 = multiply_divide_conquer(A11, B11);
            matrix C12 = multiply_divide_conquer(A11, B12);
            matrix C21 = multiply_divide_conquer(A21, B11);
            matrix C22 = multiply_divide_conquer(A21, B12);

            matrix temp1 = multiply_divide_conquer(A12, B21);
            matrix temp2 = multiply_divide_conquer(A12, B22);
            matrix temp3 = multiply_divide_conquer(A22, B21);
            matrix temp4 = multiply_divide_conquer(A22, B22);

            rep(i,0,k) rep(j,0,k)
            {
                result.mat[i][j] = C11.mat[i][j] + temp1.mat[i][j];
                result.mat[i][j + k] = C12.mat[i][j] + temp2.mat[i][j];
                result.mat[i + k][j] = C21.mat[i][j] + temp3.mat[i][j];
                result.mat[i + k][j + k] = C22.mat[i][j] + temp4.mat[i][j];
            }
        }
        return result;
    }

    void print()
    {
        rep(i,0,size)
        {
            rep(j,0,size)
            {
                cout << mat[i][j] << ' ';
            }
            cout << endl;
        }
    }
};

void solve()
{
    cin >> n;
    matrix A(n), B(n);
    rep(i,0,n) rep(j,0,n) cin >> A.mat[i][j];
    rep(i,0,n) rep(j,0,n) cin >> B.mat[i][j];

    matrix C = A * B;
    C.print();
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_n = 1;
    cin >> test_n;
    for(int t_c = 1; t_c <= test_n; t_c++)
    {
        solve();
    }
    return 0;
}
