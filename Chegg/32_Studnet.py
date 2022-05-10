# a file named "data", will be opened with the reading mode and writing mode.
file = open('data.txt', 'r+')

#dictionary will store the name of student and grade
NameGrade={}


#list of dictionary will store the grade and list of student
GradeNames={}


#initialise empty list for every grade
GradeNames['A']=[]
GradeNames['B']=[]
GradeNames['C']=[]
GradeNames['D']=[]
GradeNames['F']=[]


#read the given file
for each in file:

    #split the data in the format of list
    nameAndGrade=list(each.split(" "))

    # add student name and grade as a key,value pair in respective disctionary
    #          Student Name         Grade
    NameGrade[nameAndGrade[0]]=nameAndGrade[1][0]


    # append the student name is respective grade list
    #            Grade                    Student Name
    GradeNames[nameAndGrade[1][0]].append(nameAndGrade[0]);

# Run the program until exit
while True: 

    # Options to display
    print("1. Show all Students and Grades")
    print("2. Show Student with particular grades")
    print("3. Add a Student")
    print("4. Show a class Summary")
    print("5. Exit")


    # user input for option
    n=int(input("Enter Option: "))

    # if option=1
    if n==1:

        # printing student data
        print("\nStudent Data: \n")

        # Table format with some spaces between two columns
        print ("{:<10} {:<10}".format('NAME', 'GRADE'))

        # printing each name and grade
        for key,value in NameGrade.items():
            name,grade=key,value
            print("{:<10} {:<10}".format(name, grade),end="\n")
        
        print("\n")


    # if option=2
    if n==2:
        # Grades must be A,B,C,C or F
        print("Grades must be A or B or C or D or F")

        # input of grade
        grade1=input("Enter Grade: ")

        # validate grade
        while grade1!="A" and grade1!="B" and grade1!="C" and grade1!="D" and grade1!="F":
            print("Please enter valid grade: ")
            grade1=input("Enter Grade: ")

        print("Students with Grade "+grade1+ ": ");

         # Printing Students with the respective grade
        print(GradeNames[grade1])
    
        print("\n")


    #if option=3
    if n==3:

        # input of student name
        name=input("Enter Student Name: ")

        # input of grade
        gradeNew=input("Enter Grade: ")

        #validate grade
        while gradeNew!="A" and gradeNew!="B" and gradeNew!="C" and gradeNew!="D" and gradeNew!="F":
            print("Please enter valid grade: ")
            gradeNew=input("Enter Grade: ")

        # append new line in file system
        file.write("\n")

        # append the student with grade in file system
        file.write(r"{0} {1}".format(name,gradeNew));

        # append the student and grade in dictionary
        NameGrade[name]=gradeNew

        # append the student name in respective grade list
        GradeNames[gradeNew].append(name)

        print("\n")

    if n==4:
        # count of each grade students
        studentA=len(GradeNames["A"])
        studentB=len(GradeNames["B"])
        studentC=len(GradeNames["C"])
        studentD=len(GradeNames["D"])
        studentF=len(GradeNames["F"])


        # printing the number of students who got respective grade
        print("Students with Grade A: "+str(studentA))
        print("Students with Grade B: "+str(studentB))
        print("Students with Grade C: "+str(studentC))
        print("Students with Grade D: "+str(studentD))
        print("Students with Grade F: "+str(studentF))

        print("\n")

    # exit program
    if n==5:
        print("Exiting the program...")
        exit()
    

    # validate option
    else:
        print("Please Enter valid option")
        continue
