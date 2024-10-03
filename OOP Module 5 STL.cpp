#include "bits/stdc++.h"
using namespace std;
int display(list<int> &l) {
    for(auto i : l) cout << i << " ";
    cout << endl;
}
int rev_display(list<int> &l) {
    for(auto it = l.rbegin(); it != l.rend(); ++ it)
        cout << *it << " ";
    cout << endl;
}
void solve(){
    array<int,6> a;
    a = {10,60,30,70,20};
    cout << a.at(3) << endl;
    cout << a.front() << endl;
    cout << a.back() << endl;
    a.fill(11);
    if  (a.empty()) cout << "array is empty\n";
    else cout << "array is not empty\n";
    cout << (int)a.size() << endl;
    cout << (int)a.max_size() << endl;
    cout << a.begin() << endl;
    cout << a.end() << endl;

    pair<int,string> pi;
    pi = make_pair(10,"Rajshahi");
    cout << pi.first << " " << pi.second << endl;
    get<0>(pi) = 20;
    cout << pi.first << " " << pi.second << endl;
    pair<int,string> bi = make_pair(12,"Natore");
    swap(pi,bi);

    tuple<int,string,double> tx = make_tuple(100, "Kamal", 3.5);
    cout << get<0>(tx) << endl;
    cout << get<1>(tx) << endl;
    get<2>(tx) = 3.7;
    cout << get<2>(tx) << endl;
    tuple<int,string,double> bx = make_tuple(1,"string",3.9);
    swap(tx,bx);

    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    if(s.empty())
        cout<<"Stack is empty"<<endl;
    else
        cout<<"Stack is not empty"<<endl;

    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    if(q.empty())
        cout<<"Queue is empty"<<endl;
    else
        cout<<"Queue is not empty"<<endl;

    list<int> l;
    for(int i = 2; i < 10;i++) l.push_back(i);
    l.push_front(1),l.push_front(0);
    display(l);
    rev_display(l);
    cout << l.front() << endl;
    cout << l.back() << endl;
    l.pop_back();
    l.pop_front();
    cout <<"pos " << *find(l.begin(),l.end(),5) << endl;
    l.insert(find(l.begin(),l.end(),5) , 99);
    display(l);
    l.insert(prev(find(l.begin(),l.end(),5) ), 99);
    count(l.begin(), l.end(),99);
    l.erase(find(l.begin(),l.end(),5));
    auto it = l.begin();
    for(auto i = 0; i < 4; i++) ++it;
    l.erase(l.begin(),it);
    l.remove(99);
//    remove_if(l.begin(),l.end(),5);
    l.sort();

}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_n = 1;
    cin>>test_n;
    for(int t_c = 1;t_c <= test_n;t_c ++){
        solve();
    }
    return 0;
}