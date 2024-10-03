#include <bits/stdc++.h>
#include "conio.h"
using namespace  std;

struct member{
    string id;
    double height;
    double weight;
};
vector<member> v;
int find_id(string s) {
    for(int i = 0; i < v.size(); i++){
        if (v[i].id == s) return i;
    }
    return -1;
}
void update_member() {
    cout << "\n\n *** Updating Member ***\n";
    member new_mem;
    cout<< "Enter member ID: ";cin>>new_mem.id;
    int pos = find_id(new_mem.id);
    while (pos == -1) {
        cout<<"ID does not exist. Re-enter member ID: ";
        cin >> new_mem.id;
        pos = find_id(new_mem.id);
    }
    cout<< "Enter Height(m): ";cin>>new_mem.height;
    cout<< "Enter Weight(kg): ";cin>>new_mem.weight;
    v[pos].height = new_mem.height;
    v[pos].weight = new_mem.weight;
    cout<< "Member updated successfully.\n";
    cout << "Press any key to got to menu ...\n";getch();
}
void add_member() {
    cout << "\n\n *** Adding Member ***\n";
    member new_mem;
    cout<< "Enter member ID: ";cin>>new_mem.id;
    while (find_id(new_mem.id) != -1) {
        cout<<"ID already exist. Re-enter member ID: ";
        cin >> new_mem.id;
    }
    cout<< "Enter Height(m): ";cin>>new_mem.height;
    cout<< "Enter Weight(kg): ";cin>>new_mem.weight;
    v.push_back(new_mem);
    cout << "Member added successfully.\n";
    cout << "Press any key to got to menu ...\n";getch();
}
void remove_member() {
    cout << "\n\n *** Removing Member ***\n";
    member new_mem;
    cout<< "Enter member ID: ";cin>>new_mem.id;
    int pos = find_id(new_mem.id);
    while (pos == -1) {
        cout<<"ID does not exist. Re-enter member ID: ";
        cin >> new_mem.id;
        pos = find_id(new_mem.id);
    }
    v.erase(v.begin() + pos);
    cout << "Member removed successfully.\n";
    cout << "Press any key to got to menu ...\n";getch();
}
void find_max() {
    cout << "\n\n *** Finding Max Height and Weight ***\n";
    double w = 0,h = 0;string id_w, id_h;
    for(int i  = 0; i < v.size();i++) {
        if (v[i].weight > w) {
            w = v[i].weight;
            id_w = v[i].id;
        }
        if (v[i].height > h) {
            h = v[i].height;
            id_h = v[i].id;
        }
    }
    cout << "Max Height is " << h
         << "(m) and it belongs to ID "<< id_h<<".\n";
    cout << "Max Weight is " << w
         << "(w) and it belongs to ID "<< id_w<<".\n";
    cout << "Press any key to got to menu ...\n";getch();
}
void find_min() {
    double w = 1000,h = 1000;string id_w, id_h;
    cout << "\n\n *** Finding Min Height and Weight ***\n";
    for(int i  = 0; i < v.size();i++) {
        if (v[i].weight < w) {
            w = v[i].weight;
            id_w = v[i].id;
        }
        if (v[i].height < h) {
            h = v[i].height;
            id_h = v[i].id;
        }
    }
    cout << "Min Height is " << h
         << "(m) and it belongs to ID "<< id_h<<".\n";
    cout << "Min Weight is "
         << w << "(kg) and it belongs to ID "<< id_w<<".\n";
    cout << "Press any key to got to menu ...\n";getch();
}
void find_average() {
    cout << "\n\n *** Finding Average Height and Weight ***\n";
    double h = 0, w = 0, n = (double)v.size();
    for(int i = 0; i < n; i++) {
        h += v[i].height;
        w += v[i].weight;
    }
    cout << "Average Height is " << h / n <<".\n";
    cout << "Average Weight is " << w / n <<".\n";
    cout << "Press any key to got to menu ...\n";getch();
}
void classify_bmi() {
    cout << "\n\n *** BMI Classification ***\n";
    string id;
    cout<<"Enter member ID: ";cin>>id;
    int pos = find_id (id);
    while (pos == -1) {
        cout<<"ID does not exist. Re-enter member ID: ";
        cin >> id;
        pos = find_id(id);
    }
    double w = v[pos].weight, h = v[pos].height;
    double bmi = w / (h * h);
    cout << "height = " << h << endl;
    cout << "Weight = " << w <<endl;
    cout << "BMI = " << bmi << "\nClassification: ";
    if (bmi < 16) cout << "Severe Thinness\n";
    else if (bmi < 17) cout << "Moderate Thinness\n";
    else if (bmi < 18.5) cout << "Mild Thinness\n";
    else if (bmi < 25) cout << "Normal\n";
    else if (bmi < 30) cout << "Overweight\n";
    else if (bmi < 35) cout << "Obese class I\n";
    else if (bmi < 40) cout << "Obese class II\n";
    else cout << "Obese class III\n";
    cout << "Press any key to got to menu ...\n";getch();
}
int main()
{//system("color f0");
    int op;
    while(true) {
        system("cls");
        cout<< "\n\n  ******** MAIN MENU ********" << endl
            <<"\t1. Add Member" << endl
            <<"\t2. Update Member" << endl
            <<"\t3. Remove Member" << endl
            <<"\t4. Max Height & Weight" << endl
            <<"\t5. Min Height and Weight" << endl
            <<"\t6. Average Height and Weight" << endl
            <<"\t7. BMI Classification" << endl
            <<"\t8. Exit" << endl
            <<"\t\tEnter your option (1-8): ";
        while(cin >> op){
            if (op >= 1 && op <= 8) break;
            cout<<"Invalid command. Try again: ";
        }
        system("cls");
        bool terminate = true;
        switch (op) {
            case 1: add_member();break;
            case 2: update_member();break;
            case 3: remove_member();break;
            case 4: find_max();break;
            case 5: find_min();break;
            case 6: find_average();break;
            case 7: classify_bmi();break;
            case 8: terminate = false;break;
        }
        if (!terminate) break;
    }

    return 0;
}
