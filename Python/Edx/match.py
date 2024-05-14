#getting a string input.

name = input("Enter your name? ")

match name:
    case "Musthak":
        print("Your name is "+name)
    case "Yasith":
        print("Your name is not Musthak")

    case _ :
        print("give a valid name")