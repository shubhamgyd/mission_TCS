# Dictionary of person 1
person1 = {
    "first_name": "John",
    "last_name": "Doe",
    "age": 30,
    "city": "New York"
}

# Dictionary of person 2
person2 = {
    "first_name": "Jane",
    "last_name": "Doe",
    "age": 28,
    "city": "San Francisco"
}

# List which includes person1 and person2
people = [person1, person2]

# Print information about each person
for person in people:
    print("First Name:", person["first_name"])
    print("Last Name:", person["last_name"])
    print("Age:", person["age"])
    print("City:", person["city"])
    print("")
