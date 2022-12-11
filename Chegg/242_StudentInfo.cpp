#include <iostream>
using namespace std;

// Class to store the student information
class studentInfo
{
    // id, name, and cgpa
    int id;
    string name;
    float cgpa;

    // public methods to store studentInfo, deleteRecord, and printRecord
public:
    void addRecord(void);
    void deleteRecord(int);
    void printRecord(void);
};

// object of studentInfo
studentInfo student[5];

// add details of stuent
void studentInfo::addRecord()
{
    cin >> id >> name >> cgpa;
}

// Delete record with given id
void studentInfo::deleteRecord(int id)
{
    // Iterate students
    for (int i = 0; i < 5; i++)
    {
        // check ith student have valid id or not
        if (student[i].id != -1)
        {
            // if matched the id
            // then delete it
            if (student[i].id == id)
            {
                // Display item is found
                cout << "Item is found" << endl;
                cout << student[i].id << ", " << student[i].name << ", " << student[i].cgpa << endl;
                // update the id of ith student as -1
                // so in future it can't be accessed as mentioned validations
                student[i].id = -1;
                return;
            }
        }
    }
    // Else display error
    cout << "Item not found" << endl;
}

void studentInfo::printRecord()
{
    // Display student information
    cout << "\nStudent Records: " << endl;
    for (int i = 0; i < 5; i++)
    {
        // if ith student id is not -1 as we mentioned in delete method
        if (student[i].id != -1)
        {
            // Print data
            cout << student[i].id << ", " << student[i].name << ", " << student[i].cgpa << endl;
        }
    }
}

int main()
{
    // Iterate 5 times and get student data
    for (int i = 0; i < 5; i++)
    {
        student[i].addRecord();
    }
    // get id to delete
    cout << "Enter id to delete: ";
    int id;
    cin >> id;
    // delete id
    student->deleteRecord(id);
    // display list
    student->printRecord();
}
