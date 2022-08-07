def fulton():
    weight=int(input("Enter weight in kilogram: "))
    svl=int(input("Enter SVL in centimeters: "))
    # K=w/svl*10^3
    K=(weight*(10**3))//svl
    return K


if __name__ == '__main__':
    ans=fulton()
    print(f'The Fulton\'s k for the alligator is {ans}')
    