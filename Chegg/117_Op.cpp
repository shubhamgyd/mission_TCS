#include <iostream>
using namespace std;

// Here a anc c are passed by reference
// means if we update the value of a then it
// will automatic reflect in c
// i.e. here a is passed by reference and c is passed
// by pointer anyone will update both the values
int One(int &a, int b, int *c)
{
    // a=2,b=2,c=2

    // Step 1:
    // a=2+2+2=6
    // Now, a=6,b=2,c=6
    // because both a and c referring to same memory location
    a = a + b + *c;

    // Step 2:
    // b=6+2+6=14
    // Now, a=6,b=14,c=6
    b = a + b + *c;

    // Step 3:
    // c=6+14+6=26
    // Now, a=26,b=14,c=26
    // because both a and c referring to same memory location
    *c = a + b + *c;
    cout << "In One: " << a << " " << b << " " << *c << endl;
    return a + b + *c;
}

int main()
{
    int num = 2;
    // Here we have passed arguments by referrence,by value, by pointer respectively
    // so value in main will get updated after the execution of function
    cout << "In main: " << One(num, num, &num) << endl;
    // Updated num value=26
    cout << "Num= " << num << endl;
    return 0;
}