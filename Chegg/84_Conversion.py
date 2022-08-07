# Utility function which convert degree temperature to fahrenheit temperature
def celcius_to_fahren(C):
    return (9*C/5+32)


# list of temperatures in celcius
celcius=[40,30,20,12,34,56,78,23,54,32]
print(f"Temperatures in celcius: {celcius}")
# Conversion using map and function
fahren=list(map(celcius_to_fahren,celcius))
print(f"Tempratures in Fahrenheit: {fahren}")

expression= lambda C: (9*C/5+32)

# Conversion using map and function
fahren1=list(map(expression,celcius))
print(f"Tempratures in Fahrenheit: {fahren1}")
