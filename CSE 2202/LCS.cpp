#include "bits/stdc++.h"
using namespace std;

int n,m;
string s,r;
vector<vector<int>> dp;
int LCSrec(int i,int j)
{
    if (i >= n or j >= m) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    dp[i][j] = max(LCSrec(i+1,j), LCSrec(i,j+1));
    if (s[i] == r[j])
        dp[i][j] = max(dp[i][j], LCSrec(i+1,j+1) + 1);
    return dp[i][j];
}
int LCSit()
{
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    for (int i = n-1; i >=0; i--)
    {
        for (int j = m-1; j >= 0; j--)
        {
            dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            if (s[i] == r[j])
                dp[i][j] = max(dp[i][j], dp[i+1][j+1]);
        }
    }
    return dp[0][0];
}
int main()
{
    cin >> s >> r;
    n = s.size(), m = r.size();
    dp.resize(n,vector<int>(m,-1));
    cout << LCSrec(0,0) << " " << LCSit() << endl;
}
