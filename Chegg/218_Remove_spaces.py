# Function which removes all the white spaces between characters
def reduceWhiteSpace(s):
    # get modified string after removing white spaces
    newString = s.replace(" ", "")
    # Return the newModified String
    return newString


# Input of string
s = input("Enter string: ")
# Print before modifying it
print("String before removing white spaces: " + s)
# get modified string
modifiedString = reduceWhiteSpace(s)
# print after modifying
print("String after removing white spaces: "+modifiedString)
