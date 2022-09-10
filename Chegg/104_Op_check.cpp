#include<iostream>
using namespace std;

int func1(int n1);
void func2(int n1,int &n2);

int main()
{
    int x=9;
    int num1,num2;
    num1=1;
    num2=func1(1);
    cout<<"A: ";
    cout<<num1<<" "<<num2<<" "<<x<<endl;
    func2(num1,num2);
    x--;
    cout<<"B: ";
    cout<<num1<<" "<<num2<<" "<<x<<endl;
    return 0;
}

int func1(int n1)
{
    return n1*2;
}

void func2(int n1,int& n2)
{
    int x=1;
    n2=n1*3;
    n1--;
    x--;
    cout<<"C: ";
    cout<<n1<<" "<<n2<<" "<<x<<endl;
}