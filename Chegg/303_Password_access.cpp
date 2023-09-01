#include <iostream>
using namespace std;

int main()
{
    string password;
    int age;
    // User Input
    cout << "Enter password: ";
    cin >> password;
    cout << "Enter Age: ";
    cin >> age;
    // if length of password is at least 10 and age is at least 12
    if (password.length() >= 010 and age >= 12)
    {
        cout << "Access granted!" << endl;
    }
    // if password length is less than 10 but age is at least 12
    else if (password.length() < 10 and age >= 12)
    {
        cout << "Password too short, access denied!" << endl;
    }
    // if age is less than 12 but password is at least 12
    else if (password.length() >= 10 and age < 12)
    {
        cout << "User too young, access denied" << endl;
    }
    // else
    else
    {
        cout << "Access denied" << endl;
    }
    return 0;
}