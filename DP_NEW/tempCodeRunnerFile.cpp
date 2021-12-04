#include<bits/stdc++.h>
using namespace std;

void trick (int *temp1, int *temp2)
{
int *temp=temp1;

temp1=temp2;

temp2=temp;

}

int main() {

int a=100;

int b=200;

int c=300;

trick (&a, &b);

trick (&a, &c);

cout<<b;
}