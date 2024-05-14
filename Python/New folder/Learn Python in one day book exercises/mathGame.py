        # Exercise 5

try:
    import sys
    sys.path.append('C:\\Users\\MUSTHAK\\Desktop\\VSCode\\New folder\\Learn Python in one day book exercises')
    import myPythonFunctions as func

    userName = input("Please enter your name :")

    userScore =  int(func.getUserScore(userName))
    if userScore == -1:
        newUser = True
        userScore = 0
    else:
        newUser = False

    userChoice = 0
    while userChoice != '-1':
        userScore += func.generateQuestions()
        print("Your current score is", userScore)

        userChoice = input("Press Enter to Continue or '-1' to exit.:")

    func.updateUserPoints(newUser, userName, str(userScore))

except Exception as e:
    print("An error has occured, and the program will exit...")
    




    


