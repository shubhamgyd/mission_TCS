if __name__ == '__main__':
    # Number of lines
    N = 10
    # Opening file1 to read
    file1 = open('file_1.txt', 'r')
    # Keep track on count of lines
    count = 0
    # For loop to read file line by line
    for word in file1:
        # Remove new line char
        newLine = word.strip()
        # print line in console
        print(newLine)
        # Increment count
        count = count+1
        # Check if count is equal to N or not
        # If yes then break the loop
        if count == N:
            break
