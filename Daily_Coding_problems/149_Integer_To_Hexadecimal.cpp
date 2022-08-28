/*
Given an integer, num, convert it to hexadecimal and return the result.

Ex: Given the following num…

num = 15, return "f".
Ex: Given the following num…

num = 46, return "2e".
*/
#include<bits/stdc++.h>
using namespace std;

// function to convert decimal to hexadecimal
void decToHexa(int n)
{
    // char array to store hexadecimal number
    char hexaDeciNum[100];
 
    // counter for hexadecimal number array
    int i = 0;
    while (n != 0) {
        // temporary variable to store remainder
        int temp = 0;
 
        // storing remainder in temp variable.
        temp = n % 16;
 
        // check if temp < 10
        if (temp < 10) {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else {
            hexaDeciNum[i] = temp + 55;
            i++;
        }
 
        n = n / 16;
    }
 
    // printing hexadecimal number array in reverse order
    for (int j = i - 1; j >= 0; j--)
        cout << hexaDeciNum[j];
}

int main()
{
    int num;
    cin>>num;
    stringstream str;
    str<<hex<<num;
    string res(str.str());
    cout<<res<<endl;

    char hex_string[20];
    sprintf(hex_string, "%X", num); //convert number to hex
    cout << hex_string;
    return 0;
}