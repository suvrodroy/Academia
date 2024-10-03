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

class B {
private:
    int bx;
public:
    // Constructor to initialize bx
    B(int y) : bx(y) {
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

class C : public A, public B {
private:
    int cx;
public:
    // Constructor to initialize cx
    C(int x, int y, int z) : A(x), B(y), cx(z) {
        cout << "Constructor of class C called, cx = " << cx << endl;
    }

    // Method to sum ax, bx, and cx
    int sum() const {
        return getAx() + getBx() + cx;
    }

    // Destructor
    ~C() {
        cout << "Destructor of class C called" << endl;
    }
};

int main() {
    // Create an object of class C
    C c(1, 2, 3);

    // Call method to sum ax, bx, and cx
    cout << "Sum of ax, bx, and cx: " << c.sum() << endl;

    return 0;
}
