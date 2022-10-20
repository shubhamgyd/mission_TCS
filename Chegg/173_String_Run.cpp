#include <iostream>
using namespace std;

int main()
{
    // Input string
    string str;
    getline(cin, str);
    // get final answer
    string ans = "";
    // get length of string
    int n = str.length();
    // start from oth index
    int i = 0;
    // Iterate string
    while (i < n)
    {
        // if current char is white seperated then
        // put as it is in the final answer
        if (str[i] == ' ')
        {
            ans += " ";
            i++;
            continue;
        }
        // else
        // start from ith index and keep counting the same occurance char
        // until end of string
        int j = i;
        int cnt = 0;
        // keep counting if jth char is same as ith char
        while (j < n and str[j] == str[i])
        {
            j++;
            cnt++;
        }
        // if count of char is greater than 1
        if (cnt > 1)
        {
            // first add it's count
            ans += to_string(cnt);
            // then put char
            ans += str[i];
        }
        // else just put char
        else
        {
            ans += str[i];
        }
        // update i
        i = j;
    }
    cout << ans << endl;
    return 0;
}
/*
Time complexity: O(n)
Here n is the length of string
Explanation: We are visiting each char only once, wo it require only O(n) time

Space Complexity: O(n)
Explanation: We are making new string so in worst case it requires O(n) space
*/

/*
Pseudo code
Input string
Initialize answer string as empty
while the index is less than length of string
    while the jth char is same as ith char and j is less than the length of string
        count the occurance of ith char

    if occurance is greater than one
        ocnvert number into string and add it into ans
        then add current char into string
    else
        add current char into string

    update i as j

print answer string

*/