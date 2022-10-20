/*
Harry and Potter took a word string. Harry chose a number M (less than the length of the
string) and Potter chose N (less than the length of the string). Harry will cut M alphabets
from the end of the string and then add it to the beginning and will give it to Potter. Then,
Potter will also cut N alphabets from the end of the string, add it to the beginning and ther
give to Harry. This process will continue till they get the original word string back.
For a given string and given values of M and N, find the number of turns in which they wi
get the original word string back.
Input Specification:
input1: Original word string
Value of M​
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
}

/*
def harry(str, m, n):
    le = len(str)
    org = str.upper()
    str = str.upper()
    turn = 1 # <--------Here
    for i in str:
        str3 = str[-m:] # last n letters
        str = str.replace(' ', '')[:-m]
        str = str3 + str
        print(str)
        if org != str:
            turn = turn + 1
            str4 = str[-n:]
            str = str.replace(' ', '')[:-n]
            str= str4 + str
            print(str)
        if org == str:

            break
        turn = turn + 1 #< --------------- Here

    print(turn)

str = input("Enter the string\n")
m=int(input("Enter the value of m\n"))
n=int(input("Enter the value of n\n"))
harry(str, m, n)
*/