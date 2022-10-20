#include <string>
#include <iostream>
#include <vector>

using namespace std;

// get queue of strings
vector<string> split(string str, string token)
{
    // store the strings
    vector<string> result;
    // Iterate till last word
    while (str.size())
    {
        // get each word between space seperated token
        // and push it into the queue
        int index = str.find(token);
        if (index != string::npos)
        {
            result.push_back(str.substr(0, index));
            str = str.substr(index + token.size());
            if (str.size() == 0)
                result.push_back(str);
        }
        else
        {
            result.push_back(str);
            str = "";
        }
    }
    return result;
}

// Utility function which removes the k elements from queue
// As queue is a linear data structure which store elements in a linear fashion
// Also it works on FIFO(First in First out) principle
// so while removing elements , remove from the fron of it
// this function function removes the k front element from queue
void QueueMultiRemove(int k, vector<string> &tokens)
{
    // get size of queue
    int n = tokens.size();
    // if k is greater than the size of queue
    // then remove all elements
    int removeUntil = min(k, n);
    // remove k elements
    while (removeUntil--)
    {
        // remove from the front of the queue
        tokens.erase(tokens.begin() + 0);
    }
}

int main()
{
    string text = "As she said these words her foot slipped, and in another moment, splash! she was up to her chin in salt water. Her first idea was that she had somehow fallen into the sea, and in that case I can go back by railway, she said to herself.";
    vector<string> tokens = split(text, " ");
    // Display queue
    for (int i = 0; i < tokens.size(); i++)
    {
        cout << tokens[i] << "\t";
    }
    cout << endl;
    // Task 1:
    // Count of her/Her
    int countHer = 0;
    for (int i = 0; i < tokens.size(); i++)
    {
        // compare each string word with her and Her
        // if matched then increment count
        if (tokens[i] == "her" or tokens[i] == "Her")
        {
            countHer++;
        }
    }
    cout << "\nCount of the word her/Her = " << countHer << endl;
    cout << endl;

    // Task 2:
    // Remove k elements from the front of queue
    int k = 4;
    QueueMultiRemove(k, tokens);
    // Display queue after removing k elements
    for (int i = 0; i < tokens.size(); i++)
    {
        cout << tokens[i] << "\t";
    }

    return 0;
}