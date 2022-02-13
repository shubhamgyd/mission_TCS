f=[0]*26
def checkPalindrome():
    c = 0
    for x in f:
        if (x % 2 == 1):
            c += 1
    return c <= 1

def getMaxSubstrings(s, k):
    for i in range(k):
        f[ord(s[i]) - 97] += 1
    a = 0
    if (checkPalindrome()):
        a += 1
    i = 0
    j = k
    while (j < len(s)):
        f[ord(s[i]) - 97] -= 1
        i += 1
        f[ord(s[j]) - 97] += 1
        j += 1
        if (checkPalindrome()):
            a += 1
    if(k==len(s)):
        return a
    return a + getMaxSubstrings(s,k+1)