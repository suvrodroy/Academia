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
vint sz, per;
struct Edge
{
    int u, v, wt;
    bool operator < (const Edge &other) const
    {
        return wt < other.wt;
    }
};
int find_set(int u)
{
    if (per[u] == u) return u;
    return per[u] = find_set(per[u]);
}
bool union_set(int u,int v)
{
    int a = find_set(u);
    int b = find_set(v);
    if (sz[a] < sz[b])
        swap(a,b);
    if (a != b)
    {
        per[b] = per[a];
        sz[a] += sz[b];
        return true;
    }
    return false;
}
void solve(){
    cin >>n >> m;
    per.resize(n+1);
    sz.resize(n+1);
    iota(all(per), 0);
    rep(i,0,n) per[i+1] = i + 1;
    vector<Edge> edges(m),res;
    rep(i,0,m) cin >> edges[i].u >> edges[i].v >> edges[i].wt;
    sort(all(edges));
    for (auto i : edges)
    {
        if (union_set(i.u, i.v))
        {
            res.push_back(i);
        }
    }
    cout << "Edges in MST:\n";
    for (auto [u,v,wt] : res)
        cout << u << " - " << v << endl;
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
6 6
1 4 2
4 3 3
3 6 4
6 2 2
2 1 5
5 1 1
**/