// Imported required Library

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <ios>
using namespace std;


// Structure to store the student data
struct Student
{
    string name;
    int marks;
    char grade;
    // Constructor to set the student name, marks and grade
    Student(string studentName, int studentMarks, char studentGrade)
    {
        this->name = studentName;
        this->marks = studentMarks;
        this->grade = studentGrade;
    }
};


// Function which sort the student according to their marks and grades
bool comparison(Student student1, Student student2)
{
    // if two student have same makrs
    // then student will come first who have better grade
    if (student1.marks == student2.marks)
    {
        return (student1.grade>student2.grade);
    }
    // else student who have greater marks comes first
    return ( student1.marks>student2.marks) ;
}

// Utility finction which sort the students
void SortMakrsAndGrades(vector<Student> &student, int n)
{
    sort(student.begin(), student.end(), comparison);
}

int main()
{
    // Input : Number of students
    cout << "Enter Number of Students: ";
    int n;
    cin >> n;

    // Vector container to store the student data
    vector<Student> student;

    // Iterating and input student data
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Name: ";
        string name;
        cin >> name;
        int marks;
        char grade;
        cout << "Enter Marks: ";
        cin >> marks;
        cout << "Enter Grade: ";
        cin >> grade;
        student.push_back(Student(name, marks, grade));
        cout<<endl;
    }

    // Calling function to sort data
    SortMakrsAndGrades(student, n);

    // Printing sorted student data
    cout<<"Sorted Student According to their Marks and Grades: "<<endl;
    cout<<fixed<<"Name"<<setw(10)<<"Marks"<<setw(10)<<"Grade"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<fixed<<student[i].name<<setw(10)<<student[i].marks<<setw(10)<<student[i].grade<<endl;
    }
    return 0;
}