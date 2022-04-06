#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
    // Initial rating of movies
    int ratings[]={93,76, 54, 97, 91, 86, 92, 34, 53, 93, 91, 96, 67, 93, 99, 64, 51, 56, 62, 56, 31, 80, 81, 11,55,81,70,77,97,57,54,72,98,54,50,79,63,59,57,8,69,51,55,88,89,98,91,58,74,50,97,70,83,74,75,34,100,90,99,45,23,12,45,90,45,89,97,23,12,43,57,23,80,90,76,34,56,12,89,76,90,76,90,95,93,87,24,45,67,12,87,93,65,56,34,39,79,12,70,100};
    
    // finding the size of movie array
    int size=sizeof(ratings)/sizeof(ratings[0]);

    // Display the movie ratings
    cout<<"\nRatings: "<<endl;
    for(int i=0;i<100;i++)
    {
        cout<<ratings[i]<<",";
    }
    
    // this variable keep track on maximum rating received by Enchantio
    int max_rating_received_by_Enchantio=0;

    // this variable keep counting number of awards win by Enchantio
    int award_counter=0;

    // here we are iterating from 0th index movie to 96th index movie
    // because, according to the condition we are comparing next three consecutive move rating
    // so for that we need to stop 3 index before end
    for(int i=0;i<97;i++)
    {
        // if any movie rating is greater than 80
        if(ratings[i]>80)
        {
            // then check next two consecutive movie rating is greater than 80 or not
            if(ratings[i+1]>80 && ratings[i+2]>80)
            {
                // if condistion satisfied
                // then increment the award counter 
                // and find the maximum rating among them
                award_counter++;
                max_rating_received_by_Enchantio=max({max_rating_received_by_Enchantio,ratings[i],ratings[i+1],ratings[i+2]});
            }
        }
    }

    // printing number of awards received and the maximum rating received
    cout<<endl;
    cout<<"\nNumber of awards win by Enchantio: "<<award_counter<<endl;
    cout<<"Maximum rating received by Enchantio: "<<max_rating_received_by_Enchantio<<endl;
    cout<<endl;
    return 0;
    

}