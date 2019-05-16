t = int(input())
for test in range(t):
    ar = list(map(int,input().split()))
    ar2 = list(map(int,input().split()))
    n = ar[0]
    m = ar2[0]
    ar[0:n]=sorted(ar[1:n+1])
    ar2[0:m]=sorted(ar2[1:m+1])
    i=0
    j=0
    ans = 1000000000
    while i<n and j<m:
        ans=min(ans,abs(ar[i]-ar2[j]))
        if ar[i] > ar2[j]:
            j+=1
        else:
            i+=1
    print(ans)
