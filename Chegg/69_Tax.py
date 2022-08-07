# User Input of working Hours and payRate
workingHours=int(input("Enter Working Hours: "))
payRate=int(input("Enter Par Rate: "))

# Formula for Gross Pay
# Gross= Hours * Rate
# Net = Gross - Tax
# Tax rate is 5% of gross pay

# calculation of grossPay according to formula
grossPay=workingHours*payRate

# set tax=0 initially
taxAmount=0

# according to condition if user earns more than 50000 then only tax is dudected, otherwise no
if grossPay>50000:
    taxAmount=(grossPay*5)//100
else:
    taxAmount=0

# calculation of netPay according to formula
netPay=grossPay-taxAmount


# printing gross pay 
print(f'Gross Pay: {grossPay}')

# printing net pay 
print(f'Net Pay: {netPay}')

# printing taxAmount 
if taxAmount==0:
    print("No Tax")
else:
    print(f'Tax Amount: {taxAmount}')

