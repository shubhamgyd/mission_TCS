# Utility function which return the total studs using length and width
def lego_stud_finder(length,width):
    # finding lengthBricks
    lengthBricks=length//10
    # finding widthBricks
    widthBricks=width//10
    # return total studs
    return lengthBricks*widthBricks

# print total studs
print("\n")
print("\n")
print("\n")
print(lego_stud_finder(68, 45))