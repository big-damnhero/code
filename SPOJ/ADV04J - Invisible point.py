t = int(input())
for test in range(t):
    n = int(input())
    res = 0
    while n:
        if n==2:
            res+=2
            break
        if n%2==0:
            n//=2
        else:
            n=n//2+1
        res+=1
    print(res)
