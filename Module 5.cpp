#include "bits/stdc++.h"
using namespace  std;
class Test{
private:
public:
    int sum(int a) { return a; }
    int sum(int a,int b) { return a + b; }
    double sum(double a,int b) { return double(b) + a; }
    double sum(int a,double b) { return double(a) + b; }
    double sum(double a,double b) { return b + a ;}
};
class Circuit{
private:
    double real;
    double img;
public:
    Circuit(){real = 0, img = 0;}
    Circuit(double a,double b){real = a, img = b;}
    Circuit operator + (const Circuit &other) const{
        return {real + other.real, img + other.img};
    }
    Circuit operator - (const Circuit &other) const{
        return {real - other.real, img - other.img};
    }
    Circuit operator * (const Circuit &other) const{
        return {real * other.real - img*other.img, real*other.img + img*other.real};
    }
    Circuit operator / (const Circuit &other) const{
        double denom = other.real * other.real + other.img * other.img;
        return {(real * other.real - img*other.img) / denom, (real*other.img + img*other.real) / denom};
    }
    void distplay(){
        cout << real << " ";
        if (img < 0) cout << "- j";
        else cout << "+ j";
        cout << abs(img) << endl;
    }
};
int main()
{
    // testing class "Test"
    /*Test t;
    cout << t.sum(10) << endl;
    cout << t.sum(10,20) << endl;
    cout << t.sum(5.7,20) << endl;
    cout << t.sum(10,2.6) << endl;
    cout << t.sum(10.5,20.7) << endl;*/

    Circuit I,z1(3,4),z2(4,3),z3(0,6),V(100,50);
    Circuit Z = (z1*z2)/(z1+z2);
    Z = (Z * z3) / (Z + z3);
    I = V / Z;
    cout << "Current I = ";
    I.distplay();
    cout << endl;
}