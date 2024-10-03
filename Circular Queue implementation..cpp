#include "bits/stdc++.h"
using namespace std;
const int N = 5;
int q[N],Front = -1, Rear = -1;
void enqueue(int x) {
    if (Front == Rear and Front == -1) {
        Front = Rear = 0;
        q[Front] = x;
        return;
    }
    int new_Rear = (Rear+1)%N;
    if(new_Rear == Front) {
        cout << "queue is full. Cannot enqueue\n";
        return;
    }
    Rear = new_Rear;
    q[new_Rear] = x;
}
void dequeue() {
    if (Front == Rear ) {
        if (Front == -1)
            cout << "queue is empty. cannot dequeue\n";
        else {
            cout << "dequeue element " << q[Front] <<endl;
            Front = Rear = -1;
        }
        return;
    }
    cout << "dequeue element " << q[Front] <<endl;
    Front = (Front + 1) % N;
}
void print_queue () {
    cout << "Printing queue: \n";
    for(int i = Front; i != Rear; i = (i + 1) % N)
        cout << q[i] << " " ;
    cout <<q[Rear] << endl;
}
int main() {
    int type, value;
    while(cin >> type) {
        if (type == 1) print_queue();
        else if (type == 2)
            cout << "Front element = " << q[Front] << endl;
        else if (type == 3) {
            cout << "Insert Element: ";
            int x; cin >> x;
            enqueue(x);
        }
        else dequeue();
    }
}