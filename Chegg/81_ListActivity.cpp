#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
#include<memory>
using namespace std;


class CourseActivity
{
private:
    string name;
public:
    CourseActivity(string aname="Temporary"): name(aname){}
    string getName() const {return name;}
    void setNAme(string aname){name=aname;}
    void report() const{
        cout<<"Course Activity: "<<name<<endl;
    }
};

class TestActivity: public CourseActivity
{
private:
    int attemptsAvailable;
    int attemptsTaken;
    double testScore;
public:
    int getAtteptsAvailable() const {return attemptsAvailable;}
    void setAttemptsAvailabe(int available) {attemptsAvailable=available;}
    int getAttempsTaken() const {return attemptsTaken;}
    void setAtteptsTaken(int taken) {attemptsTaken=taken;}
    double getTestScore() const {return testScore;}

    void setTestScore(double sc){ testScore=sc;}
    void report() const;
};

// prototype of functions used by main
void printTestActivities(const TestActivity *ptr,int size);
unique_ptr<TestActivity[]> createTestActivityArray(int count);

int main()
{
    int size {0};
    cin>>size;
    cin.ignore();

    for(int index=0;index<size;++index)
    {
        char DELIM=',';
        string name;
        getline(cin,name,DELIM);
        string input;
        getline(cin,input,DELIM);
        int available=0;
        available=stoi(input);
        getline(cin,input,DELIM);
        int taken=0;
        taken=stoi(input);
        getline(cin,input);
        double score=0.0;
        score=stod(input);
    }

    return 0;
}