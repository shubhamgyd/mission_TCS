#include<bits/stdc++.h>
using namespace std;


int main()
{
    // Map Data Structure to store the ID, Country Name for checking entered ID is present in 
    // File System or not
    map<string,string>ID_Country;

    // Opening file for reading data
    fstream myfile; 
    myfile.open("location.txt",ios::in );
    

    // if given file exist
    if(myfile.is_open())
    {
        // string which fetch the id and country name from file
        string id_country;

        // reading data from file
        while( getline(myfile,id_country,'"') )
        {
            std::stringstream ss(id_country);
            std::string id,country_name;
            
            // Extracting id and country name 
            std::getline(ss,id,',');
            std::getline(ss,country_name,',');

            // storing into the map
            ID_Country[id]=country_name;
        }
    }
    else
    {
        // if file is not found, then create it
        cout<<"No data found in file"<<endl;
        ofstream file("location.txt",ios::app);
        cout<<"File Generated Successfully.."<<endl;
    }
    bool hasCountry=(ID_Country.size());


     // if file has any data
    if(hasCountry)
    {
        // Display File data 
        cout<<"\nCountry and Corresponding ID: "<<endl;
        for(auto it:ID_Country)
        {
            if(!it.first.empty() and !it.second.empty())
            {
                cout<<it.second<<" and "<<it.first<<endl;
            }
        }
    }

    cout<<"\nPlease Enter Code and Location to check Availability: "<<endl;
    // Taking Input
    while(1)
    {
        // taking input id
        string id,countryName;
        cout<<"\nEnter ID: ";
        cin>>id;

        // if given id is already present, then print id and country name
        // no need to append same id in file
        if(ID_Country.find(id)!=ID_Country.end())
        {
            cout<<"ID Found!!!"<<endl;
            cout<<ID_Country[id]<<" and "<<id<<endl;
            cout<<endl;
        }
        else
        {
            // else append the new id and country name into file system
            ofstream file("location.txt",ios::app);

            cout<<"ID not found...."<<endl;
            // taking country name input
            cout<<"Enter Country Name: ";
            cin>>countryName;

            // storing into map and appending into the file system
            if(!countryName.empty())
            {
                ID_Country[id]=countryName;
                string line= '"' + id+","+countryName + '"';
                cout<<countryName<<" and "<<id<<endl;
                file<<"\n";
                file<<line;
                file.close();
                cout<<"Data Saved Successfully....!!"<<endl;
                cout<<endl;    
            }       
            else
            {
                cout<<"Country Name not Empty...!!"<<endl;
            }
        }
    }

}