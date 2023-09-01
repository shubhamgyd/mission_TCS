/*
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.



Example 1:

Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2
Since 2 has only one digit, return it.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int addDigits(int num)
    {
        //         int temp=0;
        //         bool flag=0;
        //         while(num)
        //         {
        //             temp+=num%10;
        //             num/=10;
        //             if(num<=0)
        //             {
        //                 if(temp<10)
        //                 {
        //                     flag=1;
        //                     num=temp;
        //                     break;
        //                 }
        //                 else
        //                 {
        //                     num=temp;
        //                     temp=0;
        //                 }
        //             }

        //             if(flag)
        //             {
        //                 break;
        //             }
        //         }
        //         return num;

        if (num == 0)
            return 0;
        if (num % 9 == 0)
            return 9;
        return num % 9;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution obj;
    cout << obj.addDigits(n) << endl;
    return 0;
}