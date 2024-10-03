
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
    cout << "The array is...\n\n";
    print(n);
    int x;
    cout << "Insert Element to search: ";
    cin >> x;
    // starting timer after all inputs are taken
    time_t start = clock();

    int loc = -1;
    for(int i = 0;i < n;i++)
        if (a[i] == x){
            loc = i;
            break;
        }
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
