

student_array = []
studentInd=0
def addNewRecord(admission_prog,applicant_name,father_name ,mother_name ,dob ,gender ,nationality ,permanent_addr ,email ,category ,medium):
    studentInfo=[]
    studentInfo.append(admission_prog)
    studentInfo.append(applicant_name)
    studentInfo.append(father_name)
    studentInfo.append(mother_name)
    studentInfo.append(dob)
    studentInfo.append(gender)
    studentInfo.append(nationality)
    studentInfo.append(permanent_addr)
    studentInfo.append(email)
    studentInfo.append(category)
    studentInfo.append(medium)
    if studentInfo in student_array:
        return False
    
    student_array.append(studentInfo)
    return True
    
def getStudentInfo():
    print("Welcome to the Student Admission Form")
    print("Enter Admission Program")
    admission_prog = input()
    print("Enter Applicant's Name")
    applicant_name = input()
    print ("Enter Father's Name")
    father_name = input()
    print("Enter Mother's Name")
    mother_name = input()
    print("Enter Date of Birth")
    dob = input()
    print("Enter Gender")
    gender = input()
    print("Enter Nationality")
    nationality = input()
    print("Enter Permanent Address")
    permanent_addr = input()
    print("Enter Email Address")
    email=input()
    print("Enter Category")
    category = input()
    print ("Enter Medium")
    medium = input()
    if not addNewRecord(admission_prog,applicant_name,father_name ,mother_name ,dob ,gender , nationality ,permanent_addr ,email ,category ,medium ):
        print("Can't add more!!!")
    else:
        print("Student Information added successfully..!!!")
        print("Want to add another student ??? (Y/N)")
    add_more = input()
    if add_more == 'Y':
        getStudentInfo()

if __name__=="__main__":
    getStudentInfo()