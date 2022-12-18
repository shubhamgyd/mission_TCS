# Given food dictionary
food_dict = {
    'Jim': 'Tacos',
    'Bob': 'Burgers',
    'Janelle': '',
    'Lisa': 'Pizza',
    'Thomas': '',
    'Yolanda': '',
    'Finn': 'Bread',
}

# Iterate food dictionary and check which user have empty favorite food
# take the input of favorite food of this user
for key, value in food_dict.items():
    if len(value) == 0:
        food = input(f"What is {key}'s favorite food? ")
        food_dict[key] = food

# Keep track in the food and the nummber of occurance of this food
food_tracker = {}
print("Here are the favorite foods: ")
# Iterate food_dictionary
for key, value in food_dict.items():
    # Display favorite of current user
    print(f"{key}'s favorite food is {value}")
    # if food is already in tracker
    if value in food_tracker:
        # then increment the it's value by 1
        food_tracker[value] = food_tracker[value]+1
    # else put with the occurance of 1
    else:
        food_tracker[value] = 1

# Get popularFood
popularFood = ""
# Get occurance of popular food
cnt = 0
# Iterate food_tracker dictionary
for food, occurance in food_tracker.items():
    # if occurance is greater then previous
    if occurance > cnt:
        # update popular food
        cnt = occurance
        popularFood = food
# Display popular food
print(f'The most popular food is {popularFood}')
