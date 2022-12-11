from collections import defaultdict


def getMex(a, i, j):
    mex = 0
    seen = set()
    for k in range(i, j + 1):
        el = a[k]
        seen.add(el)

        while mex in seen:
            mex += 1

    return mex


def mexReduction(a):
    n = len(a)
    ct = defaultdict(int)
    for el in a:
        ct[el] += 1

    ret = []

    i = 0
    while i < n:
        print(i)
        curMex = 0
        seen = set()
        while curMex != mex:
            el = a[i]
            ct[el] -= 1
            seen.add(el)

            while curMex in seen:
                curMex += 1
            i += 1
        ret.append(curMex)
        if curMex == 0:
            i += 1
        nextMex = 0
        while ct[nextMex] > 0:
            nextMex += 1
        mex = nextMex
    return ret
