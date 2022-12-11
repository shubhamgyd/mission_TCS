# Read comma seperated integers i.e scores of students
scores = input("Enter a series of grades, separated by commas: ")
# convert into list by removing comma
scoreList = list(scores.split(','))
# get bestScore i.e max score from the scoreList
bestScore = max(scoreList)
# convert into int
bestScore = int(bestScore)

# For grade A
A = bestScore - 10

# For grade B
B = bestScore - 20

# For grade C
C = bestScore - 30

# For grade D
D = bestScore - 40

# Iterate in scoreList
for i in range(len(scoreList)):
    # get score of ith student
    score = int(scoreList[i])
    # if score is greater than or equal to A
    if score >= A:
        print(f"The grade of student {i} is A")
    # if score is greater than or equal to B
    elif score >= B:
        print(f"The grade of student {i} is B")
    # if score is greater than or equal to C
    elif score >= C:
        print(f"The grade of student {i} is C")
    # else print D
    else:
        print(f"The grade of student {i} is D")
