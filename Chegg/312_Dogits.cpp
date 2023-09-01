#include <iostream>
using namespace std;

int main()
{
    // Input of string
    string str;
    cin >> str;
    // Iterate string and check each character
    for (int i = 0; i < str.length(); i++)
    {
        // if ith char is greater than equal to 0 and less than equal to 9
        if (str[i] >= '0' and str[i] <= '9')
        {
            continue;
        }
        // else print no and end the program
        else
        {
            cout << "no\n";
            return 0;
        }
    }
    // if valid string then print the yes
    cout << "yes\n";
    return 0;
}