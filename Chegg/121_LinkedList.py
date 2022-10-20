MAX_VAL = 1000000000


def Closestpower(arr, n, x):
    pow_l, pow_r = 0, 0
    l, r, diff = 0, n-1, MAX_VAL
    while r > l:
        if abs((arr[r] - arr[l]) - x) == 0:
            return arr[r]+arr[l]
        if abs((arr[r] - arr[l]) - x) < diff:
            pow_l = l
            pow_r = r
            diff = abs((arr[r] - arr[l]) - x)
        if (arr[r] - arr[l]) > x:
            l += 1
        else:
            r -= 1
    return (arr[pow_l]+arr[pow_r])
