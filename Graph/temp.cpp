#include<iostream>
using namespace std;


int main()
{
    // for loop start from the 2030 and run until 2020
    for(int year=2030;year>=2020;year--)
    {
        // according to the consition if current year is 2025 then skip it
        // continue is the statement it will go to the next iteration, by skipping current one
        if(year==2025)
        {
            continue;
        }
        // else print the year
        else
        {
            cout<<year<<endl;
        }
    }
    return 0;
}