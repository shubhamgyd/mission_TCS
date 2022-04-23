#include<bits/stdc++.h>
using namespace std;

void my_func()
{
	cout<<"H"<<endl;
	my_func();
}

void func()
{
	my_func();
}

int main()
{
	func();
}