noflower = int(input())
flowpos = []
for i in range(noflower):
    n = int(input())
    flowpos.append(n)
reqflower = int(input())
for i in range(len(flowpos)):
    flowpos[i] = abs(0-flowpos[i])
flowpos.sort()
ans = 0
for i in range(reqflower):
    ans+=flowpos[i]
print(ans)