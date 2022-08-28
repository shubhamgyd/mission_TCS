# Number of student
student=int(input("Please Enter Number of student: "))
# Open a file to write student info
file=open("grades.txt",'w')
for i in range(student):
    # inout of ith student grade
    grade=input(f"Enter grade of student {i+1}: ")
    # store the ith studentInfo
    studentInfo=str(i+1)+grade
    # write it into the file
    file.write(studentInfo+"\n")
# close file
file.close()

# hashmap/dictionary to store each grade along it's count
grades={}
# try block to open file
try:
    # open file to read data line by line
    file=open("grades.txt",'r')
    print("\nStudent and Their Grades")
    print("Student\t Grade")
    # print data line by line
    for line in file:
        print(line[0]+"\t  "+line[1])
        studentGrade=line[1]
        # check if grade is already present in hashMap or not
        # if yes the increment the count of respective grade
        if studentGrade in grades:
            grades[studentGrade]=grades[studentGrade]+1
        # else put it with count 1
        else:
            grades[studentGrade]=1
# close the file
finally:
    file.close()

print("\n")
# printing count of each grade
print("Grade and Their Count")
print("Grade\t Count")
for key,value in grades.items():
    print(key+"\t "+str(value))

# Printing average of each grade
print("\nAverage of Each Grade")
print("Grade\t Average")
for key,value in grades.items():
    avgerageOfGrade=round((value/student)*100,2)
    print(key+"\t "+str(avgerageOfGrade))
