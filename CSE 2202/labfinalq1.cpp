#include "bits/stdc++.h"
using namespace std;

// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
void merge(int low,int mid, int high,vint &a)
{
    vint c(high - low + 1);
    int i = low, j = mid + 1, k = 0;
    while (i <= mid and j <= high)
    {
        if (a[i] < a[j])
            c[k++] = a[i++];
        else c[k++] = a[j++];
    }
    while (i <= mid)
        c[k++] = a[i++];
    while (j <= high)
        c[k++] = a[j++];
    i = low, j = 0;
    while (i <= high) a[i++] = c[j++];
}
void mergeSort(int low, int high, vint &a)
{
    if (low >= high) return;
    int mid = (low + high) / 2;
    mergeSort(low, mid, a);
    mergeSort(mid+1, high,a);
    merge(low,mid,high,a);
}
void solve(){
    cin >> n;
    vint a(n);
    rep(i,0,n) cin >> a[i];
    mergeSort(0,n-1,a);
    for (auto i : a) cout << i << " "; cout << endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_n = 1;
    // cin>>test_n;
    for(int t_c = 1;t_c <= test_n;t_c ++){
        solve();
    }
    return 0;
}
/**
6
92 15 67 15 120 48
7
92 15 67 15 120 48 10
**/