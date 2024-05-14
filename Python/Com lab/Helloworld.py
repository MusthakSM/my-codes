# Displaying Fibonacci series upto 10 terms....

StartigElementsList = [0,1]
FibonacciList = []
for index, char in enumerate(StartigElementsList):
    if index == 0 : 
        FibonacciList.append(char)

    if index > 0 :
        newElement = StartigElementsList[index]+StartigElementsList[index-1]
        StartigElementsList.append(newElement)
        FibonacciList.append(char)

    if len(FibonacciList) == 10:
        break

for elements in FibonacciList:
    print(elements)
    

    
  
  