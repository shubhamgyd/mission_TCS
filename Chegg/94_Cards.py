# t test cases
t=int(input())
for i in range(t):
    # n cards of Ankita
    n=int(input())
    # input of n cards
    arr1=list(map(int, input().split()))[:n]
    # m cards of Biswas
    m=int(input())
    # input of m cards
    arr2=list(map(int, input().split()))[:m]
    # sort Ankita's cards in ascending order
    arr1.sort()
    # sort Biswas's cards in ascending order
    arr2.sort()

    # If Ankita start first
    # Check if Ankita have maximum card or not
    # if yes then ankita win
    if arr1[-1]>=arr2[-1]:
        print("Ankita")
    # else Biswas win
    else:
        print("Biswas")
    
    # If Biswas start first
    # Check biswas have maximum card or not
    # if yes then Biswas can win
    if arr2[-1]>=arr1[-1]:
        print("Biswas")
    # else Ankita can Win
    else:
        print("Ankita")

# 1
# 4
# 10 5 13 8
# 3
# 6 15 6