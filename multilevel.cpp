#include "bits/stdc++.h"
using namespace std;
class A{
private:
    int x;
protected:
    int y;
public:
    int z;
    string p = "im at A";
    A(){x = 2,y = 5, z = 11;}
    void print_a(){
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
        cout << "z = " << z << endl;
    }
};
class B:public A{
public:
    string q = "im at B";
    void print_b(){
        cout << q << endl;
    }
};
class C:public B{
public:
    void confirm(){
        cout << p << endl;
        cout << q << endl;
    }
};
int main(){
    A a;
    // initializing a
    B b;
    cout << "printing A to confirm inheritance to B\n";
    b.print_a();
    cout << "confirming inheritance of C\n";
    C c;
    c.confirm();
    return 0;
}