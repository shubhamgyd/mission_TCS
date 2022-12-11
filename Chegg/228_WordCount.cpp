#include <iostream>
#include <sstream>
using namespace std;

// Function which counts the total number of words present in the given string
int wordCount(string str)
{
    // Stringstream which split the stiring into list of words
    stringstream ss(str);
    // get each word from the string
    string word = "";
    // get total count of words
    int cnt = 0;
    // Iterate string and count the words
    while (ss >> word)
    {
        cnt++;
    }
    // return total count
    return cnt;
}

int main()
{
    // get total words
    int totalWords = 0;
    while (true)
    {
        // Read string
        cout << "Enter a sentence:";
        string str;
        getline(cin, str);
        // If string is empty
        // then break loop
        if (str.empty())
        {
            break;
        }
        // else get total word count of entered string
        // and add it into total words
        totalWords += wordCount(str);
    }
    // Display total words
    cout << "The word count is " << totalWords << endl;
    return 0;
}