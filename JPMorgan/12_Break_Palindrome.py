def Convert(string):
    list1=[]
    list1[:0]=string
    return list1

def plaindrome(s, l):
    if s[0] != "a":
        s[0] = "a" 
        return s
        
    if l % 2 != 0 :
        if s[l//2] == "a" or s[l//2] == "b":
            s = "impossible"
            return s
            
        else:
            s[l//2] = "b"
            return s
    if l % 2 == 0:
        if s[l//2] == "a" and s[(l//2)-1] == "a":
            s = "impossible"
            return s
        else:
            s[(l//2)-1] = "a"
            return s    
            
    else:
        s = "impossible"
        return s

s = "zbabz"
s = Convert(s)
print(s)
l = len(s)
r = print(plaindrome(s, l))