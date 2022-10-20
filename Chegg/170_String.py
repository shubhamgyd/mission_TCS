# get input of total input string
n = int(input("Enter number: "))
# get n statement
for i in range(n):
    # input statement
    statement = input("Enter statement: ")
    # get total characters
    chars = 0
    # get total white spaces
    whiteSpace = 0
    # get frequencey of c,k,g,m,d,t (case sensitive)
    c = k = g = m = d = t = 0
    # get frequency of vowels a,e,i,o,u (case seneitive)
    a = e = i = o = u = 0
    # Iterate statement
    for ch in statement:
        # if current char is white space
        if ch == ' ':
            whiteSpace = whiteSpace+1
        # else
        else:
            # increment chars
            chars = chars+1
            # if char is a or A
            if ch == 'a' or ch == 'A':
                a = a+1
            # if char is e or E
            elif ch == 'e' or ch == 'E':
                e = e+1
            elif ch == 'i' or ch == 'I':
                i = i+1
            # if char is o or O
            elif ch == 'o' or ch == 'O':
                o = o+1
            # if char is u or U
            elif ch == 'u' or ch == 'U':
                u = u+1
            # if char is c or C
            elif ch == 'c' or ch == 'C':
                c = c+1
            # if char is k or K
            elif ch == 'k' or ch == 'K':
                k = k+1
            # if char is g or G
            elif ch == 'g' or ch == 'G':
                g = g+1
            # if char is m or M
            elif ch == 'm' or ch == 'M':
                m = m+1
            # if char is d or D
            elif ch == 'd' or ch == 'D':
                d = d+1
            # if char t or T
            elif ch == 't' or ch == 'T':
                t = t+1
    # print total chars
    print("Total number of characters in the statement = ", chars)
    # print total whiteSpaces
    print("Total number of space characters in the statement = ", whiteSpace)
    # print frequency of each consonant like c,k,g,m,d,t
    print("Frequency of occurrence of each consonant: c, k, g, m, d, t:")
    # print freq of c
    print("c: ", c)
    # print freq of k
    print("k: ", k)
    # print freq of g
    print("g: ", g)
    # print freq of m
    print("m: ", m)
    # print freq of d
    print("d: ", d)
    # print freq of t
    print("t: ", t)

    # print frequency of each vowel
    print("Frequency of occurrence of each vowel: a, e, i, o, u:")
    # print freq of a
    print("a: ", a)
    # print freq of e
    print("e: ", e)
    # print freq of i
    print("i: ", i)
    # print freq of o
    print("o: ", o)
    # print freq of u
    print("u: ", u)
    print("\n")
