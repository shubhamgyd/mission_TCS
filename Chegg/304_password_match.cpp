#include <iostream>
using namespace std;

int main()
{
    // User Input of passwords
    string password, rePassword;
    cout << "Enter password: ";
    cin >> password;
    cout << "Re-Enter password: ";
    cin >> rePassword;
    // Compare both strings
    // IF both passwords matched
    if (password == rePassword)
    {
        cout << "passwords matched!" << endl;
    }
    else
    {
        cout << "passwords do not matched!" << endl;
    }
    return 0;
}