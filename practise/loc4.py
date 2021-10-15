# num=input()
# if len(num)==1:
#     print("1")
# elif len(num)==2:
#     print("2")
# elif len(num)==3:
#     print("3")
# else:
#     print("More than 3 digits")




# import re
# def isValidVisaCardNo(string):
# 	regex = "^4[0-9]{12}(?:[0-9]{3})?$";
# 	p = re.compile(regex);
# 	if (string == ''):
# 		return False;
# 	m = re.match(p, string);
# 	if m is None:
# 		return False
# 	else:
# 		return True

# str1=input()
# print(isValidVisaCardNo(str1))


def res(input1,input2,input3):
    val=0;
    ind=input2%input1
    # l=len(input3)
    for i in range(0,input1):
        if i==ind-1:
            val=input3[i]
            break
    input3.remove(val);
    input3.insert(0,val);
    return input3







n=input()
val=int(n)
a=input()
k=int(a)
num = [int(x) for x in input().split()]

l=res(val,k,num)
for i in range(0,val):
    print(l[i],end=" ")