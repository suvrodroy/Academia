#include "bits/stdc++.h"
using namespace std;

int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);
    return i + 1;
}
void QuickSort(int a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        QuickSort(a, low, pi - 1);
        QuickSort(a, pi + 1, high);
    }
}
int main()
{
    int n = 5;
    int a[n] = {1,2,3,4,5};
    QuickSort(a,0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;

}
