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
void radix_sort(vint arr, int n) {
    int div = 1;
    const int base = 10;
    int max_digits = 4; // or compute dynamically based on max element
    vector<int> fre[base];
    while (max_digits--) {
        // Distribute into buckets by current digit
        rep(i, 0, n) {
            int digit = (arr[i] / div) % base;
            fre[digit].push_back(arr[i]);
        }
        // Collect back into array
        int j = 0;
        rep(i, 0, base) {
            for (int x : fre[i]) {
                arr[j++] = x;
            }
            fre[i].clear();
        }
        div *= base;
    }
}
void solve(){

}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_n = 1;
    cin>>test_n;
    for(int t_c = 1;t_c <= test_n;t_c ++){
        solve();
    }
    return 0;
}