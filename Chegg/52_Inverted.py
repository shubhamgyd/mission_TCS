# Utility function which delete the banned keys from the word_count_dictionary
def inverted_word_count(word_count_dict,banned):
    # dictionary whih will modify the list according to the need
    inverted_word_cnt={}

    # Iterating the word dictionary
    for key,value in word_count_dict.items():
        # If key if not found in banned list
        if key not in banned:

            # if we have not created key in new word count dictionary
            if value not in inverted_word_cnt.keys():
                # Generate new key along with list in new word count dictionary
                inverted_word_cnt[value]=[]

                # append the key as a value in new word count dictionary with value as a key
                inverted_word_cnt[value].append(key)

            # if we have already created key
            else:
                # just append the key
                inverted_word_cnt[value].append(key)
    
    # Sort the list of values in alphabetically order
    for items in inverted_word_cnt.values():
        items.sort()
    
    # return dictionary
    return inverted_word_cnt





# test dictionary
test_dict={'a':20,'west':10,'blotto':1,'bingo':1,'x':5,'member':1}

# banned list
banned=["member","west"]

# result
inverse=inverted_word_count(test_dict,banned)



# Printing key and values
for count in sorted(inverse.keys()):
    print('{}: {}'.format(count,inverse[count]))

