#function which update the first name
def q2a(fname):
    # user input for first name
    userName=input("Enter your name: e.g. John : ")
    # splitting string into wordList
    wordList=list(fname.split(" "))

    # replacing first name with newName
    # as first name is located at the last of string
    wordList[-1]=userName

    # convert list to string
    updatedName=' '.join(wordList)

    #return updatedName
    return updatedName

def main():
    # any random name input
    name=input("Enter any random name: e.g First Name is Harry: ")
    newName=q2a(name)

    # priting updated name
    print("Updated Name is: "+newName);

if __name__== '__main__':
    main()