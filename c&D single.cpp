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

    // Method to sum ax and bx
    int sum() const {
        return getAx() + bx;
    }

    // Destructor
    ~B() {
        cout << "Destructor of class B called" << endl;
    }
};

int main() {
    // Create an object of class B
    B b(3, 4);

    // Call method to sum ax and bx
    cout << "Sum of ax and bx: " << b.sum() << endl;

    return 0;
}
