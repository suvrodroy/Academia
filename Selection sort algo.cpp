#include "bits/stdc++.h"
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0;i < n; i++) cin >> a[i];
    for(int j=0;j<n-1;j++){
        int k=j;
        for(int i=j+1;i<n;i++)
            if(a[i]<a[k])
                k=i;
        swap(a[k] , a[j]);
    }
    cout << "The sorted array: ";
    for(int i=0;i<n;i++)
        cout << a[i] << " ";
    cout << endl;
    cout << "Printing all odds: ";
    for(int i =0;i < n; i++) {
        if (a[i]&1) cout << a[i] << " ";
    }
    cout << endl << "Printing all evens: ";
    for(int i = 0;i < n; i++) {
        if (!(a[i]&1)) cout << a[i] << " ";
    }
    cout << endl;
}