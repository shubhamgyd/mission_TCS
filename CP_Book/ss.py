

def getMaxOccuringChar(input1):
    count = [0] * 256
    max = -1
    c = ""
    for i in input1:
        count[ord(i)] += 1

    l=[]
    for i in count:
        if i!=0:
            l.append(i)

    l.sort();
    if l[len(l)-1]==l[len(l)-2]:
        return "0";
    
    for i in str:
        if max < count[ord(i)]:
            max = count[ord(i)]
            c = i
    return c


str = "aaabbbccc"
print("Max occurring character is " + getMaxOccuringChar(str))
