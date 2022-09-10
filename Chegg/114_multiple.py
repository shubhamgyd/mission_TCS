print("\n")
# alien_color = "green"
# print("alien_color: " + alien_color)
# if alien_color == "green":
#     print("Player just earned 5 points")

# person age input
personAge = int(input("Enter Person's Age: "))
# if age is less than 2
if personAge < 2:
    print("Person is baby")
# if age>=2 and age<4
elif personAge >= 2 and personAge < 4:
    print("Person is toddler")
# if age>=4 and age<13
elif personAge >= 4 and personAge < 13:
    print("Person is kid")
# if age>=13 and age<20
elif personAge >= 13 and personAge < 20:
    print("Person is teenager")
# if age>=20 and age<65
elif personAge >= 20 and personAge < 65:
    print("Person is adult")
# if age>=65
else:
    print("Person is older")
