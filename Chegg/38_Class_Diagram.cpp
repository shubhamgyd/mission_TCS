#include<bits/stdc++.h>
using namespace std;



// Base Class: Parent Class
class Human
{
protected:
    int id;
    string name;
public:
    void speak();
};



// 1st subclass of Human -> Lecturer
class Lecturer: public Human
{
// attribute
protected:
    int roomNumber;

// method
public:
    
};

// 2nd subclass of Human->Student
class Student: public Human
{
// Attributes
protected:
    int CGPA;

// methods
public:
    void takeNote();
};


// 1st subclass of Student->localStudent
class localStudent: public Student
{
// Attributes
protected:
    int IC_Number;

public:

    // Methods
    void study();
    void takingExam();
};

// 2nd subclass of Student->foreignStudent
class foreignStudent: public Student
{
protected:
    // attributes
    int passportNumber;
public:
    // methods
    void study();
    void takingExam();
};




int main()
{

}