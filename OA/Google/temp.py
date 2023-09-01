from collections import deque


class Solution:
    def dist(self, x, y, a, b):
        return ((x - a) ** 2 + (y - b) ** 2) ** 0.5

    def count_Points(self, dim1, dim2):
        x1, y1, r1 = dim1
        x2, y2, r2 = dim2
        x, y = -1, -1
        q = deque()
        q.append([x1, y1])
        Visited = set()
        Visited.add((x1, y1))
        while len(q) > 0:
            a, b = q.popleft()
            if self.dist(a, b, x1, y1) <= r1 and self.dist(a, b, x2, y2) <= r2:
                x, y = a, b
                break
            arr = [[a - 1, b], [a + 1, b], [a, b - 1], [a, b + 1]]
            for u, v in arr:
                if (
                    self.dist(u, v, x2, y2) < self.dist(a, b, x2, y2)
                    and self.dist(u, v, x1, y1) <= r1
                    and (u, v) not in Visited
                ):
                    Visited.add((u, v))
                    q.append([u, v])
        if x == -1 and y == -1:
            return 0
        q = deque()
        Visit = set()
        res = 1
        q.append([x, y])
        Visit.add((x, y))
        while len(q) > 0:
            a, b = q.popleft()
            arr = [[a - 1, b], [a + 1, b], [a, b - 1], [a, b + 1]]
            for u, v in arr:
                if (
                    self.dist(u, v, x1, y1) <= r1
                    and self.dist(u, v, x2, y2) <= r2
                    and (u, v) not in Visit
                ):
                    res += 1
                    Visit.add((u, v))
                    q.append([u, v])
        return res


S = Solution()
c1 = map(int, input().split(" "))
c2 = map(int, input().split(" "))

print(S.count_Points(c1, c2))
