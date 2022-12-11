# Number of teams
n = int(input())

# Input of size of each team
teamSizes = []
for i in range(n):
    teamSizes.append(int(input()))


# input of k , maximum number of teams can we reduced 
k = int(input())

# dictionary to store the team and their frequencey
teamsAndFreq = {}

# Iterate teamSizes
for teamSize in teamSizes:
    # push into the dictionary and increment it's count
    if teamSize in teamsAndFreq:
        teamsAndFreq[teamSize] = teamsAndFreq[teamSize]+1
    else:
        teamsAndFreq[teamSize] = 1

# get the maximum frequency of amongh all teams
maxFreq = 0

# get the team size
team = 0

# Iterate dictionary and get the maximum frequency and teamSize
for key, value in teamsAndFreq.items():
    if value > maxFreq:
        maxFreq = value
        team = key

# get total number of team which have size greater than the teamSize(found in earlier step)
cnt = 0

# Iterate teamSizes again
for teamSize in teamSizes:
    # if teamSize is greater than team then count
    if teamSize > team:
        cnt = cnt+1

# answer is maxFreq + minimum among k and totalAvailable teams which have size greater than teamSize
ans = maxFreq+min(k, cnt)

# Print ans
print(ans)
