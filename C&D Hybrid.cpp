#include "bits/stdc++.h"
using namespace std;

class A {
public:
    int ax;
    // Constructor to initialize ax
    A(int x) : ax(x) {
        cout << "Constructor of class A called, ax = " << ax << endl;
    }

    // Destructor
    ~A() {
        cout << "Destructor of class A called" << endl;
    }
};

class B : virtual public A {
public:
    int bx;
    // Constructor to initialize bx and ax (inherited from A)
    B(int x, int y) : A(x), bx(y) {
        cout << "Constructor of class B called, bx = " << bx << endl;
    }

    // Destructor
    ~B() {
        cout << "Destructor of class B called" << endl;
    }
};

class C : virtual public A {
public:
    int cx;
    // Constructor to initialize cx and ax (inherited from A)
    C(int x, int z) : A(x), cx(z) {
        cout << "Constructor of class C called, cx = " << cx << endl;
    }

    // Destructor
    ~C() {
        cout << "Destructor of class C called" << endl;
    }
};

class D : public B, public C {
public:
    int dx;
    // Constructor to initialize dx, bx, cx, and ax (inherited from B and C)
    D(int x, int y, int z, int w) : A(x), B(x, y), C(x, z), dx(w) {
        cout << "Constructor of class D called, dx = " << dx << endl;
    }

    // Method to sum ax, bx, cx, and dx
    int sum() const {
        return ax + bx + cx + dx;
    }

    // Destructor
    ~D() {
        cout << "Destructor of class D called" << endl;
    }
};

int main() {
    // Create an object of class D
    D d(1, 2, 3, 4);

    // Call method to sum ax, bx, cx, and dx
    cout << "Sum of ax, bx, cx, and dx: " << d.sum() << endl;

    return 0;
}