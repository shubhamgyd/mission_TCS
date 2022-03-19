def minNum(samDaily, kellyDaily, difference):
    if samDaily >= kellyDaily:
        return -1
    
    samq = difference
    kellyq = 0
    day = 0
    
    while samq > kellyq:
        samq += samDaily
        kellyq += kellyDaily
        day += 1
    
    return day