# Import math library
import math
# User input of num1,num2,num3
num1 = float(input())
num2 = float(input())
num3 = float(input())

# ans1 contains num1 to the power of num3
ans1 = num1**num3
# ans2 contains num1 to the power of (num2 to the power of num3)
ans2 = num1**(num2**num3)
# ans3 contains abs value of num1-num2
ans3 = abs(num1-num2)
# ans4 contains sqrt of num1 to the power of num3
ans4 = math.sqrt(ans1)
# Display all values
print(f'{ans1:.2f} {ans2:.2f} {ans3:.2f} {ans4:.2f}')
