def counting(fruits):
    # set to store the unique ways
    ways = set()
    # Iterate string to get every substring and append into the set
    for i in range(len(fruits)):
        # to get substring
        way = ""
        for j in range(i, len(fruits)):
            # append char to the stirng
            way = way+fruits[j]
            # add string into the list
            ways.add(way)
    # return length of unique data set
    return len(ways)


# given string
fruits = "ababa"
# print unique ways
print(counting(fruits))
