#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "gocodeiscool"; string t = "goose";
    int i = 0, j = 0, MinLength = INT_MAX, start = 0;
    unordered_map<char, int> hashTable;

    // Map of the pattern
    for (auto it : t) hashTable[it]++;

    // Size of map
    int count = hashTable.size();

    // If first char is found at zero index
    // Then decrease the value of that key
    // And keep eye on the size of map
    // if value of this char becomes 0 then we no need to find anymore char of same , so we can
    // decrease the size of map by 1
    if (hashTable.find(s[j]) != hashTable.end())
    {
        hashTable[s[j]]--;
        if (hashTable[s[j]] == 0) count--;
    }

    // Iterate to the first string
    while (j < s.length())
    {

        // If size of map is greater zero means we need to find chars of the pattern string
        if (count > 0)
        {
            j++;
            // Check wheather jth index char is present in map  or not , is yes then reduce its
            // value by 1 also keep eye on map size
            if (hashTable.find(s[j]) != hashTable.end())
            {
                hashTable[s[j]]--;
                if (hashTable[s[j]] == 0) count--;
            }
        }

        // IF we found all chars present in pattern string, then we no need to find anymore chars
        // now we are finding min length, of substring
        else if (count == 0)
        {
            // Update the length
            if (MinLength > j - i + 1)
            {
                MinLength = j - i + 1; start = i;
            }

            // Appending chars in map again, till size of map is zero
            // so that we will get desired substring
            while (count == 0)
            {
                if (hashTable.find(s[i]) != hashTable.end())
                {
                    hashTable[s[i]]++;
                    if (hashTable[s[i]] == 1)
                    {
                        count++;

                        // Update the minLength
                        if (MinLength > j - i + 1)
                        {
                            MinLength = j - i + 1; start = i;
                        }
                    }
                    i++;
                }
                else
                {
                    i++;
                }
            }
        }
    }
    string str = "";
    if (MinLength != INT_MAX) str.append(s.substr(start, MinLength));
    cout << "Shortest Substring : " << str << endl;
    cout<<endl;
    return 0;
}