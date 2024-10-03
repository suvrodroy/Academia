#include "bits/stdc++.h"
using namespace std;
void print(int n, vector<pair<int,int>> &a)
{
    cout << setw(6) << "LOC:";
    for(int i =0;i < n;i++)
        cout << setw(4) << i;
    cout << endl << setw(6) << "Value:";
    for(int i= 0;i < n;i++)
        cout << setw(4) << a[i].first;
    cout << endl;
}
int binary_search(int x,int n,vector<pair<int,int>> &a)
{
    sort(a.begin(),a.end());
    int low = 0,high = n-1, mid;
    while(low <= mid)
    {
        mid = low + (high - low)/2;
        if (a[mid].first == x) {
            return a[mid].second;
        }
        else if (x < a[mid].first) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}
int main()
{
    time_t start;
    int n;
    cin >> n;
    vector <pair<int,int>> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    start = clock();
    cout << "The array is...\n\n";
    print(n,a);
    int x;
    cout << "Insert Element to search: ";
    cin >> x;
    int loc = binary_search(x,n,a);
    if (loc == -1) cout << "The element is not present in the array\n";
    else cout << "The element " << x << " is present at location " << loc << endl;

    time_t ending = clock();
    double time = double(ending - start)/CLOCKS_PER_SEC;
    cout <<"execution time = " << time << endl;
    cout << system("time") << endl;
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
