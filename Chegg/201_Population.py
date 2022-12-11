# For Million
M = 1000000.0

# For thousand
k = 1000.0

# For any other value
constVal = 'MISSING_DATA'

# Function which clean the dataset


def clean_population_data(data):
    # Iterate data
    for j in range(len(data)):
        # Get the ith country information
        countryData = data[j]
        # store update list
        newList = []
        # Append countryName
        newList.append(countryData[0])
        # Iterate into population
        for i in range(1, len(countryData)):
            # if any non-valide entry then put MISSING_DATA as a constant
            if countryData[i][-1] != 'M' and countryData[i][-1] != 'k':
                newList.append(constVal)
            # else find the appropriate population
            else:
                population = 0.0
                population = countryData[i].rstrip(countryData[i][-1])
                population = float(population)
                # if M then multiply by Million
                if countryData[i][-1] == 'M':
                    population = population*M
                # if k then multiply by Thousand
                if countryData[i][-1] == 'k':
                    population = population*k
                # store value into list
                newList.append(population)
        # Update the original list by actual population with validations
        for i in range(len(newList)):
            data[j][i] = newList[i]


# Given data set
small_sample_data = [['France', '29M', '29.1M', '29.2M', '29.3m'],
                     ['Mauritius', '59k', '60.7k', '62.4k', '64.2k']]

# Function call to clean data set
clean_population_data(small_sample_data)
# Print 0th index data
print(small_sample_data[0])
# Print 1th index data
print(small_sample_data[1])
