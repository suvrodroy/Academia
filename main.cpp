#include "bits/stdc++.h"
using namespace std;


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
vector<int> a;
int findMin(int l, int r)
{
    if (l > r) return INT_MAX;
    if (l == r) return a[l];
    int mid = (l+r)/2;
    int left = findMin(l,mid);
    int right = findMin(mid+1,r);
    return min(left,right);
};
int findMax(int l,int r)
{
    if (l > r) return 0LL;
    if (l == r) return a[l];
    int mid = (l+r)/2;
    int left = findMax(l,mid);
    int right = findMax(mid+1,r);
    return max(left,right);
};
pair<int,int> findMinMax(int l,int r)
{
    if (l > r) return make_pair(INT_MAX,0LL);
    if (l == r) return make_pair(a[l],a[l]);
    int mid = (l+r)/2;
    auto left = findMinMax(l,mid);
    auto right = findMinMax(mid+1,r);
    return make_pair( min(left.first,right.first) , max(left.second,right.second));
};
void solve(){
    cout << "Enter number of  elements: ";
    cin >> n;
    a.resize(n);
    cout << "Enter array: ";
    rep(i,0,n) cin >> a[i];

    cout << "Query Type\n1) 1 l r -> finds the smallest element in range [l,r](zero based indexing)\n";
    cout << "2) 2 l r -> finds the largest element in range [l,r](zero based indexing)\n";
    cout << "3) 3 l r -> finds the smallest and largest element in range [l,r](zero based indexing)\n";
    cout << "4) 4 ends query\n";
    int t,l,r;
    while (cin >> t)
    {
        if (t == 4) break;
        cin >> l >> r;
        if (t == 1)
            cout << "Smallest in range [" << l << "," <<r << "] is " << findMin(l,r) << endl;
        if (t == 2)
            cout << "largest in range [" << l << "," <<r << "] is " << findMax(l,r) << endl;
        if (t == 3)
        {
            auto p = findMinMax(l,r);
            cout << "Smallest and largest in range [" << l << "," <<r << "] is " << p.first << " and " << p.second << endl;
        }
    }
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
