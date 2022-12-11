# Import random
import random
# Sum of sumOfDieces generated randomly
sumOfDie = 0
# Iterate 10 times
for i in range(10):
    # Get random number
    number = random.randint(1, 6)
    # Add into sum
    sumOfDie = sumOfDie+number
# Print sum
print(sumOfDie)
