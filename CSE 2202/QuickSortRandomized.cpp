#include "bits/stdc++.h"
using namespace std;
int callCount = 0;
int itCount = 0;
int partition(int a[], int low, int high)
{

    int pivotIndex = low + rand() % (high - low + 1);
    swap(a[pivotIndex], a[high]);
    
    int pivot = a[high];
    int i = low;

    for (int j = low; j < high; j++) {
        itCount++;
        if (a[j] < pivot) {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[high]);
    return i;
}

void QuickSort(int a[], int low, int high)
{
    callCount++;
    if (low < high) {
        int pi = partition(a, low, high);
        QuickSort(a, low, pi - 1);
        QuickSort(a, pi + 1, high);
    }
}
int main()
{
    int n = 10;
    int a[n] = {1,2,3,4,5,6,7,8,9,10};
    QuickSort(a,0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    cout << callCount << endl;
    cout << itCount << endl;
}
