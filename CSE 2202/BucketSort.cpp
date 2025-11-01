#include "bits/stdc++.h"
using namespace std;
void bucketSort(vector<float>& arr)
{
    int n = arr.size();
    vector<vector<float>> buckets(n);

    for (int i = 0; i < n; i++)
    {
        int idx = n * arr[i];
        buckets[idx].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++)
        sort(buckets[i].begin(), buckets[i].end());

    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (float val : buckets[i])
            arr[k++] = val;
    }
}
int main()
{
    vector<float> arr = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    bucketSort(arr);
    for (float x : arr)
        cout << x << " ";
    cout << endl;
}
