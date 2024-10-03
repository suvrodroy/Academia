#include<iostream>
using namespace std;

class A
{
private:
    int x=10;
protected:
    int y=30;
public:
    int z=90;
    int getX()
    {
        return x;
    }
};

class B
{
private:
    int p=20;
protected:
    int q=45;
public:
    int r=70;
    int getP()
    {
        return p;
    }

};

class C:public A,public B
{
public:

    int getY()
    {
        return y;
    }
    int getQ()
    {
        return q;
    }
    void show()
    {
        cout<<getX()<<endl;
        cout<<getY()<<endl;
        cout<<z<<endl;
        cout<<getP()<<endl;
        cout<<getQ()<<endl;
        cout<<z<<endl;
    }
};

int main()
{
    C c;
    c.show();
}
