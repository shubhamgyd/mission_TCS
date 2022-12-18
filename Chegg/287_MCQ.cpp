#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream inFS;
    int numBooks;
    int numStudents = 40;
    inFS >> numBooks;
    cout << "Books per student: ";
    cout << numBooks / numStudents << endl;
}