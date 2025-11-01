//
// Created by roysu on 7/7/2025.
//
#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef long double ld;

void Merge(int *a, int low, int high, int mid,int n);
void MergeSort(int *a,int low, int high, int n);
int callCount = 0;
int main()
{
    int n = 10;
    int a[n] = {3,1,0,9,5,2,4,10,7,6};
    MergeSort(a,0,n-1,n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    cout << callCount << endl;
}
void merge(int *a, int low, int high, int mid,int n)
{
    //cout<<"im at merge\n";
    int c[n];
    int i,j,k;
    i = low;
    k = low;
    j = mid+1;
    while(i<=mid && j <=high){
        if (a[i]<a[j]){
            c[k] = a[i];
            k++;
            i++;
        }
        else{
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while(i<=mid){
        c[k] = a[i];
        k++;
        i++;
    }
    while(j<=high){
        c[k] = a[j];
        j++;
        k++;
    }
    for(i = low;i < k;i++)
        a[i] = c[i];
}
void MergeSort(int *a,int low, int high, int n)
{
    callCount++;
    //cout<<"im at MergeSort\n";
    int mid = low + (high-low)/2;
    if (low<high){
        MergeSort(a,low,mid,n);
        MergeSort(a,mid+1,high,n);
        merge(a,low,high,mid,n);
    }
}