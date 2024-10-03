#include <iostream>
using namespace std;

class MyClass {
private:
    int x;
public:
    MyClass() : x(0) {} // Constructor to initialize x to 0

    // Friend functions declarations
    friend void Add(MyClass &obj, int value);
    friend void IncX(MyClass &obj, int m);
    friend void DecX(MyClass &obj, int n);
    void display() const {
        cout << "x = " << x << endl;
    }
};
void Add(MyClass &obj, int value) {
    obj.x = value;
}
void IncX(MyClass &obj, int m) {
    obj.x += m;
}
void DecX(MyClass &obj, int n) {
    obj.x -= n;
}

int main() {
    MyClass obj;

    Add(obj, 10);
    obj.display(); // Should display x = 10

    IncX(obj, 5);
    obj.display(); // Should display x = 15

    DecX(obj, 3);
    obj.display(); // Should display x = 12

    return 0;
}
