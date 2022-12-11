#include <iostream>
using namespace std;

// Utility function prints the characters by traversing into the string
void printChars(string str)
{
    // Iterate string
    for (int i = 0; i < str.length(); i++)
    {
        // If current character is not space
        if (str[i] != ' ')
        {
            // Print the ith character
            cout << str[i] << endl;
        }
    }
}

int main()
{
    // Input of string
    string str;
    // Read string
    getline(cin, str);
    // Function call to print characters of a given string
    printChars(str);
    return 0;
}