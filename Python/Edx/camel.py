
input_string = input("camelCase: ")

print("snake_case", end="")

for index,Char in enumerate(input_string) :

    if (index != 0):
        if(Char ==  Char.upper()):
            Char = "_"+ Char.lower()
        else:
            Char = Char.lower()
    else:
        Char.lower()

    print(Char, end="")

print()
