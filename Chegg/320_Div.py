user_input = input()
while user_input != 'end':
    try:
        # Possible ValueError
        divisor = int(user_input)
        # Possible ZeroDivisionError
        print(60//divisor)  # Truncates to an integer
    except ValueError:
        print('v')
    except ZeroDivisionError:
        print('z')
    user_input = input()
print('OK')
