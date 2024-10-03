#include "bits/stdc++.h"
using namespace  std;
class Father{
private:
    int money;
protected:
    int gold;
public:
    int land;
    void show_f(){
        cout << "Father's money = " << money << endl;
        cout << "Father's gold = " << gold << endl;
        cout << "Father's land = " << land << endl;
    }
};
class Son:public Father{
public:
    void show_s(){
        show_f();
        cout << "Son's inheritance of money = " << money << endl;
        cout << "Son's inheritance of gold = " << gold << endl;
        cout << "Son's inheritance of land = " << land << endl;
    }
};
class Grandson:public Son{
public:
    void show_g(){
        show_f();
        show_s();
        cout << "Grandson's inheritance of money = " << money << endl;
        cout << "Grandson's inheritance of gold = " << gold << endl;
        cout << "Grandson's inheritance of land = " << land << endl;
    }
};
int main(){

}