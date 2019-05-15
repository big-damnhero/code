def f(cnt,kg,ar,n,k,dp):
    if cnt > n or kg > k:
        return 10000000
    if k==kg:
        return 0
    if dp[cnt][kg]!=10000000:
        return  dp[cnt][kg]
    else:
        for i in range(1,k+1):
            if ar[i]!=-1:
                dp[cnt][kg]=min(dp[cnt][kg],f(cnt+1,kg+i,ar,n,k,dp)+ar[i])
        return dp[cnt][kg]
 
 
t = int(input())
for test in range(t):
    n, k = map(int,input().split())
    cost = list(map(int,input().split()))
    dp = [ [10000000 for i in range(k+1)] for j in range(n+1)]
    ar = [0]*(k+1)
    for i in range(k):
        ar[i+1]=cost[i]
    res = f(0,0,ar,n,k,dp)
    if res >=10000000:
        print(-1)
    else:
        print(res) 
