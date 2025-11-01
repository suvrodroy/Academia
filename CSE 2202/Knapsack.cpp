#include "bits/stdc++.h"
using namespace std;
int main()
{
    int n,wt = 0;
    cin >> n >> wt;
    vector<pair<double, pair<int,int>>> v(n);
    for (int i = 0;i < n; i++) cin >> v[i].second.first;
    for (int i = 0;i < n; i++) cin >> v[i].second.second;
    for (int i = 0;i < n; i++) v[i].first = v[i].second.first / v[i].second.second;
    sort(v.begin(),v.end(),greater<>());
    double total = 0;
    for (int i = 0;i < n; i++)
    {
        if (v[i].second.second <= wt)
        {
            wt -= v[i].second.second;
            total += v[i].second.first;
        }
        else total += v[i].first * wt,i = n;
    }
    cout << total << endl;
}