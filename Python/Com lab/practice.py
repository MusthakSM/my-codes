
List = ["Musthak","Samsudeen","Semmonodai",7413,3404,8820,9.81,"red"]

# List length
print(len(List))

# Print List
print(List)

# Access List Items (Negative Indexing)
print(List[-2])
print(List[-1])
print(List[-6])

# Range of indices
MyList = List[0:3]
Numbers = List[3:7]
print(MyList,Numbers)

# Check if item exists.
if "red" in List:
    print("red is in the list")
else:
    print("red is not in the list")

# Change item value
List[1] = "Audi"
print(List)

# Change a range of item values
List[0:3]=["Audi","Lamborgini","Yamaha"]
print(List)

# List.insert
List.insert(7,"Rolls Royce")
print(List)

# List.append
List.append("Duke")
print(List)

# List addition
print(MyList+Numbers)

# List.remove       IT IS SAME AS DELETE
List.remove("Duke")
print(List)

del List[8]
print(List)

# List pop
y = List.pop()
print(List)

print(y)
