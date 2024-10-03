
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
    static void display_n() {
        cout <<"n = " << n << endl;
    }
    static void display() {
        cout << "id = " << id << endl;
        cout << "amount = " << amount << endl;
        cout << "n = " << n << endl;
    }
    static void display_total_balance() {
        cout << "Total amount of the bank is " << total_amount <<endl;
    }
};

int Bank::n = 0;
float Bank::total_amount = 0;

signed main() {

    Bank  b(2203142,100.00), c(b),info;
    b.display();
    c.change_amount(1234.00);
    c.display();
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
    Bank::display_n();
    cout << endl;
    for(int i = 0; i < 5; i++) {
        acc[i].display();
    }
    cout << endl;
    Bank::display_total_balance();

    return 0;
}
/*
133
4033
134
4034
135
4035
136
4036
137
4037
*/
