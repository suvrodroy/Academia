#include "bits/stdc++.h"
using namespace std;
int main()
{
    double total = 0;
    vector<int> profit = {8, 6, 15, 12, 16};
    vector<int> lifespan = {2, 3, 5, 4, 2};
    int day = 7;
    vector<pair<double,pair<int,int>>> a;
    int n = profit.size();
    for (int i = 0;i < n; i++) {
        a.push_back({(double)profit[i] / lifespan[i], {profit[i], lifespan[i]}});
    }
    sort(a.begin(),a.end(), greater<>());
    for (int i = 0; i < n; i++) {
        if(day <= 0) break;
        int p = a[i].second.first;
        int l = a[i].second.second;
        double ratio = a[i].first;
        int mn = min(day, l);
        day -= mn;
        total += ratio * mn;
    }
    cout << total << endl;
}