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
int find_side(pii p, pii p1, pii p2)
{
    int res = (p2.first - p1.first) * (p.second - p1.second) -
              (p2.second - p1.second) * (p.first - p1.first);
    if (res > 0) return 1;
    if (res < 0) return -1;
    return 0;
}
vii GrahamScan(vii points)
{
    if (points.size() <= 3) return points;
    vector<pii> st;
    pii base = {INF,INF};
    for (auto &[x,y] : points)
        if (y < base.second) base = {x,y};
    vector<pair<double, pii>> v;
    // cout << "Maybe\n";
    for (auto &[x,y] : points)
    {
        if (make_pair(x,y) == base) continue;
        // double theta = atan2(y - base.second, x - base.first);
        double theta = (x - base.first == 0) ? acos(-1)*0.5 : atan((y-base.second)/(x - base.first));
        v.push_back({theta, {x,y}});
    }
    // cout << "Here\n";
    sort(all(v));
    st.push_back(base);
    for(auto &[t,p] : v) {
        // cout << "Point " << p.first << " " << p.second << endl;
        // cout << "Current Stack: \n" ;
        // for (auto i : st) cout << i.first << " " << i.second << endl;
        while(st.size() >= 2 && find_side(st[st.size() - 2], st.back(), p ) < 0)
        {
            st.pop_back();
        }
        st.push_back(p);
    }
    return st;
}
void solve(){
    vii points = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0},
                  {0, 0}, {3, 3}, {4, 2}, {2, 4}, {1, 3}};
    vii ConvexHull = GrahamScan(points);
    cout << "Convex Hull:\n";
    for (auto &[x,y] : ConvexHull)
    {
        cout << "(" << x <<", " << y <<"), ";
    }
    cout << endl;
}
signed main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    int test_n = 1;
    // cin>>test_n;
    for(int t_c = 1;t_c <= test_n;t_c ++){
        solve();
    }
    return 0;
}