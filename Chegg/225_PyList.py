# String of list
L = ["Laptop", "Computer", "Mobile", "Tablet", "iPad", "iPhone", "PC", "Android"]
# Letter which need to check in list of strings
letter = 'a'
# variable which keep track on letter if found in list of strings or not
found = False
# Iterate list and check if any string contains this letter then update found as true
for string in L:
    # check string contain letter or not
    if letter in string:
        # update found
        found = True

# print found
print(found)
