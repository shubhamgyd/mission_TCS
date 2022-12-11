
if __name__ == '__main__':
    # List to store the studnetInformation
    ics234 = []
    # Iterate 2 times
    for i in range(2):
        # keep ith student details
        studentInfo = []
        # Read Name
        name = input("Enter Name: ")
        # Read first test score
        score1 = int(input("Enter First Test Score: "))
        # Read second test score
        score2 = int(input("Enter Second Test Score: "))
        # calculate grade
        grade = ''
        if (score1+score2)//2 >= 93:
            grade = 'A'
        studentInfo.append(name)
        studentInfo.append(score1)
        studentInfo.append(score2)
        studentInfo.append(grade)
        ics234.append(studentInfo)

    # Iterate 2 times
    for i in range(1, 3):
        print(f"\nStudent {i}:")
        # Print name
        print("Name = "+ics234[i-1][0])
        # Print first test score
        print("First Test Score = "+str(ics234[i-1][1]))
        # Print second test score
        print("Second Test Score = "+str(ics234[i-1][2]))
        # Print grade
        print("Grade = "+ics234[i-1][3])
