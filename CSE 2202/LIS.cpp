#include "bits/stdc++.h"
using namespace std;

int n;
vector<int> a;
vector<int> dp;
int LISRec(int i)
{
    if (i >= n) return 0;
    if (dp[i] != -1) return dp[i];
    LISRec(i+1);
    int ans2 = 1;
    for (int j = i+1; j < n; j++)
    {
        if (a[j] > a[i])
            ans2 = max(ans2, LISRec(j) + 1);
    }
    return dp[i] = ans2;
}
int LISIt()
{
    vector<int> dp(n);
    for (int i = 0;i < n; i++)
    {
        for (int j = 0;j < i; j++)
        {
            if (a[j] < a[i])
                dp[i] = max(dp[i], dp[j]);
        }
        dp[i]++;
    }
    return *max_element(dp.begin(), dp.end());
}
int main()
{
    cin >> n;
    a.resize(n);
    dp.resize(n,-1);
    for (int i = 0;i < n; i++)
        cin >> a[i];
    LISRec(0);
    cout << *max_element(dp.begin(), dp.end()) << " " << LISIt() << endl;
    for (auto i : dp) cout << i << endl;
}
/*
10
11 12 6 8 13 9 10 15 17 2
*/