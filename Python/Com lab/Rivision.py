
int1 = int(input('Number1:'))
int2 = int(input('Number2:'))

Maxint = max(int1,int2)
Minint = min(int1,int2)


for factor in range(1,Minint+1):
    if Maxint % factor == 0 and Minint % factor == 0 :
        GCD = factor

print("GCD of",Minint,"&",Maxint,"=",GCD)











