#include "bits/stdc++.h"
using namespace std;
int a[100000];
void print(int n)
{
    cout << setw(6) << "LOC:";
    for(int i =0;i < n;i++)
        cout << setw(4) << i;
    cout << endl << setw(6) << "Value:";
    for(int i= 0;i < n;i++)
        cout << setw(4) << a[i];
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) cin >> a[i];
    // starting timer after all inputs are taken
    time_t start = clock();
    cout << "Before sorting ...\n";
    print(n);
    for(int i = 1;i < n;i ++)
    {
        for(int j = i;j > 0; j--)
        {
            if (a[j] < a[j-1]) swap(a[j],a[j-1]);
        }
    }
    cout << "\nAfter sorting ...\n";
    print(n);
    cout << endl;
    time_t ending = clock();
    double time = double(ending - start)/CLOCKS_PER_SEC;
    cout <<"execution time = " << time << endl;
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
