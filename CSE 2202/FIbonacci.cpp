#include "bits/stdc++.h"
using namespace std;

int n = 10000;
int dp[10001];
int f(int i)
{
    if (i <= 0)
        return 0;
    if (i == 1) return dp[i] = 0;
    if (i == 2) return dp[i] = 1;
    if (dp[i] != -1) return dp[i];
    return dp[i] = f(i-1) + f(i-2);
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int fib[n+1];
    fib[1] = 0, fib[2] = 1;
    for (int i = 3; i <= n; i++)
        fib[i] = fib[i-1] + fib[i-2];
    int x = 17;
    f(n);
    cout << x << " th fibonacci is " << fib[x] << " | " << dp[x] << endl;
}
