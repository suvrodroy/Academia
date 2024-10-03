#include "bits/stdc++.h"
using namespace std;
class Bank{
private:
    int id;
    float amount;
    static int n;
    static float total_amount;
public:

    Bank(){
        id = 0;
        amount = 0;
        n++;
    }
    Bank(int i,float am) {
        id = i;
        amount = am;
        n++;
        total_amount += amount;
    }
    Bank(Bank &cpy){
        id = cpy.id;
        amount = cpy.amount;
        total_amount += amount;
        n++;
    }
    void set_value(int i, float am) {
        id = i;
        amount = am;
        total_amount += amount;
    }
    void change_amount(float am) {
        total_amount -= amount;
        amount = am;
        total_amount += amount;
    }
    void display_n() {
        cout <<"n = " << n << endl;
    }
    void display() {
        cout << "id = " << id << endl;
        cout << "amount = " << amount << endl;
        cout << "n = " << n << endl;
    }
    void display_total_balance() {
        cout << "Total amount of the bank is " << total_amount <<endl;
    }
};

int Bank::n = 0;
float Bank::total_amount = 0;

signed main() {

    //info.display_total_balance();
    Bank  a,b(2203142,100.00), c(b),info;
    cout << endl;
    cout << "Default constructor initialization of 'a'\n";
    a.display();
    cout << "\nParameterized constructor initialization of 'b'\n\n";
    b.display();
    cout << "\nCopy constructor initialization of 'c'(copied from 'b')\n";
    c.display();
    //cout << "\n";
    //info.display_total_balance();

    cout << "\nChanging amount of 'c'\n";
    c.change_amount(1234.0);
    c.display();

    info.display_total_balance(); cout << endl;
    Bank acc[5];
    for(int i = 0; i < 5;i++) {
        int id;
        float amount;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter amount = ";
        cin >> amount;
        acc[i].set_value(id,amount);
    }
    cout << endl;
    info.display_n();
    cout << endl;
    for(int i = 0; i < 5; i++) {
        acc[i].display();
    }
    cout << endl;
    info.display_total_balance();

    return 0;
}
/**
142
2230
143
5530
144
3101
145
6690
146
1500
**/
