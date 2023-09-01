words_list = ['apple', 'banana', 'mango', 'kiwi', 'grape', 'fig', 'watermelon']

filtered_words = []

for word in words_list:
    if len(word) <= 5:
        if word.startswith('f'):
            filtered_words.append(word.upper())
        else:
            filtered_words.append(word)

print(filtered_words)
