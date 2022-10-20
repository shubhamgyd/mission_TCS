#include <bits/stdc++.h>
using namespace std;

int main()
{
    // int_fast64_t x=9;
    double x = pow(9, 10);
    double x_2 = x * x;
    double num = x * x + 17;
    double num1 = sqrt(num);
    double num2 = num1 * x;
    cout << x << endl;
    cout << x_2 << endl;
    cout << num << endl;
    cout << num1 << endl;
    cout << num2 << endl;
    cout << fixed << setprecision(6) << num2 - x_2 << endl;
}