
size = int(input("Enter the size of the list: "))

container = []
for i in range(size):
    number = int(input("Enter the number: "))
    container.append(number)
    

for i in range(size):
    flag = False
    for j in range(0, size-i-1):
        if(container[j]>container[j+1]):
            temp = container[j]
            container[j] = container[j+1]
            container[j+1] = temp
            flag = True
                
    if not flag:
        break


print("Sorted order is: ")
for i in range(size):
    print(container[i], end=" ")