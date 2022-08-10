import numpy as np
import sys
arr_1=([1,4,9,16], [25,39,25,2,3], [1,54,96,236,458])
arr=np.array(arr_1) 
arr_2= np.array([1,23,4545,3,5,5648])
for array in arr.flat: 
    print (array)
print(arr_2.argmax(axis=0), arr.argsort())
print(arr.ndim, arr_2.nbytes, arr_2.reshape(3,2))
print(arr_2.argmin(axis=1))