#include "bits/stdc++.h"
using namespace std;
class A{
private:
    int x = 20;
protected:
    int y = 70;
public:
    int z = 170;
    A(){x = 2, y = 7, z= 17;}
    int get_x(){return x;}
    int get_y(){return y;}
    int get_z(){return z;}
};
class B: public A{
public:
    void confirm(){
        cout << "direct access of private and public members of A\n";
        cout << "y = " << y << " ";
        cout << "z = " << z << endl;
        cout << " printing private member through inherited method\n";
        cout << "x = " << get_x() << endl;
    }
    int get_x_from_B(){return get_x();}
    int get_y_from_B(){return get_y();}
    int get_z_from_B(){return get_z();}
};
class C: public A{
public:
    void confirm(){
        cout << "direct access of private and public members of A\n";
        cout << "y = " << y << " ";
        cout << "z = " << z << endl;
        cout << " printing private member through inherited method\n";
        cout << "x = " << get_x() << endl;
    }
    int get_x_from_C(){return get_x();}
    int get_y_from_C(){return get_y();}
    int get_z_from_C(){return get_z();}
};
class D: public B, public C{
public:
    void can_i_access_A(){
//        cout << get_x() << endl;
//        cout << get_y() << endl;
//        cout << get_z() << endl;
        cout << "Cannot access A\n";
    }
};
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    A a;
    B b;
    C c;
    cout << "confirming inheritance of B\n";
    b.confirm();
    cout << "confirming inheritance of C\n";
    c.confirm();
    D d;
    cout << "\nTrying to access superclass A\n";
    d.can_i_access_A();
    cout << "\naccessing A through B\n";
    cout << "x = " << d.get_x_from_B() << " ";
    cout << "y = " << d.get_y_from_B() << " ";
    cout << "z = " << d.get_z_from_B() << endl;
    cout << "\naccessing A through C\n";
    cout << "x = " << d.get_x_from_B();
    cout << "y = " << d.get_y_from_B();
    cout << "z = " << d.get_z_from_B();

    cout << endl;
    return 0;
}
// using virtual class
/*
#include "bits/stdc++.h"
using namespace std;
class A{
private:
    int x = 20;
protected:
    int y = 70;
public:
    int z = 170;
    A(){x = 2, y = 7, z= 17;}
    int get_x(){return x;}
    int get_y(){return y;}
    int get_z(){return z;}
};
class B: virtual public A{
public:
    void confirm(){
        cout << "direct access of private and public members of A\n";
        cout << "y = " << y << " ";
        cout << "z = " << z << endl;
        cout << " printing private member through inherited method\n";
        cout << "x = " << get_x() << endl;
    }
};
class C: virtual public A{
public:
    void confirm(){
        cout << "direct access of private and public members of A\n";
        cout << "y = " << y << " ";
        cout << "z = " << z << endl;
        cout << " printing private member through inherited method\n";
        cout << "x = " << get_x() << endl;
    }
};
class D: public B, public C{
public:
    void can_i_access_A(){
        cout << get_x() << endl;
        cout << get_y() << endl;
        cout << get_z() << endl;
        cout << "A is accessible when using virtual class\n";
    }
};
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    A a;
    B b;
    C c;
    cout << "confirming inheritance of B\n";
    b.confirm();
    cout << "confirming inheritance of C\n";
    c.confirm();
    D d;
    cout << "\nTrying to access superclass A\n";
    d.can_i_access_A();

    cout << endl;
    return 0;
}*/
