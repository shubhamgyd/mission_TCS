/*
This problem was asked by Amazon.

Run-length encoding is a fast and simple method of encoding strings. 
The basic idea is to represent repeated successive characters as a single count and character. 
For example, the string "AAAABBBCCDAA" would be encoded as "4A3B2C1D2A".

Implement run-length encoding and decoding. You can assume the string to be
 encoded have no digits and consists solely of alphabetic characters. 
 You can assume the string to be decoded is valid.
*/

#include<bits/stdc++.h>
using namespace std;


int main()
{
    string str;
    cin>>str;
    string ans="";
    int i=0;
    while(i<str.length())
    {
        int j=i;
        int ct=0;
        while(j<str.length() && str[j]==str[i])
        {
            ct++;
            j++;
        }
        ans+=to_string(ct);
        ans.push_back(str[i]);
        i=j;
    }
    cout<<ans<<endl;
    return 0;
}


/*
// Daily coding problem #29
// Run-length encoding is a fast and simple method of encoding strings. The basic idea is to represent repeated successive characters as
// a single count and character. For example, the string "AAAABBBCCDAA" would be encoded as "4A3B2C1D2A".

// Implement run - length encoding and decoding.You can assume the string to be encoded have no digits and consists solely of alphabetic
// characters.You can assume the string to be decoded is valid.


#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> run_length(std::string str)
{
    std::vector<std::string> result;
    if (str.empty() || str.size() == 1)
    {
        result.push_back(str);
        return result;
    }

    int count = 1;
    for (int i = 1; i < str.size(); ++i)
    {
        if (str[i] == str[i - 1])
            count++;
        else
        {
            if (count > 1)
            {
                result.push_back(std::to_string(count));
            }
            result.push_back((std::string(1, str[i - 1])));
            count = 1;
        }
    }
    if (count > 1)
    {
        result.push_back(std::to_string(count));
    }
    result.push_back(std::string(1, str[str.size() - 1]));

    return result;
}

int main()
{
    std::string str = "AAAAAAAAAABBBCCAA";
    auto result = run_length(str);

    for (auto it : result)
        std::cout << it << " ";

    std::cin.get();
}
*/