# import function
from a3q2v1 import closest_to_zero

# testdriver program
if __name__ == '__main__':
    # input of three numbers
    a, b, c = map(int, input().split())
    # get closest number
    ans = closest_to_zero(a, b, c)
    # print answer
    print(ans)
