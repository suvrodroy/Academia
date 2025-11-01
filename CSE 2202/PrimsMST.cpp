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
void solve(){
    cin >> n >> m;
    vector<vector<pair<int,int>>> g(n+1);
    vector<int> p(n+1,0),cost(n+1,INF);
    for (int i = 1;i <= m;i ++)
    {
        int u,v,w; cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    cost[1] = 0;
    set<pair<int,int>> st;
    st.insert({0,1});
    int sum = 0;
    bool vis[n+1] = {false};
    while (!st.empty())
    {
        auto [W,node] = *st.begin();
        st.erase(st.begin());
        if (W > cost[node] or vis[node]) continue;
        vis[node] = true;
        for (auto &[to,wt] : g[node])
        {
            if (wt < cost[to] and !vis[to])
            {
                cost[to] = wt;
                p[to] = node;
                st.insert({cost[to], to});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (p[i]) cout << i << " " << p[i] << endl;
    }
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