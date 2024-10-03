
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
const int N = 1e6 + 10, Mod = 1e9 + 7;
//int d[N];
int pre[N];
int anc[N];
void dfs(int node,int parent,int dist, vint *g) {
//    d[node] = dist;
    for(auto i : g[node]) {
        if (i == parent) continue;
        dfs(i,node,dist + 1,g);
        pre[i] = node;
    }
}
void solve(){
    int n,m;
    cin >> n >> m;
    vint g[n+1];
    rep(i,1,n) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    //int last = 1,fre[n+1] = {0};
    dfs(1,-1,1,g);
    vint s(m);
    bool vis[n+1] = {false};
    rep(i,0,m) {
        int x;
        cin >> x;
        if (!vis[anc[x]]){
            vis[anc[x]] = true;
            s[i] = anc[x];
            cout << "d";
            continue;
        }
        int ans = -1;
        vint path;
        for(int cur = x; cur != 0; cur = pre[cur]) {
            if (vis[cur]) {
                break;
            }
            ans = cur;
            path.push_back(x);
        }
        if (ans != -1) vis[ans] = true;
        else {
            cout << "f";
            s[i] = ans;
            anc[x] = ans;
            for(int j = 0;j < path.size() - 1;j++){
                cout <<"why\n";
                anc[path[j]] = path.back();
            }
            cout << "g";
        }
    }
    cout << s[0];
    rep(i,1,m) cout <<" " << s[i];
    cout << endl;

}
signed main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
    int test_n = 1;
    cin>>test_n;
    for(int t_c = 1;t_c <= test_n;t_c ++){
        rep(i,0,N) anc[i] = 1;
        solve();
    }

    return 0;
}
