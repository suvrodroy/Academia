//
// Created by roysu on 7/7/2025.
//
#include "bits/stdc++.h"
using namespace std;

int binary_search(int x,vector<int> &a)
{
    int n = a.size();
    sort(a.begin(),a.end());
    int low = 0,high = n-1, mid;
    while(low <= mid)
    {
        mid = low + (high - low)/2;
        if (a[mid] == x) {
            return mid;
        }
        else if (x < a[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}
int linear_search(int x,vector<int> &a)
{
    int n = a.size();
    for (int i = 0;i < n; i++)
        if (a[i] == x)
            return i;
    return -1;
}
int main()
{
    vector<int> a = {1,7,9,10,23,33,44};
    cout << binary_search(10,a) << endl;
    cout << linear_search(10,a) << endl;
}
/**
10
5 6 7 1 5 7 9 3 8 5
20
5 6 7 1 5 7 9 3 8 5 12 78 61 54 78 11 3 46 4 20
30
5 6 7 1 5 7 9 3 8 5 12 78 61 54 78 11 3 46 4 20 5 6 7 1 5 7 9 3 8 5
40
5 6 7 1 5 7 9 3 8 5 12 78 61 54 78 11 3 46 4 20 5 6 7 1 5 7 9 3 8 5 12 78 61 54 78 11 3 46 4 20
50
5 6 7 1 5 7 9 3 8 5 12 78 61 54 78 11 3 46 4 20 5 6 7 1 5 7 9 3 8 5 12 78 61 54 78 11 3 46 4 20 5 6 7 1 5 7 9 3 8 5
**/
