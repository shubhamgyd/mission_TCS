#include <iostream>
using namespace std;

int main()
{
    // 1D array to store top 5 friends
    string friendList[5];
    cout << "[Top 5 Friends' List]\n";
    // keep track on how many freinds are in list
    int index = 0;
    // run program until user want
    while (true)
    {
        // Display menue options
        cout << "\nWhat would you like to do?\n";
        cout << "1) Enter a friend's name\n";
        cout << "2) Replace a friend's name\n";
        cout << "3) Display your friends list\n";
        cout << "4) Quit\n";

        // Get user choice
        int choice;
        cout << "Your choice: ";
        cin >> choice;
        // if choice = 1
        if (choice == 1)
        {
            // get friend name input
            string name;
            cout << "\nEnter a name: ";
            cin.ignore();
            getline(cin, name);
            // Check list is full or not
            if (index < 5)
            {
                bool isValidName = true;
                // Check entered name is already in the friend list or not
                for (int i = 0; i < index; i++)
                {
                    // if name found in the list
                    if (friendList[i] == name)
                    {
                        cout << "Sorry, they'are already on the list!\n";
                        isValidName = false;
                        break;
                    }
                }
                // if entered name is new
                // then assign it at current index
                if (isValidName)
                {
                    friendList[index] = name;
                    // increment index
                    index++;
                }
            }
            // else list if full then display msg
            else
            {
                cout << "Sorry, your friends list is full!\n";
            }
            cout << "\n";
        }
        // if choice = 2
        else if (choice == 2)
        {
            // get name and index
            string name;
            int ind;
            cout << "\nEnter a name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Ente an index: ";
            cin >> ind;
            // keep track on valid index or not
            bool isValidIndex = true;
            // if index is greater than or equal to 5
            // because we have indices from 0 to 4( i.e. 0,1,2,3,4)
            if (ind >= 5)
            {
                cout << "Sorry, that's an invalid command!\n";
                isValidIndex = false;
            }
            // if valid index
            if (isValidIndex)
            {
                // Replace existing name with the new name
                cout << "\n";
                cout << name << " has replaced " << friendList[ind] << " on your friends list!\n";
                friendList[ind] = name;
            }
        }
        // if choice is 3
        else if (choice == 3)
        {
            // display friend list
            cout << "\nFriend's List: \n";
            for (int i = 0; i < 5; i++)
            {
                // if friend name present at ith index
                if (friendList[i].length() > 0)
                {
                    cout << (i + 1) << ") " << friendList[i] << "\n";
                }
                // else print number and space
                else
                {
                    cout << (i + 1) << ") \n";
                }
            }
        }
        // if choice is 4
        // ends the program
        else if (choice == 4)
        {
            cout << "\n[Program Ends]\n";
            break;
        }
        else
        {
            cout << "Invalid choice!!\n";
            break;
        }
    }
    return 0;
}