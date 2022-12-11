
# Task 1:
# Check if value 200 exists in the following dictionary by using the
# values() method

# Given dictionary
sample_dict = {'a': 100, 'b': 200, 'c': 300}

# Here sample_dict.values() return the list of values present in the dictionary
# i.e.[100,200,300]
# Then if condition checks 200 is in this list or not

if 200 in sample_dict.values():
    print('True')
else:
    print('False')


# Task 1.2:
# Get the key of a minimum value from the following dictionary using the built-in min() function.

# Given dictionary
# from random import sample


# sample_dict = {'Physics': 82,
#                'Math': 65,
#                'History': 75
#                }

# # Find the min value keys in dictionary
# minValue = min(sample_dict.values())

# # Now get the list of keys(if more than one) of this minValue value from the sample_dict
# key = [key for key in sample_dict if sample_dict[key] == minValue]

# # print key
# print(key)


# # Task 1.3:
# # Change the value of a key in a nested dictionary , Change Brads salary to 8500 in the following dictionary


# # given dictionary
# sample_dict = {'emp1': {'name': 'John', 'salary': 7500},
#                'emp2': {'name': 'Emma', 'salary': 8000},
#                'emp3': {'name': 'Brad', 'salary': 500}
#                }

# # print Brads info before updating
# print(sample_dict['emp3'])

# # Update Brads salary
# sample_dict['emp3']['salary'] = 8500

# # print Brads updated info
# print(sample_dict['emp3'])
