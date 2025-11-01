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
    cout << "Begin here\n";
    vector<vector<int>> a(5);
     a[0] = {1,2,3,4,5,6}; // size 6
     a[1] = {1,5,8}; // size 3
     a[2] = {1,5,6,12,13,18,20,28,29,40}; // size 10
     a[3] = {1,5,10,22,31,33,34,38,42,46,52,53,58}; // size 13
     a[4] = {1,5,6,7,8}; // size 5
    set<pair<int,int>> st;
    for (int i = 0; i < 5 ; i++)
    {
        st.insert({a[i].size(), i});
    }

    auto merge = [&](vector<int> &left,vector<int> &right) -> void
    {
        vector<int> temp(left.size() + right.size());
        int i = 0, j = 0, k = 0;
        while (i < left.size() and j < right.size())
        {
            if (left[i] < right[j])
                temp[k++] = left[i++];
            else temp[k++] = right[j++];
        }
        while (i < left.size())
            temp[k++] = left[i++];
        while (j < right.size())
            temp[k++] = right[j++];
        left = temp;
        right.clear();
    };
    cout << "here is why " << st.size() << endl;
    while (st.size() > 1)
    {
        auto fst = prev(st.end());
        auto snd = prev(fst);
        int l = fst->second, r = snd->second;
        st.erase(fst), st.erase(snd);
        merge(a[l],a[r]);
        st.insert({a[l].size(), l});
    }
    auto it = st.begin();
    cout << "Final merged array at index " << it->second << endl;
    cout << "Merged Array: "; for (auto i : a[it->second]) cout << i << " "; cout << endl;
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