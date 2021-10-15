# mod , maxn , cur , ans , r = 998244353, 1000005, 10, 0 , 0
# dp, x , a = [0] * maxn, [0] * maxn , [0] * 12 , 
# x[1] = 1
# dp[0] = 1
# for i in range(2 , maxn):
#     x[i] = mod - (mod// i) *x[mod % i] % mod;
# n , k = map(int,input().split())
# n = n // 2
# p = [0] * k
# for u in map(int,input().split()):
#     cur = min(cur , u)
#     p[r] = u
#     r += 1
# for i in range(k):
#     a[p[i] - cur] = 1
# for i in range (n * 10 + 1):
#     sm,  j = 0, 0 
#     while j < min(10 , i + 1):
#         sm += dp[i-j] * (j+1) * a[j+1] * n % mod
#         j+= 1
#     j = 1
#     while j < min(10 , i + 1):
#         sm -= dp[i-j+1] * (i-j+1) * a[j]
#         j+= 1
#     ans = (ans + dp[i] * dp[i]) %mod
#     dp[i+1] = sm * x[i+1] % mod
# print(ans % mod)


# n,k=map(int,input().split())
# if k>=n:print(0)
# else:
#     m=998244353
#     L=[1]
#     for i in range(1,n+1):
#         L.append((L[-1]*i)%m)
#     def comb(n,k):
#         return (L[n]*pow((L[n-k]*L[k]),m-2,m))%m
#     c=0
#     for i in range(n-k):
#         c+=((-1)**i*pow(n-k-i,n,m)*comb(n-k,n-k-i))%m
#     c*=2
#     c%=m
#     c*=comb(n,n-k)
#     c%=m
#     if k==0:print(L[n])
#     else:print(c)


def numDecodings(s: str) -> int:
	if len(s) == 0 or (len(s) == 1 and s[0] == '0'):
		return 0
	return numDecodingsHelper(s, len(s))


def numDecodingsHelper(s: str, n: int) -> int:
	if n == 0 or n == 1:
		return 1
	count = 0
	if s[n-1] > "0":
		count = numDecodingsHelper(s, n-1)
	if (s[n - 2] == '1'
		or (s[n - 2] == '2'
			and s[n - 1] < '7')):
		count += numDecodingsHelper(s, n - 2)
	return count



digits = str(input())
print(numDecodings(digits))
