#include<iostream>
#include<map>
#include<chrono>
#include<thread>
using namespace std;


// Utility function , which prints all the entries that contains the keywords enterd by user
void getEntries(multimap<string,string>&Database)
{
    cout<<"\nEnter Keywords: ";
    string keyword;
    cin>>keyword;

    // Iterator for iterating all enteries loaded into database
    multimap<string, string>::iterator itr;

    cout<<"Entries which contains entered keyword: "<<endl;
    for(itr = Database.begin(); itr != Database.end(); ++itr)
    {
        // if we have found the keyword either in artist name or in song name
        // then print this entery
        if(itr->first.find(keyword)!=string::npos || itr->second.find(keyword)!=string::npos)
        {
            cout<<itr->first<<": "<<itr->second<<endl;
        }
    }
}

void getCount(multimap<string,string>&Database)
{
    // Iterator for iteration of entries
    multimap<string, string>::iterator itr;


    // map is a STL Container, which stores the entries in sorted order
    // also it maintain the frequency of each entry which occurs multiple times in database
    map<string,int>Count;
    for(itr = Database.begin(); itr != Database.end(); ++itr)
    {
        // increment the entry , if found more than one times
        Count[itr->second]++;
    }
    cout<<"Count of songs with frequency in alphabetically order "<<endl;
    // Map will print the song names in sorted order
    // Print each entry with its frequency
    for(auto it:Count)
    {
        // Song name          Frequency
        cout<<it.first<<"="<<it.second<<endl;
    }
}

int main()
{
    // multipmap is a STL Container, which does work same as map
    // Also, it is NOT required that the key-value and mapped value pair have to be unique in this case. 
    //  multimap is that multimap keeps all the keys in sorted order always.


    // STL Container to store data
    multimap<string,string>Database;
    cout<<"Data is loading into database...."<<endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    Database.insert(pair<string, string>("Spitboy","True Self"));
    Database.insert(pair<string, string>("Spitboy","In Your Face"));
    Database.insert(pair<string, string>("Lil Wayne","In Your Face"));
    Database.insert(pair<string, string>("Chaos UK","Victimized"));
    Database.insert(pair<string, string>("CHaos UK","King for a Day"));
    Database.insert(pair<string, string>("UB40","Johnny Too Bad"));
    Database.insert(pair<string, string>("UB40","Red Red Wine"));
    Database.insert(pair<string, string>("Neil Diamond","Red Red Wine"));
    Database.insert(pair<string, string>("Incubus","Admiration"));
    Database.insert(pair<string, string>("Johnboy","Admiration"));
    Database.insert(pair<string, string>("Jawbreaker","Kiss the Bottle"));
    Database.insert(pair<string, string>("Minor Threat","Straight Edge"));
    Database.insert(pair<string, string>("Bikini Kill","Rebel Girl"));
    Database.insert(pair<string, string>("MC 900 Foot Jesus","Killer Inside Me"));
    Database.insert(pair<string, string>("Sonic Youth","Kill Yr Idols"));
    Database.insert(pair<string, string>("Husker Du","Eight Miles High"));
    Database.insert(pair<string, string>("Butuch Hancock","One Kiss"));
    Database.insert(pair<string, string>("Butuch Hancock","Already Gone"));
    Database.insert(pair<string, string>("The Clash","Complete Control"));
    // system("Color 0A");
    cout<<"Data has been successfully Loaded..."<<endl;
    int choice=1;
    while(choice>=1 and choice<=2)
    {
        cout<<endl;
        cout<<"1. Get Keywords Entries"<<endl;
        cout<<"2. Get Songs Count"<<endl;
        cout<<"\nEnter Choice: ";
        cin>>choice;
        if(choice==1)
        {
            // call function to get the result
            getEntries(Database);
        }
        if(choice==2)
        {
            // call function to get the result
            getCount(Database);
        }
    }
    return 0;
}