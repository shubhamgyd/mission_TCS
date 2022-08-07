# Utility Function which finds the family assistance amount using some conditions
def familyAssistance():
    # keep track on totalFamilyAssistance
    # of all families
    totalAmountOfAssistance=0
    # run until user want
    while True:
        # input: income
        income=int(input("Enter housold income: "))
        # if -1 end program
        if income==-1:
            print("Exit..!!!")
            # print totalAsstitance value till the families
            print(f'Tha total amount of Assistance: {totalAmountOfAssistance}')
            return
        # children input
        children=int(input("Enter number of children: "))
        # condition 1: if income is greater than 30000 and less than or equal to 40000
        if income>30000 and income<=40000:
            # if children greater than or equal to 3
            if children>=3 :
                # totalAssistance for this family children is
                assistanceAmount=children*1000
                # add this to our global totalAssistance
                totalAmountOfAssistance=totalAmountOfAssistance+assistanceAmount
                # Print amount of assistance
                print(f'Amount of Assistance: {assistanceAmount}')
        # Condition 2: if income is greater than 20000 and less than or equal to 30000
        elif income>20000 and income<=30000:
            # if family have greater than or equal to 2 children
            if children>=2:
                # totalAssistance for this family children is
                assistanceAmount=children*1500
                # add this to our global totalAssistance
                totalAmountOfAssistance=totalAmountOfAssistance+assistanceAmount
                # Print amount of assistance
                print(f'Amount of Assistance: {assistanceAmount}')
        # else if income is less than or equal to 20000
        elif income<=20000:
            # totalAssistance for this family children is
            assistanceAmount=children*2000
            # add this to our global totalAssistance
            totalAmountOfAssistance=totalAmountOfAssistance+assistanceAmount
            # Print amount of assistance
            print(f'Amount of Assistance: {assistanceAmount}')
        # else if income is greater than 40000
        elif income>40000:
            # assitance amount =0
            assistanceAmount=0
            totalAmountOfAssistance=totalAmountOfAssistance+0
            print(f'Amount of Assistance: {assistanceAmount}')
    

if __name__ == '__main__':
    familyAssistance()
    