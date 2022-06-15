#include<iostream>
#include<vector>

using namespace std;


int main()
{
    // part a
    vector<int>a;

    // vector from 1 to 20
    for(int i=1;i<=20;i++)
    {
        // assigning elements into the vector
        a.push_back(i);
    }
    cout<<"Part a: ";
    for(auto it:a) cout<<it<<" ";
    cout<<endl;

    // part b
    vector<int>b;

    // vector element from 20 to 1
    for(int i=20;i>=1;i--)
    {
        // assigning elements into the vector
        b.push_back(i);
    }
    cout<<"Part b: ";
    for(auto it:b) cout<<it<<" ";
    cout<<endl;

    // part c
    vector<int>c;
    // First part from 1 to 20
    for(int i=1;i<=20;i++)
    {
        c.push_back(i);
    }

    // second part from 19 to 1
    for(int i=19;i>=1;i--)
    {
        c.push_back(i);
    }
    cout<<"Part c: ";
    for(auto it:c) cout<<it<<" ";
    cout<<endl;


    // part d;
    vector<int>d={4,6,3};
    cout<<"Part d: ";
    for(auto it:d) cout<<it<<" ";
    cout<<endl;


    // part e
    vector<int>e;

    // vector contains 10 occurance of 4
    for(int i=1;i<=10;i++)
    {
        e.push_back(4);
        e.push_back(6);
        e.push_back(3);
    }
    cout<<"Part e: ";
    for(auto it:e) cout<<it<<" ";
    cout<<endl;

    // part f
    vector<int>f;

    // vector contains 11 occurance of 4, 10 occurance fof 6, 10 occurance of 3
    for(int i=1;i<=10;i++)
    {
        f.push_back(4);
        f.push_back(6);
        f.push_back(3);
    }
    // 11th occurance
    f.push_back(4);
    cout<<"Part f: ";
    for(auto it:f) cout<<it<<" ";
    cout<<endl;


    // part g
    vector<int>g;
    // vector contains 10 occurnce of 4
    for(int i=1;i<=10;i++)
    {
        g.push_back(4);
    }

    // 20 occurance of 6
    for(int i=1;i<=20;i++)
    {
        g.push_back(6);
    }

    // 30 occurance of 3
    for(int i=1;i<=30;i++)
    {
        g.push_back(3);
    }
    cout<<"Part g: ";
    for(auto it:g) cout<<it<<" ";
    cout<<endl;




}