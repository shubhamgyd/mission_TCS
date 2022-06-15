#include<iostream>
#include<vector>
using namespace std;


int main()
{
    // Initial sample data array
    vector<int>sampleDataArray={5,6,87,21,89,87,87};

    // length of the array
    int length=7;

    // key we have to find in the sampleDataArray
    int key=87;

    // vector which stores the indices of occurance of key in SampleDataArray
    vector<int>indices;

    // Iterating in sampleDataArray
    for(int i=0;i<length;i++)
    {
        // if key is found in the sampleDataArray
        if(sampleDataArray[i]==key)
        {
            // push the index into vector (0 based indexing)
            indices.push_back(i);
        }
    }

    // print all occurances of key
    cout<<endl;
    cout<<endl;
    int size=indices.size();
    cout<<"The number "<<key<<" has been found at indices ";
    for(int i=0;i<size;i++)
    {
        cout<<indices[i]<<", ";
    }
    cout<<endl;
    cout<<endl;
    return 0;
    
}