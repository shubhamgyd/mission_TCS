#include <bits/stdc++.h>
using namespace std;

// Class adder
class Adder
{
public:
    // to store num
    int num;
    // Default constructor
    Adder()
    {
        // Initialize num with zero
        num = 0;
    }
    // Parametarize constructor
    // Initialize num with data value
    Adder(int data)
    {
        num = data;
    }
};

int main()
{
    // Object 1(sum1) with initial value =0
    Adder sum1;
    // Object 2(sum2) with intial value = 2
    Adder sum2(2);
    // Display sum1 and sum2
    cout << "sum1 is " << sum1.num << endl;
    cout << "sum2 is " << sum2.num << endl;
    // Add 5 in sum1
    sum1.num += 5;
    // Add -3 in sum2
    sum2.num += -3;
    // Display sum1 and sum2 after modifications
    cout << "After modifications sum1 is " << sum1.num << endl;
    cout << "After modifications sum2 is " << sum2.num << endl;
    // Check both have same value of not
    if (sum1.num == sum2.num)
    {
        cout << "sum1 and sum2 are the same\n";
    }
}