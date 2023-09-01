# MOD = 1000000007


# def solve(N, K, L, R):
#     dp = [[0]*(R*N+1) for i in range(N+1)]
#     dp[0][0] = 1
#     for i in range(1, N+1):
#         for j in range(K, R*i+1):
#             for k in range(max(K-L*(i-1), 0), j):
#                 dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD
#     result = 0
#     for j in range(K, R*N+1):
#         result = (result + dp[N][j]) % MOD

#     return result


# N, K, L, R = map(int, input().split())
# print(solve(N, K, L, R))


def solve(N, K, L, R):
    mod = 1000000007
    dp = [[0 for j in range(200005)] for i in range(55)]
    dp[0][0] = 1
    for i in range(1, N+1):
        for j in range(K, 200005):
            for k in range(L, min(j, R)+1):
                dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % mod
    result = 0
    for j in range(K, 200005):
        result = (result + dp[N][j]) % mod
    return result


N, K, L, R = map(int, input().split())
print(solve(N, K, L, R))
