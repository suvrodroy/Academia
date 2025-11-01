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
#define INF 1000000
//#define INF 9223372036854775807
#define null '\0'
const int N = 1e4 + 10, Mod = 1e9 + 7;
int n,m;
int dp[N];
int f(int wt, vint &a)
{
    if (wt == 0) return dp[wt] = 0;
    if (dp[wt] != -1) return dp[wt];
    int ans = INF;
    for (auto w : a)
    {
        if (w <= wt)
            ans = min(ans, f(wt - w, a) + 1);
    }
    return dp[wt] = ans;
}
void solve(){
    memset(dp,-1,sizeof(dp));
    cin >> n >> m;
    vint a(n);
    rep(i,0,n) cin >> a[i];
    f(m, a);
    vint coins;
    while (m > 0)
    {
        for (auto w : a)
        {
            if (w > m) continue;
            if (dp[m - w] + 1 == dp[m])
            {
                coins.push_back(w);
                m -= w;
                break;
            }
        }
    }
    cout << coins.size() << endl;
    for (auto i : coins) cout << i << " "; cout << endl;
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
3 11
1 5 7
3 11
1 5 12
**/