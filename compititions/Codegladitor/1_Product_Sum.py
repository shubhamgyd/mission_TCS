e = 100001
dp, MOD = [1] * (3 * e), 998244353

for i in range(2, e):
    dp[i] = dp[i - 1] * i % MOD
    dp[i + e] = MOD - MOD // i * dp[MOD % i + e] % MOD
    dp[i + (2 * e)] = dp[i - 1 + (2 * e)] * dp[i + e] % MOD

C = lambda x, y: dp[x] * dp[y + (2 * e)] * dp[x - y + (2 * e)] % MOD

for tc in range(int(input())):
    n, t = int(input()), 0
    c0 = tuple(map(int, input().split())).count(0)
    for i in range(n - c0 + 1):
        if not (n - i < 0 or c0 > n - i):
            t += i * C(n - i, c0) % MOD
    print(t * (c0 + 1) * dp[n - c0] * dp[c0] % MOD)