//
// Created by roysu on 7/7/2025.
//
#include "bits/stdc++.h"
using namespace std;
void BubbleSort(vector<int> &a)
{
    int n = a.size();
    for (int i = 0;i < n; i++)
    {
        bool swaped = false;
        for (int j = 0;j < n - 1; j++)
            if (a[i] > a[i+1])
                swap(a[i],a[i+1]);
        if (!swaped) break;
    }
}
void InsertionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
void SelectionSort(vector<int> &a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        int min_i = i;
        
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_i])
                min_i = j;
        }
        if (min_i != i)
            swap(a[i], a[min_i]);
    }
}
int main()
{
    vector<int> a = {5,6,7,1,5,7,9,3,8,5,12,78,61,54,78,11,3,46,4,20};
    BubbleSort(a);
    InsertionSort(a);
    SelectionSort(a);
    for (auto i : a) cout << i << " " ;
    cout << endl;
}
