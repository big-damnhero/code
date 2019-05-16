t = int(input())
for test in range(t):
    ar = list(map(int,input().split()))
    n = ar[0]
    ar[0:n]=ar[1:n+1]
    pre = [0]*(n)
    pre[0]=ar[0]
    for i in range(1,n):
        pre[i]=pre[i-1]+ar[i]
    res = min(pre[n-1]-ar[0],pre[n-1]-ar[n-1])
    for i in range(1,n-1):
        res=min(res,min(2*pre[i-1]+pre[n-1]-pre[i],pre[i-1]+2*pre[n-1]-2*pre[i]))
    print(res)
