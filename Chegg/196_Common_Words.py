# Opening file1 to read
file1 = open('file1.txt', 'r')

# List to store all words from file1
list1 = []

# For loop to read file line by line
for word in file1:
    # Remove new line char
    newWord = word.strip()
    # Append word into list1
    list1.append(newWord)

# Close file
# file1.close()

# Opening file2 to read
file2 = open('file2.txt', 'r')

# Here is the list which stores the common words present in both files
commonWords = []
for word in file2:
    # Remove new line char
    newWord = word.strip()
    # If word found int list1
    if newWord in list1:
        # Append it into the commonWord list
        commonWords.append(newWord)

# Sort list
commonWords.sort()

# Print list
print(commonWords)
