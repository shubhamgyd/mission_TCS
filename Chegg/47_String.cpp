#include<bits/stdc++.h>
using namespace std;

// Task 1: Utility function which accepts the string and convert it into the another format
// Here we are going to convert C++ style string into C style string

void Style_Conversion(string str)
{
    int len=str.length();                 // length of string


    // Converting C++ style string to C style string
    char arr[len+1];                       // char array

    // Not Iterate the string
    for(int i=0;i<len;++i)
    {
        // storing char into char array
        arr[i]=str[i];
    }
    arr[len]='\0';
    // printing char array
    cout<<"Char array of string: "<<endl;
    cout<<"{ ";
    for(int i=0;i<=len;++i)
    {
        cout<<"'"<<arr[i]<<"', ";
    }
    cout<<" }"<<endl;
}



// Task 2: We are eliminating elements in the sequence which are divisible by given variable

int *eliminate_divisible(int start,int end,int var)
{
    // Creating the array of size end-start+1
    int* arr=new int[end-start+1];

    // Initialize array with the max_element, so that we will print element between start to end
    for(int i=0;i<end-start+1;++i)
    {
        arr[i]=end+1;    // indicates the this is not valid number in range
    }

    int ind=0;   // keep tracking on the index of  arr

    // Iterate the sequence and delete all those numbers which are divisible by var
    for(int i=start;i<=end;++i)
    {
        // if number is divisible by var
        if((i)%var==0)
        {
            arr[ind]=i;
            ind++;
        }
    }
    return arr;
}


// Task 3: Removing all repeated occurance pairs whose gcd=1

class OP
{
    int gcd(int a,int b) 
    {
        if (b==0) return a;
        return gcd(b,a%b);
    }
public:
    void unique(vector<int>&arr)
    {
        int size=arr.size();   // size of array
        set<pair<int,int>>uniquePairs;   // which will remove the duplicate pairs

        map<pair<int,int>,int>occurance;    // which indicates the occurance of pairs


        // Iterating the array
        for(int i=0;i<size;i++)
        {
            for(int j=i+1;j<size;j++)
            {
                int num=gcd(arr[i],arr[j]);
                if(num==1)
                {
                    uniquePairs.insert({arr[i],arr[j]});   // insert into the uniquePairs
                    occurance[{arr[i],arr[j]}]++;          // insert into key-value hash map
                }
            }
        }

        // Now print the repeated occurance pairs whose gcd=1
        cout<<"Deleted Paris: "<<endl;
        cout<<"Pair"<<fixed<<setw(13)<<"Occurance"<<endl;
        for(auto it:occurance)
        {
            // if current pair occurs more than 1 times then print it
            if(it.second>1)
            {
                cout<<it.first.first<<","<<it.first.second<<"----->"<<fixed<<setw(3)<<it.second<<endl;
            }
        }
        
    }
};

int main()
{
    // Task 1: Style_Conversion
    string str;
    str="abcfgja";
    cout<<"\nTask: 1"<<endl;
    Style_Conversion(str);


    cout<<endl;


    // Task 2: Eliminate_divisible
    cout<<"\nTask: 2"<<endl;
    int start=10;
    int end=90;
    int var=6;
    int* arr=new int[end-start+1];
    arr=eliminate_divisible(start,end,var);
    int size=end-start+1;

    //priting elements which are divisible by var
    cout<<"Elements which are divisible by var= "<<var<<endl;
    for(int i=0;i<size;i++)
    {
        // we have set the condition
        if(arr[i]<=end)
        {
            cout<<arr[i]<<" ";
        }
    }

    cout<<endl;



    cout<<"\nTask: 3"<<endl;

    vector<int>elements={1,1,3,4,2,3,6,5,9,7,0,3,11,13,17,3,7,5,5,5,7,9,3};
    OP obj;
    obj.unique(elements);
    cout<<endl;
    return 0;
}