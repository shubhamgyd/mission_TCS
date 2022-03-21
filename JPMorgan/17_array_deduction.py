import heapq
def reduce_sum(lst):
    heapq.heapify(lst)
    s = 0
    while len(lst) > 1:
        first = heapq.heappop(lst)
        second = heapq.heappop(lst)
        s += first + second
        heapq.heappush(lst, first + second)
    return s
print(reduce_sum([1, 2, 3]))