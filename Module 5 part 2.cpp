#include "bits/stdc++.h"
using namespace  std;
class A{
public:
    void virtual Print(){
        cout<<"Inside Print() of class A"<<endl;
    }
};

class B:public A{
public:
    void Print(){
        cout<<"Inside Print() of class B"<<endl;
    }
};
int main()
{
//    A a;
//    a.Print();

//    B b;
//    b.Print();

//    A a;
//    A *p;
//    p=&a;
//    p->Print();

//    B b;
//    A *p;
//    p=&b;
//    p->Print();

    B b;
    B *p;
    p=&b;
    p->Print();
}