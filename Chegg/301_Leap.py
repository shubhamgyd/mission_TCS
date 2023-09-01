# Current Era
CE = 2023
# Indicates whether year is leap or not
isLeapYear = False
# Checking for leap year
if ((CE % 4 == 0) and (CE % 100 != 0)) or (CE % 400 == 0):
    isLeapYear = True

# Dictionary to store months and their days
monthDict = {}
# Store month and their days
monthDict['January'] = 31
monthDict['Jan'] = 31
if isLeapYear:
    monthDict['February'] = 29
else:
    monthDict['February'] = 28
monthDict['Feb'] = monthDict['February']
monthDict['March'] = 31
monthDict['Mar'] = 31
monthDict['April'] = 30
monthDict['Apr'] = 30
monthDict['May'] = 31
monthDict['June'] = 30
monthDict['Jun'] = 30
monthDict['July'] = 31
monthDict['Jul'] = 31
monthDict['August'] = 31
monthDict['Aug'] = 31
monthDict['September'] = 30
monthDict['Sep'] = 30
monthDict['October'] = 31
monthDict['Oct'] = 31
monthDict['November'] = 30
monthDict['Nov'] = 30
monthDict['December'] = 31
monthDict['Dec'] = 31


# Input of month name
monthName = input("Enter Month Name: ")
# Check entered month name is in dictionary or not
# if not then print error msg
if monthName not in monthDict:
    print("Error!: Invalid month name")

# else print month name and days
else:
    print(f'{monthName}:{monthDict[monthName]}')
