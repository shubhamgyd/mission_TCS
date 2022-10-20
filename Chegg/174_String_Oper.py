# Input senteces
sentence = input("Type the message to be shortened\n")

# convert into list of words
wordOfSentence = sentence.split(' ')

# to keep track of vowels
vowels = {'a': 1, 'e': 1, 'i': 1, 'o': 1, 'u': 1}

# count the removed vowels
vowelsRemoved = 0

# count the repeated adjacent same chars
repeatedRemovals = 0

# get updated sentence
ans = ""

# Iterate sentence
for word in wordOfSentence:
    # convert it into lower case
    word = word.lower()
    # get length of word
    n = len(word)
    i = 0
    # start iterating word
    while i < n:
        cnt = 0
        j = i
        # start iterating from the current char and count the adjacent occurance of current char
        while j < n and word[i] == word[j]:
            j = j+1
            cnt = cnt+1

        # if vowel is present at the starting of word then add it
        # else ignore it
        if i == 0 and word[i] in vowels:
            ans += word[i]

        # if ith char is vowel
        # get the count of removed vowels
        if i != 0 and word[i] in vowels:
            vowelsRemoved = vowelsRemoved+cnt

        # for other words add only one occurance of ith char
        if word[i] not in vowels:
            ans += word[i]

        # if ith char is occurs more than 1 adjacent times
        # removed only non vowels
        if cnt > 1 and word[i] not in vowels:
            repeatedRemovals = repeatedRemovals+1
        i = j
    # add space to the end of updated answer
    ans += " "

print("Algorithm 1")
print("Vowels removed: ", vowelsRemoved)
print("Repeats removed: ", repeatedRemovals)
print("Algorithm 1 message: ", ans)
print("Algorithm 1 characters saved: ", vowelsRemoved+repeatedRemovals)


# convert into lower case
newSentence = sentence.lower()

# count the unique characters from updated answer
# set
uniqueChars = set()
# Itearate ans
for i in range(len(newSentence)):
    # if space ignore it
    if newSentence[i] == ' ':
        continue
    # add into the set
    uniqueChars.add(newSentence[i])

uniqueLength = len(uniqueChars)

# get frequency of each char present
freq = {}
for i in range(len(newSentence)):
    # if space ignore it
    if newSentence[i] == ' ':
        pass
    else:
        # if ith char is already present in freq then increment it's frequency
        if newSentence[i] in freq:
            freq[newSentence[i]] = freq[newSentence[i]]+1
        # else put into freq with count 1
        else:
            freq[newSentence[i]] = 1

# get shortner message
shortnerMsg = ""
for key, value in freq.items():
    shortnerMsg += str(value)
    shortnerMsg += key

# get saved length
savedLength = len(sentence)-len(shortnerMsg)


print("\nAlgorithm 2")
print("Unique characters found: ", uniqueLength)
print("Algorithm 2 message: ", shortnerMsg)
print("Algorithm 2 characters saved: ", savedLength)
