def remove_vowels_and_double_consonants(phrase):
    # vowels
    vowels = set('aeiouyAEIOUY')
    # consonanst
    double_consonants = set('bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ')
    # counts the vowels
    counts = {'a': 0, 'e': 0, 'i': 0, 'o': 0, 'u': 0, 'y': 0}
    # get output
    output = ""
    i = 0
    # iterate given string
    while i < len(phrase):
        # if ith char is vowel
        # increment it's count
        if phrase[i] in vowels:
            counts[phrase[i].lower()] += 1
            i += 1
        # if consonents get double
        elif i < len(phrase) - 1 and phrase[i] == phrase[i + 1] and phrase[i] in double_consonants:
            output += phrase[i]
            i += 2
        # else get chars as it is in the output
        else:
            output += phrase[i]
            i += 1
    # return the output and counts of vowels removed
    return (output, counts)


# Example usage
phrase = "Marry had a Little Lamb."
# get result by removing the phrase
result, counts = remove_vowels_and_double_consonants(phrase)
# print result
print(result)
# print each removed vowels with its count
for vowel, count in counts.items():
    if count != 0:
        print(vowel.upper(), count)
