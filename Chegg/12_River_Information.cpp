#include<bits/stdc++.h>
using namespace std;

// structure to store the information about lake
struct Lake
{
    string name;
    double area;
    double height;
    double depth;
    Lake(string lakeName,double lakeArea,double lakeHeight,double lakeDepth)
    {
        name=lakeName;
        area=lakeArea;
        height=lakeHeight;
        depth=lakeDepth;
    }
};

// Helper function which compare the depth of lakes and return the the lake 
// which have greatest depth
bool CompareDepth(Lake a,Lake b)
{
    return a.depth>b.depth;
}

// Helper function which compare the area of lakes and return the the lake 
// which have smalles area
bool CompareArea(Lake a,Lake b)
{
    return a.area<b.area;
}


// Helper function which compare the area of lakes and return the the lake 
// which have greatest area
bool CompareArea1(Lake a,Lake b)
{
    return a.area>b.area;
}

// Utility function which print the lake which have greatest depth
void greatestDepth(vector<Lake>&Info)
{
    // sort the lakes according to depth of lakes
    sort(Info.begin(),Info.end(),CompareDepth);
    cout<<"Greatest depth of Lake is: "<<Info[0].name<<endl;
    cout<<"Depth : "<<Info[0].depth<<endl;
}


// Utility function which print the depth of lake which have smallest area
void lakeWithSmallestArea(vector<Lake>&Info)
{
    // sort the lakes according to area of lakes
    sort(Info.begin(),Info.end(),CompareArea);
    cout<<"Depth of the Lake which have smallest area: "<<Info[0].depth<<endl;
    cout<<"Lake : "<<Info[0].name<<endl;
}


// Utility function which print the information about lake which have largest area
void largestAreaLakeInfo(vector<Lake>&Info)
{
    // sort the lakes according to area of lakes
    sort(Info.begin(),Info.end(),CompareArea1);
    cout<<"Information about largest area lake: "<<endl;
    cout<<"Name: "<<Info[0].name<<endl;
    cout<<"Area: "<<Info[0].area<<endl;
    cout<<"Depth: "<<Info[0].depth<<endl;
    cout<<"Height from sea level: "<<Info[0].height<<endl;
}


// Utility function which print the name of lakes whose depth is in given range
void printLakeInRange(vector<Lake>&Info)
{
    double start=5;
    double end=20;
    cout<<"Name of the lakes whose depth is in range[5,20]: "<<endl;
    int size=Info.size();
    for(int i=0;i<size;i++)
    {
        if(Info[i].depth>=start && Info[i].depth<=end)
        {
            cout<<Info[i].name<<endl;
        }
    }
}

int main()
{
    // to store the information of lakes
    vector<Lake>Info;

    // append all data into the container
    Info.push_back(Lake("Paravani",37.5,2073,3.3));
    Info.push_back(Lake("Paliastomi",18.2,-0.3,3.2));
    Info.push_back(Lake("Tabatskuri",14.2,1997,40.2));
    Info.push_back(Lake("Jandari",10.6,291,7.2));
    Info.push_back(Lake("Ritsa",1.49,884,101));
    Info.push_back(Lake("Bazaleti",1.22,879,7));
    cout<<endl;

    // print the information about lakes according to tasks
    greatestDepth(Info);
    cout<<endl;
    lakeWithSmallestArea(Info);
    cout<<endl;
    largestAreaLakeInfo(Info);
    cout<<endl;
    printLakeInRange(Info);
    cout<<endl;
    return 0;
}