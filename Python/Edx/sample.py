

greeting = input("Greeting: ")

if (greeting[0:5].lower() == "hello"):
    print("$0")
elif(greeting[0].lower() == 'h'):
    print("$20")
else:
    print("$100")