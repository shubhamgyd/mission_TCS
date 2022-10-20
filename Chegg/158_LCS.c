#include <stdio.h>
#include <string.h>

// return maximum in between a and b
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// function which returns the longest common subsequence of text1 and text2
int longest_common_subsequence(char *text1, char *text2, int n, int m)
{
    // base case
    // if legth of any string is zero
    if (n == 0 || m == 0)
        return 0;

    // If both string have same character
    // then we will count it and check for other characters
    if (text1[n - 1] == text2[m - 1])
    {
        // add 1 and check for other chars
        return 1 + longest_common_subsequence(text1, text2, n - 1, m - 1);
    }
    // else we have two choices
    // 1. Either stay at same position at text1 and check other chars in text2
    // 2. Or stay at same position at text2 and check for other chars in text1
    else
    {
        // stay at m and check in text1                         or stay at n and check in text2
        return max(longest_common_subsequence(text1, text2, n - 1, m), longest_common_subsequence(text1, text2, n, m - 1));
    }
}

void main()
{
    // string 1
    char text1[] = "abc";
    // string 2
    char text2[] = "abc";

    // get length of string 1
    int n = strlen(text1);
    // get length of strng 2
    int m = strlen(text2);
    // get longest common subsequence
    int length = longest_common_subsequence(text1, text2, n, m);
    // print length
    printf("%d", length);
}