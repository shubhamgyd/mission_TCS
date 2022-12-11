# import numpy
import numpy as np

a = np.array([[1, 2, 3, 4], [4, 5, 6, 7], [7, 8, 9, 10], [11, 12, 13, 14]])
b = np.random.randint(100, 200, (4, 6))
c = np.arange(0, 40).reshape(4, 10)
# concanate a,b,c with axis 1
# means join 2D arrays row wise
ans = np.concatenate((a, b, c), axis=1)
# print ans
print(ans)
