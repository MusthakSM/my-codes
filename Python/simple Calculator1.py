#TODO: Write the functions for arithmatic operations here
#These functions should cover Task 2

def calculation(number1, number2, operation):
    if operation == "^":
        print(number1**number2)
    else:
        if operation == "/" and number2 == 0:
            print("float division by zero")
            print(str(number1)+" / "+str(number2)+" = "+"None")
        else:
            Result = eval(str(number1)+operation+str(number2))
            print(str(number1)+" "+operation+" "+str(number2)+" =",Result)

#-------------------------------------
# TODO: Write the select_op(choice) function here
#This function sould cover Task 1 (Section 2) and Task 3

def select_op(choice):
    if choice == "#":
        return -1
    elif choice == "$":
        print("Reset")
    else:
        while True:
            firstNumber = input("Enter first number: ")
            if "$" in firstNumber:
                break
            secondNumber = input("Enter second number: ")
            if "$" in secondNumber:
                break
            break
                
            #except:
                #print("Not a valid number,please enter again")

        if "$" in str(firstNumber) or "$" in str(secondNumber):
            None
        elif "#"==firstNumber or "#"== secondNumber:
            return -1
        else:
            number1 = float(firstNumber)
            number2 = float(secondNumber)
            calculation(number1, number2, choice )






#End the select_op(choice) function here
#-------------------------------------
#This is the main loop. It covers Task 1 (Section 1)
#YOU DO NOT NEED TO CHANGE ANYTHING BELOW THIS LINE

while True:
    print("Select operation.")
    print("1.Add      : + ")
    print("2.Subtract : - ")
    print("3.Multiply : * ")
    print("4.Divide   : / ")
    print("5.Power    : ^ ")
    print("6.Remainder: % ")
    print("7.Terminate: # ")
    print("8.Reset    : $ ")
    

    # take input from the user
    choice = input("Enter choice(+,-,*,/,^,%,#,$): ")
    print(choice)
    if(select_op(choice) == -1):
        #program ends here
        print("Done. Terminating")
        exit()