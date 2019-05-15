    import math
     
    t = int(input())
    for test in range(t):
        n = int(input())
        c = n
        no_of_zero = 0
        while n % 10 == 0:
            n = n // 10
            no_of_zero+=1
        x = n%10
        if x < 5 :
            x1 = c - (x*(10**no_of_zero))
            x2 = c + ((5-x)*(10**no_of_zero))
        elif x > 5 :
            x1 = c - ((x -5) * (10 ** no_of_zero))
            x2 = c + ((10 - x) * (10 ** no_of_zero))
        else :
            x1 = c - ((5) * (10 ** no_of_zero))
            x2 = c + ((5) * (10 ** no_of_zero))
        temp = 0
        if math.ceil(0.95*c)<=x1<=math.floor(1.05*c) or math.ceil(0.95*c)<=x2<=math.floor(1.05*c):
            temp = 1
        if temp:
            print("absurd")
        else:
            print("not absurd")
     
