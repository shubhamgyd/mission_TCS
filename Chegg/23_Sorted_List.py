
# Function which print the occurnace of each character from the list
def main():
    # Character list 
    characterList=[ 'l', 'z', 'b', 'y', 's', 'k' ,'f', 'u', 's','i', 't', 'n', 'k', 'b', 'm', 'h', 'h', 'e', 'e', 'h', 'r' ,'g', 'a', 'c', 'l', 'p', 'g', 'j', 's' 'c' ,'d', 'y', 'u', 'o', 'j', 'y', 'g', 'q', 'f', 'o', 'd', 'l', 'o' ,'j', 'c', 'k', 'v', 'k', 'p', 'z', 't', 'm','c','s', 'q', 'e', 'u', 'r', 's', 'r', 'h', 'c', 'h', 'c', 'm', 'd', 's', 'q', 'j', 'r', 'w', 'k', 'u', 'y', 'r', 'g', 'i', 'x', 't', 'w', 'm', 'l', 'x', 'c', 'o', 'x', 'v', 'k', 'g', 'k', 'n', 'd', 'd' ,'y', 'z', 'q', 'z', 'i', 'g', 'x', 'j', 'o']
    # for loop will print the charater from a to z 
    # also parallely we are counting the occurance in the list
    # chr will typecast from ascii value to the character
    print('\n')
    for i in range(97,123):
        print(characterList.count(chr(i)),chr(i), end="  ")
    print('\n')

main()