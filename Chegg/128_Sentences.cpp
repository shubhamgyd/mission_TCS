#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
    // vector to store the string of length less than or equal to 30
    vector<string> vec;
    // given string
    string str;
    // input string
    getline(cin, str);
    // stringstream to get the word by word from the string
    stringstream ss(str);
    // store the word from string
    string word;
    // keep track on final string
    string sentence = "";
    // keep track on lenght of string
    int length = 0;
    // Iterate the string and append words into sentence
    while (ss >> word)
    {
        // get the length of word
        int len = word.length();
        // if word length + previous string length is greater than 30
        // then push the previous string into vector
        // clear the previous sentence and append word in it
        // also update the length of sentece as the length of word
        if (length + len > 30)
        {
            vec.push_back(sentence);
            sentence = word;
            sentence += " ";
            length = len + 1;
        }
        // else append the word into sentence
        else
        {
            sentence += word;
            // add space
            sentence += " ";
            // update length
            length += len;
            // for space character
            length += 1;
        }
    }
    // for last of sentence have some words and length is less than equal to 30
    // append it into the vector
    if (sentence.length() > 0)
    {
        vec.push_back(sentence);
        sentence = "";
    }
    // print all sentences whose length is less than or equal to 30
    cout << endl;
    for (auto it : vec)
    {
        cout << it << endl;
    }
    return 0;
}