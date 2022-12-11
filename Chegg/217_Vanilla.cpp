#include <iostream>
using namespace std;

int main()
{
    // input
    while (true)
    {
        // Read vanilla array in the form of string
        string str;
        cout << "Enter array as a string or Empty string to exit: ";
        getline(cin, str);
        // If empty string is entered
        if (str.length() == 0)
        {
            break;
        }
        // If first and last char is not same just for checking the entered string is array or not
        if (str[0] != '{' || str[str.length() - 1] != '}')
        {

            cout << "The string does not contains a valid or a vanilla array\n";
            continue;
        }
        // Keep track on entered array is vanilla array or not
        bool isVanillaNumber = true;
        // Get first char
        char startingChar = str[1];
        // Start from 1st index
        int i = 1;
        // Iterate string
        while (i < str.length())
        {
            // Iterate particular number
            int j = i;
            // Check number have same char or not as i.e. startingChar must be same with the jth char
            // if not then mark the entered array is not valid vanilla array
            while (j < str.length() and (str[j] != ',' and str[j] != '}'))
            {
                if (str[j] != startingChar)
                {
                    isVanillaNumber = false;
                    break;
                }
                j++;
            }
            // check next number
            i = j + 1;
            // If not valid vanilla number
            // display  error and continue for next input
            if (!isVanillaNumber)
            {
                cout << "The string does not contains a valid or a vanilla array\n";
                break;
            }
        }
        // If entered array is valid vanilla array, then display the message
        // and continue with next input
        if (isVanillaNumber)
        {
            cout << "The string contains a valid vanilla array\n";
        }
    }
}