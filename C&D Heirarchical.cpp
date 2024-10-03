#include "bits/stdc++.h"
using namespace std;

class A {
private:
    int ax;
public:
    // Constructor to initialize ax
    A(int x) : ax(x) {
        cout << "Constructor of class A called, ax = " << ax << endl;
    }

    // Destructor
    ~A() {
        cout << "Destructor of class A called" << endl;
    }

    // Getter for ax
    int getAx() const {
        return ax;
    }
};

class B : public A {
private:
    int bx;
public:
    // Constructor to initialize bx
    B(int x, int y) : A(x), bx(y) {
        cout << "Constructor of class B called, bx = " << bx << endl;
    }

    // Destructor
    ~B() {
        cout << "Destructor of class B called" << endl;
    }

    // Getter for bx
    int getBx() const {
        return bx;
    }
};

class C : public A {
private:
    int cx;
public:
    // Constructor to initialize cx
    C(int x, int z) : A(x), cx(z) {
        cout << "Constructor of class C called, cx = " << cx << endl;
    }

    // Method to sum ax and cx
    int sum() const {
        return getAx() + cx;
    }

    // Destructor
    ~C() {
        cout << "Destructor of class C called" << endl;
    }
};

int main() {
    // Creating objects of class B and C
    cout << "Creating object of class B:" << endl;
    B b(1, 2);

    cout << "Creating object of class C:" << endl;
    C c(3, 4);

    // Calling methods of class B and C
    cout << "Sum of ax and cx: " << c.sum() << endl;

    return 0;
}
