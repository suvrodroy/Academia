#include <utility>

#include "bits/stdc++.h"
#include "conio.h"
#include "chrono"
using namespace std;

class OtpGenerator {
public:
    static string generate() {
        return "1234586";
    }
};

enum TransactionType {
    cash_in,
    cash_out,
    send_money,
    bill_payment
};

class Transaction {
private:
    string sender;
    string recipient;
    double amount;
    double senderBalance;
    double receiverBalance;
    TransactionType type;
    time_t transaction_time; // have to use a date time class
public:
    Transaction(const string &sender, const string &recipient, double amount, double senderBalance,
                double receiverBalance, TransactionType type) : sender(sender), recipient(recipient), amount(amount),
                                                                senderBalance(senderBalance),
                                                                receiverBalance(receiverBalance),
                                                                type(type)
    {
        transaction_time = time(nullptr);
    }

    const string &getSender() const {
        return sender;
    }

    const string &getRecipient() const {
        return recipient;
    }

    double getAmount() const {
        return amount;
    }

    double getSenderBalance() const {
        return senderBalance;
    }

    double getReceiverBalance() const {
        return receiverBalance;
    }

    time_t getTransactionTime() const {
        return transaction_time;
    }


};

class History {
private:
    vector<Transaction> transactions;
public:
    void insertTransaction(Transaction transaction) {
        transactions.push_back(transaction);
    }

    vector<Transaction> showTransactionHistory(const string& phone) {
        vector<Transaction> result;
        for (const auto& transaction : transactions) {
            if (transaction.getSender() == phone or transaction.getRecipient() == phone) {
                result.push_back(transaction);
            }
        }
        return result;
    }
};

class MyCash{
private:
    string mobile,name,pin;
    double amount;
    int trans_id = 1;
public:
    MyCash(){
        amount = 0;
    }
    MyCash(string &a,string &b, string &c){
        mobile = a;
        name = b;
        pin = c;
        amount = 0;
    }
    bool match_pin(string input){
        if (input == pin) return true;
        return false;
    }
    bool match_mobile(string input){
        if (input == mobile) return true;
        return false;
    }
    void update_name(string s) {name = s;}
    void update_pin(string s) {pin = s;}
    string get_name(){return name;}
    string get_pin(){return pin;}
    void cash_in(int x) {
        amount += x;
        // history

    }
};

// start here

vector <MyCash> member;
int index;

int find_id(string s){
    int pos = -1;
    for(int i = 0;i < member.size();i++) {
        if (member[i].match_mobile(s)) return pos = i;
    }
    return pos;
}
bool otp_verify(){
    int otp = (rand() + 1000)%10000;
    cout << "Your OTP is: " << otp << endl;
    int input;
    cout << "Enter your 4 digit OTP: ";
    cin >> input;
    if (input == otp) return true;
    return false;
}

void update_me() {

    string s, pin;
    char c;
    cout << "Old Name: " << member[index].get_name() << endl;
    cout << "Enter New Name (press enter to ignore): ";
    cin.ignore();
    getline(cin, s);
    if (s != "\n") member[index].update_name(s);
    cout << "Old PIN: " << member[index].get_pin() << endl;
    cout << "Enter New PIN (press enter to ignore): ";
    getline(cin, s);
    if (s != "\n") {
        cout << "Confirm New PIN: ";
        cin >> pin;
        //
        // have to add PIN mismatch also in regi
        //
        if (otp_verify()) member[index].update_pin(s);
    }
}
void remove_me(){
    if(otp_verify()) member.erase(member.begin() + index);
    cout << "Account removal successful.\n";
    cout << "Press any key to continue...";
    getch();
}
void menu() {
    int option;
    while(true){
        system("cls");
        cout << "********** MyCash Menu ********" << endl;
        cout << "\t1. Update Me" << endl;
        cout << "\t2. Remove Me" << endl;
        cout << "\t3. Send Money" << endl;
        cout << "\t4. Cash-in" << endl;
        cout << "\t5. Cash-out" << endl;
        cout << "\t6. Pay Bill" << endl;
        cout << "\t7. Check Balance" << endl;
        cout << "\t8. History" << endl;
        cout << "\t9. Logout" << endl;
        cout << "\tEnter Your Option (1-9): ";
        cin >> option;
        if (option == 1) {
            update_me();
        }
        else if (option == 2) {
            remove_me();
        }
        else break;
    }

}
void login(){
    string mob;
    cout << "Enter Mobile No. (11-digit): ";
    cin >> mob;
    int pos = find_id(mob);
    if (mob.size() != 11) {
        cout << "Mobile No. must be 11 digits.\n";
        cout << "Press any key to return...";
        getch();
    }
    else if (pos == -1) {
        cout << "An Account does not exist. Please try again...\n";
        cout << "Press any key to return...";
        getch();
    }
    else {
        string pin;
        cout << "Enter PIN: ";
        cin >> pin;
        if(member[pos].match_pin(pin)){
            cout << "Login is successful." << endl
                 << "Press any key to continue to menu...";
            getch();
            index = pos;
            menu();
        }
        else {
            cout << "pin does not match. Login unsuccessful.\n";
            cout << "Press any key to return...";
            getch();
        }
    }
}
void registration(){
    string mob,name,pin,re_pin;
    double amount;
    cout << "Enter Mobile No. (11-digit): ";
    while(cin >> mob){
        if (mob.size() < 11) {
            cout << "Mobile No. must be 11 digits. Please try again...\n";
        }
        else if (find_id(mob) != -1) {
            cout << "An Account already exists. Please try again...\n";
        }
        else {
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter PIN: ";
            cin >> pin;
            while(true){
                cout << "Reconfirm PIN: ";
                cin >> re_pin;
                if (re_pin != pin) {
                    cout << "PIN does not match. Re-enter your PIN: ";
                }
                else break;
            }
            if (!otp_verify()){
                cout << "OTP does not match. Registration unsuccessful.\n";
                return;
            }
            MyCash ob(mob,name,pin);
            member.push_back(ob);
            break;
        }
    }
}
int main(){
    while(true) {
        system("cls");
        cout << "*** MyCash Login**\n"
             << "\t1. Login\n"
             << "\t2. Register\n"
             << "\t3. Exit\n"
             << "\tEnter Your Option:";
        int option;
        cin >> option;
        if (option == 1)
            login();
        else if (option == 2)
            registration();
        else break;
    }
    return 0;
}