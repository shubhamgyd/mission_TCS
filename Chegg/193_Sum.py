# Input of n
n = int(input())
# Get total Sum
S = 0
# Starting from 2
i = 2
# Use while loop to get sum
while i <= n:
    # formula s=s+i/i+2
    S = S+(i/(i+2))
    # Increment i by 2
    i = i+2
# Print total sum
print(S)
