t = int(input())
for test in range(t):
    m = input()
    ar = input().split()
    x = ar[0].find('machula')
    y = ar[2].find('machula')
    z = ar[4].find('machula')
    if x!=-1:
        x = int(ar[4])-int(ar[2])
        print(str(x)+" + "+ar[2]+" = "+ar[4])
    if y!=-1:
        y = int(ar[4])-int(ar[0])
        print(ar[0]+" + "+str(y)+" = "+ar[4])
    if z!=-1:
        z = int(ar[0])+int(ar[2])
        print(ar[0]+" + "+ar[2]+" = "+str(z))
