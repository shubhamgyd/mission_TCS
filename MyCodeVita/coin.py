
def main():
    n = int(input())
    for x in range(0, n):
        inp = input()
        inp = inp.split(' ')
        inp = [int(a) for a in inp]
        s = inp[0]
        m = inp[1]
        l = [0 for i in range(0, s + m + 1)]
        l[0] = 1
        for i in range(0, s + 1):
            for j in range(1, m + 1):
                l[i + j] += l[i]
        print(l[s])



main()