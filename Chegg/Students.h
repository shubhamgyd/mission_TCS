#ifndef STUDENTS_H
#define STUDENTS_H
class Students
{
private:
    char *studentNumber;
    char *studentName;
    double GPA;
    void _initStudentNumber(const char *number);
    void _initStudentName(const char *name);

public:
    Students();
    ~Students();
    void setStudentNumber(const char *number);
    void setStudentName(const char *name);
    void setGPA(double gpa);
    const char *getStudentNumber() const;
    const char *getStudentName() const;
    double getStudentGPA() const;
};

#endif