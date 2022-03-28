#include<iostream>
#include<queue>
using namespace std;

int main()
{
    // queue is a data structure which works on th FIFO( First in First Out) Principle
    
    // queue onject to store the elements
    queue<int>q;
    q.push(77);              // front
    q.push(55);
    q.push(48);
    q.push(32);
    q.push(25);              // rear


    // dequeue means removing the front element from the queue
    
    // removing the front element and store it one vaiable
    int temp=q.front();
    q.pop();

    // getting the front element and add it temp
    temp+=q.front();
    q.pop();

    temp=temp/11;


    // push the result into the queue
    q.push(temp);

    // pushing the fron element into last and removing it
    q.push(q.front());
    q.pop();

    cout<<endl;
    cout<<endl;
    // printing the final queue after this operations
    cout<<"\nQueue Elements after final operation: ";
    while(!q.empty())
    {
        // getting the font element
        cout<<q.front()<<" ";;
        q.pop();
    }
    return 0;
}

/*
Function TASK(A,n)
    For j-> 1 to n-1 do
        k->A[j]
        i->j-1
        while i>=0 and A[i]>k do
            print(A[i])
            i=i-1
        end while
        j=j+1;
    end for
end function


Analysis: 
Here we have n is the length of the array.
So, first for loop goes from index 1 till the end of the array. menas it will run n times 
i.e it checked one more iteration for j is less than n-1 or not then after that it will terminate

Then we have another while loop it goes from previous index of j till the 0th index. And parallely it checing the 
element at the ith index is greater than the jth index or not. If it is greater than the jth index, then it will print
this element and index of i goes one step backword and so on.

So in worst case scenario it will run n times 

so see below complexity analysis for better understanding

Function TASK(A,n)
    For j-> 1 to n-1 do -------->       (n)
        k->A[j]      -------- >         (1)     
        i->j-1      ---------->         (1)
        while i>=0 and A[i]>k do ------>(n)
            print(A[i])          -->    (1)
            i=i-1                 --->  (1) 
        end while
        j=j+1;                 -->      (1)
    end for
end function

T(TASK)= n*(1+1+n*(1+1+1))
       = n+n+n*(3n);
       = 2n + 3n^2
       = n^2  ( ignoring constant)

Note: Constant are not considering while computing the complexity

Worst Case: O(n^2)
Best Case: O(n)  , if array is in sorted order

*/