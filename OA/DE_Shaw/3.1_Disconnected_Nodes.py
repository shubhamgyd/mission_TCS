# https://leetcode.com/discuss/interview-question/2933597/D.E.-Shaw-or-Off-Campus-or-2023-Batch-or-Question-3-and-solution

dp, nodes = list(range(g_nodes)), [1]*g_nodes


def find(x):
    if dp[x] != x:
        dp[x] = find(dp[x])
    return dp[x]


for i, j in zip(g_from, g_to):
    i, j = find(i-1), find(j-1)
    if i != j:
        nodes[i] += nodes[j]
        dp[j] = i

disconnect = set(map(find, disconnected_nodes))
disconnect_within = sum(nodes[i]*(nodes[i]-1) for i in disconnect)//2
free = sum(map(nodes.__getitem__, set(map(find, dp))-disconnect))

return free*(free-1)//2 + free*max(map(nodes.__getitem__, disconnect)) + disconnect_within - g_edges
