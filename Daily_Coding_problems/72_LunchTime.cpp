/*
This question is asked by Apple. You are serving people in a lunch line and need to 
ensure each person gets a “balanced” meal. A balanced meal is a meal where there exists 
the same number of food items as drink items. Someone is helping you prepare the meals and 
hands you food items (i.e. F) or a drink items (D) in the order specified by the items string. 
Return the maximum number of balanced meals you are able to create without being able to 
modify items.
Note: items will only contain F and D characters.

Ex: Given the following items…

items = "FDFDFD", return 3
the first "FD" creates the first balanced meal.
the second "FD" creates the second balanced meal.
the third "FD" creates the third balanced meal.
Ex: Given the following items…

items = "FDFFDFDD", return 2
"FD" creates the first balanced meal.
"FFDFDD" creates the second balanced meal.

*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;
    int foodCounter=0, drinkCounter=0,mealCounter=0;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='F') 
        {
            foodCounter++;
        }
        else if(str[i]=='D')
        {
            drinkCounter++;
        }
        if(foodCounter==drinkCounter)
        {
            mealCounter++;
        }
    }
    cout<<mealCounter<<endl;
    return 0;
}
// Time Complexity:O(n)
// Space Complexity:O(1)