# Read file
fp = open('simple.txt')
text = fp.read()
# Split it into list of strings
tokens = text.split()
# Dictionary
counting = {}
# Iterate lines
for token in tokens:
    # if first letter of word is found in dictionary then increment it's count
    if token[0] in counting:
        counting[token[0]] = counting[token[0]]+1
    # else put into dictionary with count 1
    else:
        counting[token[0]] = 1

# Print dictionary
print(counting)
# Close file
fp.close()
