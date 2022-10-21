/*
Description
Ugly number is a number that only have prime factors 2, 3 and 5.

Design an algorithm to find the Nth ugly number. The first 10 ugly numbers are 1, 2, 3, 4, 5, 6, 8, 9, 10, 12...

Note that 1 is typically treated as an ugly number.

1 \leq n \leq 10^{5}1≤n≤10 
5
 

Example
Example 1:

Input:

n = 9
Output:

10
Explanation:

[1,2,3,4,5,6,8,9,10,....],the ninth ugly number is 10.

Example 2:

Input:

n = 1
Output:

1
Challenge
O(n log n) or O(n) time.

*/

#include<bits/stdc++.h>
using namespace std;


int factorOfTwo(int n,int a)
{
    while(n%a==0)
    {
        n/=a;
    }
    return n;
}
int factorOfThree(int n,int a)
{
    while(n%a==0)
    {
        n/=a;
    }
    return n;
}
int factorOfFive(int n,int a)
{
    while(n%a==0)
    {
        n/=a;
    }
    return n;
}


bool isUgly(int n)
{
    n=factorOfTwo(n,2);
    n=factorOfThree(n,3);
    n=factorOfFive(n,5);

    return n==1?true:false;
}

int UglyNumber(int n)
{
    int i=1;
    int count=1;
    while(n>count)
    {
        i++;
        if(isUgly(i))
        {
            count++;
        }
    }
    return i;
}
// Not efficient method
// Space Complexity :O(1)




int nthUgly(int n)
{
    set<int>st;
    st.insert(1);
    n--;
    while(n)
    {
        auto it=st.begin();
        int num=*it;
        st.erase(it);
        st.insert(2*(num));
        st.insert(3*(num));
        st.insert(5*(num));
        n--;
    }
    cout<<*st.begin()<<endl;
    return *st.begin();
}
// Time Complexity:O(nlogn)
// Auxiliary Space :O(1)

int main()
{
    int n;
    cin>>n;
    int num=UglyNumber(n);
    cout<<"nth Ugly number is: "<<num<<endl;
    nthUgly(n);
    return 0;
}