def sod(n):
    res=0
    while n:
        res +=((n%10)*(n%10))
        n//=10
    return res


x, y = map(int,input().split())
while x and y:
    x1=x
    y1=y
    ans_x=[x]
    ans_y=[y]
    while True:
        res=sod(x)
        if res in ans_x:
            break
        ans_x.append(res)
        x = res
    while True:
        res=sod(y)
        if res in ans_y:
            break
        ans_y.append(res)
        y = res
    n = len(ans_x)
    m = len(ans_y)
    res1=n+m+5
    for i in range(n):
        for j in range(m):
            if ans_x[i]==ans_y[j] and res1>i+j+2:
                res1=i+j+2
    if res1==m+n+5:
        print(str(x1)+" "+str(y1)+" 0")
    else:
        print(str(x1) + " " + str(y1) + " "+str(res1))
    x, y = map(int, input().split())

