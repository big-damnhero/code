g, t, a, d = map(int,input().split())
while g!=-1:
    res = 0
    res += (g*((t-1)*(t))//2)
    no_adv = g*a
    no_adv+= d
    ar = [(2**i) for i in range(35)]
    for i in range(35):
        if no_adv<=ar[i]:
            break
    res += (ar[i]-1)
    print(str(g)+"*"+str(a)+"/"+str(t)+"+"+str(d)+"="+str(res)+"+"+str(ar[i]-no_adv))
    g, t, a, d = map(int, input().split())
