# Formula to find the calories
'''Calories=((Age*0.2757)+(Weight*0.03295) + (Heart Rate*1.0781)-75.4991)*time/8.368'''
# Input of age
age = int(input())
# Input of weight
weight = int(input())
# Input of heartRate
heartRate = int(input())
# Input of time
time = int(input())
# Find calories
calories = ((age*0.2757)+(weight*0.03295) +
            (heartRate*1.0781)-75.4991)*time/8.368
# Print total calories
print(f'Calories: {calories:.2f} calories')
