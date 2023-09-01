# Animal 1
dog = {
    "kind": "Canine",
    "owner": "John"
}

# Animal 2
cat = {
    "kind": "Feline",
    "owner": "Jane"
}

# Animal 3
bird = {
    "kind": "Avian",
    "owner": "Jim"
}

# Add all animals into pets list
pets = [dog, cat, bird]

# print information about each animal
for pet in pets:
    print("Kind:", pet["kind"])
    print("Owner:", pet["owner"])
    print("")
