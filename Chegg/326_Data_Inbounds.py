# Input of list
data = list(map(int, input().split(' ')))

# Get the Sum along with the Max and Min element
sumOfElements = 0
mx = 0
mn = float('inf')
for num in data:
    # add into the sum
    sumOfElements += num

    # Update max and min element
    mx = max(mx, num)
    mn = min(mn, num)


# Print all required values
print(f'Sum: {sumOfElements}')
print(f'Max: {mx}')
print(f'Min: {mn}')
