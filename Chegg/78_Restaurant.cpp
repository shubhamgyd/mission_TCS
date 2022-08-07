#include <bits/stdc++.h>
using namespace std;

// Structure to store the information of restaurant
struct RectrauntStruct
{
    string name;
    string phone;
    string type;
    string avgPrice;
};

int main()
{
    // constant size to store the restaurant information
    const int SIZE = 100;
    RectrauntStruct allRestraunts[SIZE];
    // myIn likes cin
    ifstream myIn;
    // open the file
    myIn.open("restaurant.txt");
    if (!myIn)
    { 
        // file couldn't be opened
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }
    // variable for to store the vaue
    string firstLine("");
    // after every 4 line it indicates that we have fetched all information about particular 
    // restaurant
    int count = 0;
    // index to store the restaurant values
    int i = 0;
    // total count of rectaurant
    int restaurantCount = 0;
    // get first line of file
    if (getline(myIn, firstLine))
    {
        // set it as a name of restaurant
        allRestraunts[i].name = firstLine;
    }
    // now go to the second line i.e 1st index line
    count = 1;
    // until end of file
    while (!myIn.eof())
    {
        // variable to store the value of restaurant info
        string line("");
        if (getline(myIn, line))
        {
            // if index is less than 100 and count is less than 4
            if (count < 4 and i < 100)
            {
                // 0th count means name of restaurant
                if (count == 0)
                {
                    allRestraunts[i].name = line;
                    count++;
                }
                // count=1 menas phone of restaurant
                else if (count == 1)
                {
                    allRestraunts[i].phone = line;
                    count++;
                }
                // count=2 means type of restaurant
                else if (count == 2)
                {
                    allRestraunts[i].type = line;
                    count++;
                }
                // count=3 means averagePrice 
                else if (count == 3)
                {
                    allRestraunts[i].avgPrice = line;
                    count = 0;
                    i++;
                    // Increment the restaurant count
                    restaurantCount++;
                }
            }
            // after 100 restaurant we can't store restaurants

            else
            {
                count++;
                // so after every count>=3 , increment the count of restaurant
                if(count==3)
                {
                    restaurantCount++;
                    count=0;
                }
            }
        }
    }
    myIn.close();
    // Total restaurant count
    cout << "Total Restaurants: " << restaurantCount << endl;
    //  if restaurant is greater than 100 then we can only print 100 of them
    for (int i = 0; i < min(restaurantCount,100); i++)
    {
        // print all information abount ith restaurant
        cout << "Restaurant: " << i + 1 << endl;
        for (int j = i; j < i + 1; j++)
        {
            cout << "Restaurant Name: " << allRestraunts[j].name << endl;
            cout << "Phone No       : " << allRestraunts[j].phone << endl;
            cout << "Restaurant Type: " << allRestraunts[j].type << endl;
            cout << "Average Price  : " << allRestraunts[j].avgPrice << endl;
        }
        cout << endl;
    }
}