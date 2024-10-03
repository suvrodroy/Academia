#include "bits/stdc++.h"
using namespace  std;
class A{
private:
    int x = 3;
protected:
    int y = 5;
public:
    int z = 7;
    int get_x(){ return x;}
    int get_y(){return y;}
    int get_z(){return z;}
};
class B : public A{
public:
    void show_inheritance(){
        cout << "Direct Access\n";
//        cout << "accessing x = " << x << endl;
        cout << "accessing y = " << y << endl;
        cout << "accessing z = " << z << endl;
        cout <<"Using methods\n";
        cout << "accessing x = " << get_x() << endl;
        cout << "accessing y = " << get_y() << endl;
        cout << "accessing z = " << get_z() << endl;
    }
};
class C : protected A{
public:
    void show_inheritance(){
        cout << "Direct Access\n";
//        cout << "accessing x = " << x << endl;
        cout << "accessing y = " << y << endl;
        cout << "accessing z = " << z << endl;
        cout <<"Using methods\n";
        cout << "accessing x = " << get_x() << endl;
        cout << "accessing y = " << get_y() << endl;
        cout << "accessing z = " << get_z() << endl;
    }
};
class D : private A{
public:
    void show_inheritance(){
        cout << "Direct Access\n";
//        cout << "accessing x = " << x << endl;
        cout << "accessing y = " << y << endl;
        cout << "accessing z = " << z << endl;
        cout <<"Using methods\n";
        cout << "accessing x = " << get_x() << endl;
        cout << "accessing y = " << get_y() << endl;
        cout << "accessing z = " << get_z() << endl;
    }
};
int main(){
    B b;
    C c;
    D d;
    cout << "Accessing members of B\n";
//    cout << b.x << endl;
//    cout << b.y << endl;
    cout << b.z << endl;
    cout << "Inheritance of A in B\n";
    b.show_inheritance();
    //
    cout << "Accessing members of C\n";
//    cout << c.x << endl;
//    cout << c.y << endl;
//    cout << c.z << endl;
    cout << "Inheritance of A in C\n";
    b.show_inheritance();
    //
    cout << "Accessing members of D\n";
//    cout << d.x << endl;
//    cout << d.y << endl;
//    cout << d.z << endl;
    cout << "Inheritance of A in D\n";
    b.show_inheritance();
}
