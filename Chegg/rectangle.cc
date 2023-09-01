#include <bits/stdc++.h>
using namespace std;

class A
{
public:
    A()
    {
        cout << "A";
    }
    ~A()
    {
        cout << "!A";
    }
};

class B : public A
{
public:
    B()
    {
        cout << "B";
    }
    ~B()
    {
        cout << "!B";
    }
};

int main()
{
    A *obj = new B();
    delete obj;
    return 0;
}