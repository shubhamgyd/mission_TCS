#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <set>
using namespace std;

// function checks given char is present in the vector or not
void check(vector<char> &c, vector<unsigned> &n, char ch, int num)
{
    for (int i = 0; i < c.size(); i++)
    {
        // if present
        if (c[i] == ch)
        {
            n[i] += num;
            return;
        }
    }
    // if not present
    c.push_back(ch);
    n.push_back(num);
    cout << endl;
}

// print both the character and it's count
void print_input(vector<char> &c, vector<unsigned> &n)
{
    for (int i = 0; i < c.size(); ++i)
    {
        cout << c[i] << ": " << n[i] << endl;
    }
    cout << endl;
}

// get the vector count
void get_vector(string &name, vector<char> &c, vector<unsigned> &n)
{
    for (auto ch : name)
    {
        check(c, n, ch, 1);
    }
    cout << endl;
}

// largest ascending subseqence from the count vector along its starting index and length
void largest_asc_sub(vector<unsigned> &n, int &start, int &len)
{
    // set which stores the unique elements
    set<int> s;
    // Iterate count vector
    for (auto a : n)
    {
        // if current element is already present in the set
        // continue
        if (s.find(a) != s.end())
            continue;
        // else insert into set
        s.insert(a);
        // get it's position from set
        auto it = s.upper_bound(a);
        // if this is not last element
        // then erase it
        // because we want larget increasing subsequence
        if (it != s.end())
            s.erase(it);
    }
    // get size
    len = s.size();
    // get starting index of largest increasing subsequence
    int startElement = *s.begin();
    for (int i = 0; i < n.size(); i++)
    {
        if (n[i] == startElement)
        {
            start = i;
            return;
        }
    }
}

// print the subset
void print_subset(vector<char> &c, int start, int len)
{
    for (int i = start; i < start + len; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;
}

int main()
{
    // to store the characters
    vector<char> c;
    // to store the count
    vector<unsigned> n;
    // read file
    ifstream file;
    file.open("a.text");
    std::string line;
    // read file line by line
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        char ch;
        unsigned num;
        string words;
        int ind = 0;
        while (ss >> words)
        {
            if (ind == 0)
            {
                ch = words[0];
                ind++;
            }
            else if (ind == 1)
            {
                num = stoi(words);
            }
        }
        // store into char and count vector
        c.push_back(ch);
        n.push_back(num);
    }

    // functions
    print_input(c, n);

    check(c, n, 'a', 10);

    string str = "";
    cout << "Enter string: ";
    cin >> str;

    get_vector(str, c, n);

    print_input(c, n);

    int start = 0;
    int len = 0;

    largest_asc_sub(n, start, len);

    print_subset(c, start, len);
}