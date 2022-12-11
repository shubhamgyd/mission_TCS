# Read string from user
string = input("Enter string: ")
# dictionary which stores the frequency of instances of characters
freqOfChars = {}
# Iterate string
for ch in string:
    # ignore space
    if ch == ' ':
        continue
    # ch already in dictionary then increment it's count
    if ch in freqOfChars:
        freqOfChars[ch] = freqOfChars[ch]+1
    # else put into dictionary with frequency 1
    else:
        freqOfChars[ch] = 1

# print(chars with frequency)
print(freqOfChars)
