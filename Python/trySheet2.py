Details = []
for _ in range(int(input())):
        name = input()
        score = float(input())
        
        Details.append([name, score])


Details.sort(key=lambda x: x[1])

min = Details[0][1]
secondLeastHolders = []
for i in range(1, len(Details)):
    if (Details[i][1] == min):
        continue
    else:
        secondLeastHolders.append(Details[i][0])
        if(i!=len(Details)-1 and (Details[i][1] == Details[i+1][1])):
            continue
        else:
            break

secondLeastHolders.sort()

for name in secondLeastHolders:
    print(name)
    
