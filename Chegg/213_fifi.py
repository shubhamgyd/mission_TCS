def fifi(n):
    '''(int)->int'''
    som = 0
    for i in range(n):
        for j in range(n):
            som += 1
    return som


print(fifi(5))
