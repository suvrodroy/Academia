#include "bits/stdc++.h"
using namespace std;

#define int long long
#define rep(i,j,k) for(int i=j;i<k;i++)
#define endl '\n'

void radix_sort(int arr[], int n) {
    int div = 1;
    const int base = 10;
    int max_digits = 4;
    vector<int> fre[base];

    while (max_digits--) {
        rep(i, 0, n) {
            int digit = (arr[i] / div) % base;
            fre[digit].push_back(arr[i]);
        }
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

void solve() {
    int n = 10;
    int arr[] = {10, 6, 2, 123, 14, 50, 33, 6, 10, 14};
    
    radix_sort(arr, n);

    cout << "The result: ";
    rep(i, 0, n) cout << arr[i] << " ";
    cout << endl;
}

signed main() {
    solve();
    return 0;
}
