#include<bits/stdc++.h>
using namespace std;

// Utility function gives the minimum element from the vector
void min_element(vector<double>&vec)
{
    // initialize min value with max so it will give us minimum value
    double mn=INT_MAX;
    int size=vec.size();

    // iterating vector
    for(int i=0;i<size;i++)
    {
        // if element is less than min value
        if(vec[i]<mn)
        {
            // update min value
            mn=vec[i];
        }
    }

    // printing min value
    cout<<"\nMinimum Value: "<<mn<<endl;
}



// Utility function print the max value from vector
void max_element(vector<double>&vec)
{
    // initialize the max value with min_value
    double mx=INT_MIN;
    int size=vec.size();

    // Iterting the vector
    for(int i=0;i<size;i++)
    {
        // if element is larger than the max value
        if(vec[i]>mx)
        {
            // update the max value
            mx=vec[i];
        }
    }

    // print the max value
    cout<<"Max Value: "<<mx<<endl;
}


// Utility function print the average of vector elements
void average(vector<double>&vec)
{
    int size=vec.size();
    double sum=0;
    for(int i=0;i<size;i++)
    {
        // add into sum
        sum+=vec[i];
    }
    // finding average
    double ans= sum/(double)size;

    // printing average
    cout<<"Average: "<<ans<<endl;
}

int main()
{
    // vector to store the element
    vector<double>vec;
    cout<<"\nEnter size of vector:";
    int n;
    cin>>n;
    
    // taking elements
    for(int i=0;i<n;i++)
    {
        cout<<"Enter number: ";
        double a;
        cin>>a;
        vec.push_back(a);
    }
    // finding min element
    min_element(vec);

    // finding max element
    max_element(vec);

    // finding average
    average(vec);


    // adding more element
    cout<<"\nAdd more element to get min,max, average "<<endl;
    while(1)
    {
        // if user want to add more element or not
        // 1->yes
        // 0->no
        cout<<"Do you want to add number(1|0): ";
        int flag;
        cin>>flag;
        if(flag==1)
        {
            cout<<"Enter number: ";
            double num;
            cin>>num;
            vec.push_back(num);
        }
        else
        {
            break;
        }
    }


    // finding the size of vector
    int size=vec.size();

    // printing the min and max-size of vector
    bool hashSize=false;
    if(vec.size())
    {
        hashSize=true;
    }
    if(hashSize)
    {
        cout<<"Min size vector: "<<1<<endl;
    }
    else
    {
        cout<<"Min size vector: "<<0<<endl;
    }
    cout<<"Max size vector: "<<size<<endl;
    return 0;

}