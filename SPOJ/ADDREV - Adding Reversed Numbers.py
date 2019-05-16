    t = int(input())
    for test in range(t):
        n, m = input().split()
        n=n[::-1]
        m=m[::-1]
        x = int(n)
        y = int(m)
        res = x+y
        res=str(res)
        res=res[::-1]
        res=int(res)
        print(str(res))
     
