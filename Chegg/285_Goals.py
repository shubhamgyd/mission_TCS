# final minimum goal scored by country
goals_dict = {}
# goals_file = "goals.txt"
# Opening file1 to read
file = open('goals.txt', 'r')
# get the string
getCountryGoals = ""
# add all data into the string
for word in file:
    getCountryGoals += word

# split string into list
listOfcontryGoals = getCountryGoals.split(' ')
# iterate list of country and goals from index 0
i = 0
# store country and list of goals scored by country
countryGoals = {}
# unitl end of list
while i < len(listOfcontryGoals):
    # if country name hit
    if listOfcontryGoals[i].isalpha():
        # get country name
        country = listOfcontryGoals[i]
        # check country already avaialbe in countryGoals dictionary or not
        # if no then assign list in front of country name
        if country not in countryGoals:
            countryGoals[country] = []
        # iterate from next i
        j = i+1
        # until the end of list and every time check we didn't hit the country name
        # as soon as we hit the country name, break the loop
        while j < len(listOfcontryGoals) and not listOfcontryGoals[j].isalpha():
            # append goal into the list of country name by typecasting it
            countryGoals[country].append(int(listOfcontryGoals[j]))
            j = j+1
        # update index i
        i = j

# Iterate countryGoals dictionary
# and get the minimum goals scored by each country
for key, value in countryGoals.items():
    goals_dict[key] = min(value)
# print goals dict
print(goals_dict)
