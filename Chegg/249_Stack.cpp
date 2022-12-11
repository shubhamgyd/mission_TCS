#include <iostream>
#include <vector>
using namespace std;

// Stack class
class Stack
{
public:
    // Public stack vector
    vector<char> stack;
    // method to push char into stack
    void push(char);
    // method to pop char from stack
    void pop();
};

// push char c into the stack
void Stack::push(char c)
{
    stack.push_back(c);
}

// get reverseString
string reverseString = "";
// pop last char from the stack and push in back into the reverseString
// so we will get reverseString
void Stack::pop()
{
    char ch = stack.back();
    reverseString += ch;
    stack.pop_back();
}

int main()
{
    // Read String
    cout << "Enter String: ";
    string str = "";
    cin >> str;
    // Stack class object
    Stack obj;
    // Iterate string and push each char into the stack
    for (int i = 0; i < str.length(); i++)
    {
        obj.push(str[i]);
    }
    // Pop each char from the stack and push into the reverseString
    for (int i = str.length(); i >= 0; i--)
    {
        obj.pop();
    }
    // Keep track on given string is palindrome or not
    bool isPalindrome = true;
    // Iterate string and check both string have same char at ith index
    // if yes then continue
    // else mark as non palindrome
    for (int i = 0; i < str.length(); i++)
    {
        // if ith char of both string is not same
        // then it is not a palidrome
        if (str[i] != reverseString[i])
        {
            isPalindrome = false;
            break;
        }
    }
    // if givne string is palindrome
    if (isPalindrome)
    {
        cout << "Given String is Palindrome!" << endl;
    }
    // if given string is not palindrome
    else
    {
        cout << "Given String is not Palindrome!" << endl;
    }
    return 0;
}