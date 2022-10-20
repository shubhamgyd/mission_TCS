#include <iostream>
using namespace std;

class myInt
{
    int num;

public:
    myInt(int number)
    {
        this->num = number;
    }
    void isMultiple();
    void sumOfDigits();
    void squareRoot();
    void isPrime();
    void isPerfectSquare();
};

void myInt::isMultiple()
{
    bool isMultipleOfSeven = false;
    bool isMultipleOfEleven = false;
    bool isMultipleOfThirteen = false;
    if (num % 7 == 0)
        isMultipleOfSeven = true;
    if (num % 11 == 0)
        isMultipleOfEleven = true;
    if (num % 13 == 0)
        isMultipleOfThirteen = true;

    cout << num;
    if (isMultipleOfSeven)
    {
        cout << " is multiple of 7, ";
    }
    else
    {
        cout << "not multiple of 7, ";
    }
    if (isMultipleOfEleven)
    {
        cout << " is multiple of 11, ";
    }
    else
    {
        cout << "not multiple of 11, ";
    }
    if (isMultipleOfThirteen)
    {
        cout << " is multiple of 13, ";
    }
    else
    {
        cout << "not multiple of 13, ";
    }
}

void myInt::sumOfDigits()
{
    int sum = 0;
    int temp = num;
    while (temp)
    {
        sum += temp % 10;
        temp /= 10;
    }
    if (sum % 2 == 0)
    {
        cout << "Sum of its digits is even" << endl;
    }
    else
    {
        cout << "Sum of its digits is odd" << endl;
    }
}