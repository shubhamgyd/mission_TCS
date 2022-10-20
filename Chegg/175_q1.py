# Input of n and m
# number of students and number of operations
n, m = map(int, input().split(' '))

# dictionary of groupA
groupA = []

# dictionary of groupB
groupB = []

# Input of n students in which group he/she belongs
students = list(map(str, input().split()))
for i in range(len(students)):
    # if i==A then ith student belongs to the groupA
    if students[i] == "A":
        groupA.append(i+1)
    # else ith student belongs to the groupB
    else:
        groupB.append(i+1)

# score of GroupA
scoreA = 0

# score of GroupB
scoreB = 0

# now iterate m times and get check citations
for i in range(m):
    # Input of operation
    operation = input().split(' ')
    # take process
    oper = operation[0]
    # get student 1
    student1 = int(operation[1])
    # get student 2
    student2 = 0
    if len(operation) == 3:
        student2 = int(operation[2])
    # if operation is citation
    if oper == "cite":
        # both student belongs to same group , either in A or in B
        if (student1 in groupA and student2 in groupA) or (student1 in groupB and student2 in groupB):
            # if they belongs to groupA
            if student1 in groupA:
                scoreA = scoreA+1
            # else they belongs to groupA
            else:
                scoreB = scoreB+1

        # if they belongs to different groups
        # if student1 in groupA and student2 in groupB
        if student1 in groupA and student2 in groupB:
            # increment score of 2nd group by 5
            scoreB = scoreB+5

        # if they belongs to different groups
        # if student1 in groupB and student2 in groupA
        if student1 in groupB and student2 in groupA:
            # increment score of 1st group by 5
            scoreA = scoreA+5

    # if operation is change
    if oper == "change":
        # if student 1 is from groupA then change his/her group A->B
        if student1 in groupA:
            groupA.remove(student1)
            groupB.append(student1)
        # else student 1 is from groupB then change his/her group B->A
        else:
            groupB.remove(student1)
            groupA.append(student1)

# print score of groupA and groupB respectively
print(str(scoreA)+" "+str(scoreB))
