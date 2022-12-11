
import math


def factor3n(n):
    # store all factors
    factors = []
    # start from 1
    num = 1
    # while number is less than or equal to the square root n
    while num <= math.sqrt(n):
        # if n is divisible by num
        if n % num == 0:
            # if both factors are same then append only once
            if n/num == num:
                factors.append(num)
            # else append both
            else:
                factors.append(num)
                factors.append(n//num)
        num = num+1
    # sort them in ascending order
    factors.sort()
    # Start from i=0
    for i in range(len(factors)):
        # start from j=0
        for j in range(len(factors)):
            # start from k=0
            for k in range(len(factors)):
                # if product of ith, jth, and kth factors is equal to n
                # then print it
                if factors[i]*factors[j]*factors[k] == n:
                    print(f'({factors[i]},{factors[j]},{factors[k]})')


if __name__ == '__main__':
    n = int(input())
    factor3n(n)
