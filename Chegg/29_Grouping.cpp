#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
    // Number of classifications
    int n;
    cin>>n;

    // mat data structure to store the classification accorind to locationd and animal type
    // like [location1]-> [animal1][num]
    //      [location2]-> [animal2][num]
    map<string,map<string,int>>classifications;

    // vector to store the locations
    // according to the guidelines output locations same as they appears in input
    vector<string>locations;

    // map data structure to store the animals as they appear in input according the location type
    map<string,vector<string>>Animals;


    // Input
    for(int i=0;i<n;i++)
    {
        string animal;
        int num;
        string location;

        // Input animal name , number, location type
        cin>>animal>>num>>location;

        // if we have found new location then store it in our locations storage
        if(classifications.find(location)==classifications.end())
        {
            locations.push_back(location);
        }

        // if we have found new animal in particular location then add this animal into our animals storage
        if(find(Animals[location].begin(),Animals[location].end(),animal)==Animals[location].end())
        {
            Animals[location].push_back(animal);
        }


        // update the cound of animals according to the location type
        classifications[location][animal]= classifications[location][animal]+num;
    }

    cout<<"\nOutput: "<<endl;
    // now itarate through the locations as they appears into the input
    for(int i=0;i<locations.size();i++)
    {
        // display location
        cout<<locations[i]<<": ";
        
        // now go the animal appears into that particular locations
        for(auto it:Animals[locations[i]])
        {
            // name of animal and total count of that animal
            cout<<it<<" "<<classifications[locations[i]][it]<<", ";
        }
        cout<<endl;
    }
}