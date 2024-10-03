#include "bits/stdc++.h"
using namespace std;
template <typename t, typename u>
class A{
private:
    t x;
    u y;
public:
    A(t x, u y) : A(x,y) {}
    void set(t x, u y) {
        this-> x = x;
        this-> y = y;
    }
    auto get_sum() {return x + y;}
};

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