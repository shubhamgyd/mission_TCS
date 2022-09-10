// #include <iostream>
// using namespace std;

// // Utility finction which finds the nth finonacci number
// int fibb(int n)
// {
//     // base case
//     // if n is less than or equal to 1
//     if (n <= 1)
//     {
//         cout << "Changed value of n: " << n << endl;
//         return n;
//     }
//     // else add the previous and the previous of previous term
//     cout << "Changed value of n: " << n << endl;
//     return fibb(n - 1) + fibb(n - 2);
// }

// int main()
// {
//     // Input number
//     cout << "Enter Number: ";
//     int n;
//     cin >> n;
//     // function call to find the nth fibonacci number
//     cout << n << "th fibonacci number: " << fibb(n) << endl;
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int pow(int base, int power)
// {
//     // Base case
//     // if base^0=1
//     if (power == 0)
//     {
//         return 1;
//     }
//     // multiply base with base by power times
//     return base * pow(base, power - 1);
// }

// int main()
// {
//     // Base input
//     cout << "Enter base: ";
//     int base;
//     cin >> base;
//     // power input
//     cout << "Enter power: ";
//     int power;
//     cin >> power;
//     // Function call to get the power of base
//     cout << base << "^" << power << " = " << pow(base, power) << endl;
//     return 0;
// }

// #include <iostream>
// using namespace std;

// // Recursive function to get the sum
// int sum(int arr[], int n)
// {
//     // base case if index is less than zero
//     // then return 0
//     if (n < 0)
//         return 0;
//     // else add nth index element and recur to the n-1th index
//     return arr[n] + sum(arr, n - 1);
// }

// int main()
// {
//     cout << "Enter number: ";
//     // Input size of array
//     int n;
//     cin >> n;
//     int arr[n];
//     // Input array
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     // get sum of array of elemetns
//     int ans = sum(arr, n - 1);
//     cout << ans << endl;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int countOccurance(string str, int ind)
// {
//     // base case
//     // if index is less than 0
//     if (ind < 0)
//     {
//         return 0;
//     }
//     // if str[ind] is any vowel then count it and iterate the string to count
//     // next vowels
//     if (str[ind] == 'a' or str[ind] == 'e' or str[ind] == 'i' or str[ind] == 'o' or str[ind] == 'u' or str[ind] == 'y')
//     {
//         return 1 + countOccurance(str, ind - 1);
//     }
//     // else iterate string
//     else
//     {
//         return countOccurance(str, ind - 1);
//     }
// }

// int main()
// {
//     cout << endl;
//     cout << endl;
//     cout << "Enter string: ";
//     // input string
//     string str;
//     cin >> str;
//     // get length of string
//     int len = str.length();
//     int getCount = countOccurance(str, len - 1);
//     cout << getCount << endl;
//     return 0;
// }

#include <iostream>
using namespace std;

string reverseString(string s)
{
    // base case
    if (s.empty())
    {
        return s;
    }
    // revese string by index by index
    else
    {
        return reverseString(s.substr(1)) + s[0];
    }
}

int main()
{
    cout << endl;
    cout << endl;
    // input string
    string str;
    cin >> str;
    // reverse string
    string ans = reverseString(str);
    cout << ans << endl;
    return 0;
}
