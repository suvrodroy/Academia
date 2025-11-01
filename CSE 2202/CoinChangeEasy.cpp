#include "bits/stdc++.h"
using namespace std;
int main()
{
    vector<int> coins = {1000,500,100,50,20,10,5,2,1};
    sort(coins.begin(),coins.end(),greater<>());
    int amount;
    cin >> amount;
    int total = 0;
    for (auto i : coins)
    {
        if (amount <= 0) break;
        if (amount >= i)
        {
            int c = amount / i;
            amount -= i * c;
            total += c;
        }
    }
    cout << total << endl;
}