#include <bits/stdc++.h>
using namespace std;
class myExcepetion : public std::exception{
private:
    const char* err;
public :
    myExcepetion(const char* s) : exception() {};
};
int main()
{
    int i;
    int ax[5]={10,20,60,40,30};
    cout<<"enter index:";
    cin>>i;
    try{
        if (i > 5) {
            throw myExcepetion("out of reach");
        }
        if (i <= 5 and i>0) throw i;
    }
    catch(int i) {
        cout<<"ax["<<i<<"]= "<<ax[i-1]<<endl;
    }
    catch(myExcepetion &s) {
        cout << "out of reach" << endl;
    }
    catch(...) {
        cout << "invalid index\n";
    }

}