

# Student dictionry which store the information of about student
studentInfo={}

# loop until program ends
while True:
    # Options of Operations
    print("PRESS 1: TO ADD STUDENT INFORMATION")
    print("PRESS 2: TO DELETE STUDENT INFORMATION")
    print("PRESS 3: TO UPDATE INFORMATION")
    print("PRESS 4: TO DISPLAY STUDENT INFORMATION")
    print("PRESS 5: TO EXIT SYSTEM")
    print("\n")
   
    # option inout
    option=int(input("ENTER YOUR OPTION: "))



    # if option is 1
    # add student information into the dictionry
    if option==1:
        print("ADDING STUDENT INFORMATION: ")
        print("\n")


        # taking all the reauired input from user
        name=input("ENTER STUDENT NAME : ")
        sr_code=input("ENTER STUDENT SR-CODE: ")
        age=input("ENTER STUDENT AGE: ")
        major1=input("ENTER STUDENT MAJOR: ")
        email_id=input("ENTER STUDENT EMAIL-ID: ")
        address=input("ENTER STUDENT ADDRESS: ")


        # validate the student sr-code
        # if enteres sr-code is already present into the dictionary
        # then we need to add new and unique sr-code id to add student information
        if sr_code in studentInfo.keys():
            print("GIVEN STUDENT IS ALREADY PRESENT, PLEASE ENTER VALID INFORMATION..!!!!")
        

        # is sr-code is not present in dictionary
        # means sr-code id is unique, add data
        else:
            studentInfo[sr_code]={}              # creating dictionary of name,email etc fields
            studentInfo[sr_code]["name"]=name
            studentInfo[sr_code]["sr-code"]=sr_code
            studentInfo[sr_code]["age"]=age
            studentInfo[sr_code]["major"]=major1
            studentInfo[sr_code]["email_id"]=email_id
            studentInfo[sr_code]["address"]=address
            print("STUDENT DATA ADDED SUCCESSFULLY...!!!!")
            print("\n")


    # if option is 2
    if option==2:

        # taking input of sr-code which we want to delete
        sr_code=input("PLEASE ENTER STUDENT SR-CODE: ")

        # checking entered sr-code is present into the dictionary or not
        if sr_code not in studentInfo.keys():
            print("PLEASE ENTER VALID SR-CODE: ")
            print("\n")
        
        # is present the delete it
        else:
            del studentInfo[sr_code]
            print("STUDENT DATA DELETED SUCCESSFULLY....!!!!")


    # if option is 3
    if option==3:
        print("UPDATING INFORMATION")


        # taking sr-code input to update student data
        sr_code=input("PLEASE ENTER STUDENT SR_CODE TO UPDATE: ")


        # checking sr-code is already present in dictionary or not
        if sr_code not in studentInfo.keys():
            print("PLEASE ENTER VALID SR-CODE")
            print("\n")

        # if present then update data
        else:
            new_name=input("ENTER STUDENT NAME : ")
            new_sr_code=input("ENTER STUDENT SR-CODE: ")
            new_age=input("ENTER STUDENT AGE: ")
            new_major1=input("ENTER STUDENT MAJOR: ")
            new_email_id=input("ENTER STUDENT EMAIL-ID: ")
            new_address=input("ENTER STUDENT ADDRESS: ")


            studentInfo[sr_code]["name"]=new_name
            studentInfo[sr_code]["sr-code"]=new_sr_code
            studentInfo[sr_code]["age"]=new_age
            studentInfo[sr_code]["major"]=new_major1
            studentInfo[sr_code]["email_id"]=new_email_id
            studentInfo[sr_code]["address"]=new_address

            print("STUDENT DATA UPDATED SUCCESSFULLY...!!!")
            print("\n")
    

    # if option is 4
    if option==4:
        print("DISPLAYING INFORMATION..!!!")

        # displaying student information
        for key in studentInfo.keys():
            print("---------------------")
            print("STUDENT NAME : "+ studentInfo[key]["name"])
            print("STUDENT SR-COE: "+ key)
            print("STUDENT AGE: "+ studentInfo[key]["age"])
            print("STUDENT MAJOR: "+ studentInfo[key]["major"])
            print("STUDENT EMAIL-ID: "+ studentInfo[key]["email_id"])
            print("STUDENT ADDRESS: "+ studentInfo[key]["address"])
            print("\n")
    

    # exiting program
    if option==5:
        print("ESITING PROGRAMM...!!!")
        exit(0)
