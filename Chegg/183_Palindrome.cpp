#include <iostream>
using namespace std;

int main()
{
    // Keep track on total palindromes
    int countPalindrome = 0;
    // Iterate from 1 to 9999
    for (int i = 1; i <= 9999; i++)
    {
        // convert integer to string
        string str = to_string(i);
        // two pointer approach to check given number is palindrome or not

        // point to the 0th indes
        int j = 0;
        // point to the last index
        int k = str.length() - 1;
        // keep track on given string is palindrome or not
        bool isPalindrome = true;
        // Iterate until j<=k
        while (j <= k)
        {
            // if jth and kth char is not same then break and mark current number is not palindrome
            if (str[j] != str[k])
            {
                isPalindrome = false;
                break;
            }
            j++;
            k--;
        }
        // if given number is palindrome
        if (isPalindrome)
        {
            // Increment palindrome
            countPalindrome++;
        }
    }
    // Display total palindrome
    cout << countPalindrome << endl;
    return 0;
}