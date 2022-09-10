# input sentence
sentence = input("Enter sentence: ")
# printing entered sentence
print(sentence)

# finding total words in sentence
words = len(sentence.split())
# keep track in first space character index
firstSpaceInd = 0
# Iterate sentence
for i in range(len(sentence)):
    # if space character
    if sentence[i] == ' ':
        # get index
        firstSpaceInd = i
        break


newString = sentence
# replace ' ' by '+'
newString = newString.replace(" ", "+")
# get length of sentence
stringLen = len(sentence)
# convert uppercase
upperCaseString = sentence.upper()

# words to search in sentence
word1 = "pyThon"
word2 = "JAVA"
word3 = "Matlab"
word1 = word1.lower()
word2 = word2.lower()
word3 = word3.lower()
# initially mark them not found
first = False
second = False
third = False
# Iterate words in sentence
for word in sentence.split():
    word = word.lower()
    # if word1 found
    # mark true
    if word == word1:
        first = True
    # if word2 found
    # mark true
    if word == word2:
        second = True
    # if word3 found
    # mark true
    if word == word3:
        third = True

# dictionary store the frequency of chars in sentences
freqChars = {}
for i in range(len(sentence)):
    if sentence[i] != ' ':
        ch = sentence[i]
        ch = ch.lower()
        if ch in freqChars:
            freqChars[ch] = freqChars[ch]+1
        else:
            freqChars[ch] = 1

# a - Number of words in sentences
print(words)

# b - First index of space Char
print(firstSpaceInd)

# c - string obtained by replacing ' ' by '+'
print(newString)

# d - characters between 6th index to 12th index
if stringLen < 13:
    print("String length is less than 12..")
else:
    print(sentence[6:13:])

# e - string to uppercase
print(upperCaseString)

# f - finding strings
if first == True:
    print(word1 + " Found!!")
else:
    print(word1 + " Not Found!!")

if second == True:
    print(word2 + " Found!!")
else:
    print(word2 + " Not Found!!")

if third == True:
    print(word3 + " Found!!")
else:
    print(word3 + " Not Found!!")

# g - unique characters from sentence
for key, value in freqChars.items():
    # if frequency of char is 1
    # then print it
    if value == 1:
        print(key)

# h - ask user char to print it's frequency from sentence
userCh = input("Enter character: ")
if userCh in freqChars:
    print(userCh + " "+str(freqChars[userCh]))
else:
    print(str(userCh)+" is not present in sentence")
