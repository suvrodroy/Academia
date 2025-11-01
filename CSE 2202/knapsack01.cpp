#include <bits/stdc++.h>
using namespace std;

int knaprec(int W, vector<int> &wt, vector<int> &val, int n, vector<vector<int>> &dp) {
    if (n == 0 || W == 0) return 0;
    if (dp[n][W] != -1) return dp[n][W];
    if (wt[n - 1] > W) return dp[n][W] = knaprec(W, wt, val, n - 1, dp);
    return dp[n][W] = max(val[n - 1] + knaprec(W - wt[n - 1], wt, val, n - 1, dp),
                          knaprec(W, wt, val, n - 1, dp));
}

int knapit(int W, vector<int> &wt, vector<int> &val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}

int main() {
    int n, W;
    cin >> n;
    vector<int> wt(n), val(n);
    for (int i = 0; i < n; i++) cin >> wt[i];
    for (int i = 0; i < n; i++) cin >> val[i];
    cin >> W;
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    cout << knaprec(W, wt, val, n, dp) << endl;
    cout << knapit(W, wt, val, n) << endl;
    return 0;
}
