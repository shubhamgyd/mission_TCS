# from typing_extensions import runtime
# import check

# runtimes=("1","log n", "sqrt n","n","n**2","n**3","2**n")

# def f1(L):
#     ans=0
#     while L!=[]:
#         ans=ans+L[0]
#         L=L[1:]
#     return ans>100

# r1="n**2"
# e1="""Because as we know L is a 2D list so it will iterate until it not get any empty list. Basically
#       This function add the first value of every row"""
# check.expect("f1",r1 in runtime,True)


def f2(L):
    if len(L)==0:
        print("Len : "+str(len(L)))
        return ""
    else:
        return f2(L[1:])+f2(L[:-1]);



L=[1,2,3,4,5,6,7]
print(f2(L))