#include <iostream>
#include <iomanip>
using namespace std;

// Function to get the binary representation of a given number
string binary(int n)
{
    // get binary string
    string binaryString = "";
    while (n)
    {
        if (n & 1)
        {
            binaryString += '1';
        }
        else
        {
            binaryString += '0';
        }
        n >>= 1;
    }
    if (binaryString.empty())
        return "0";
    return binaryString;
}

int main()
{
    // For loop to print decimal and binary representation of a current number
    for (int i = 0; i <= 25; i++)
    {
        string binExp = binary(i);
        cout << i << " \t" << binExp << endl;
    }
    return 0;
}