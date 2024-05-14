# Exercise 01

from random import randint
from os import remove, rename

# Exercise 02

def getUserScore(userName):

    try:
        file_1 = open('userScores.txt','r')

        for line in file_1:
            [x,y] = line.split(', ')

            if x == userName :
                file_1.close()
                return y
            
        
        file_1.close()
        return "-1"

    except IOError:
        print("IOError: to handle the 'File not found' error.")
        file_1 = open('userScores.txt','w')
        file_1.close()
        return "-1"

'''****IN A FUNCTION return SHOULD BECOME AFTER CLOSE THE FILE'''
# Exercise 03

def updateUserPoints(newUser, userName, score):

    if newUser:
        file_1 = open('userScores.txt','a')
        file_1.write("\n" + userName + ", " + "score")
        file_1.close()

    else:
        file_1 = open('userScores.txt','r')
        file_2 = open('userScores.tmp','w')

    for data in file_1:
        [a,b] = data.split(', ')

        if a == userName :
            b = score           # Changing to new score...

        file_2.write(a + ', ' + b + '\n')

    file_1.close()
    file_2.close()

    remove("userScores.txt")
    rename("userScores.tmp","userScores.txt")

# Exercise 4: ****Generating the Questions..

def generateQuestions():
    operandList = [0, 0, 0, 0, 0]
    operatorList = ['', '', '', '']
    operatorDict = {1:'+', 2:'-', 3:'*', 4:'**'}

    for index in range(len(operandList)):
        operandList[index] = randint(1, 9)

             ## Hardest part..... Updating operator list with mathematical symbols...

    ''' count = 0 '''
    for Index in range(len(operatorList)):     
        '''if operatorList[Index] == "**":
            count +=1
        if count > 1 : 
            continue'''
        if Index > 0 and operatorList[Index-1]!='**':
            operator = operatorDict[randint(1,4)]
        else:
            operator = operatorDict[randint(1,3)]

        operatorList[Index] = operator

    questionString = str(operandList[0])
    
    for index in range(1, 5):
        questionString += operatorList[index-1] + str(operandList[index])

         # EVALUATING THE RESULT...

    result = eval(questionString)

         # INTERACTING WITH USER...
    questionString = questionString.replace('**', '^')
    print('\n' + questionString)

 
    userAnswer = input("Enter your answer :")
    while True:
        try:
            if int(userAnswer) == result :
                print("Genius.. You got the right answer..")
                return 1
            else:
                print("Hmmm!.. Your answer is wrong. Correct answer is,", result)
                return 0
        except Exception as e:
            print("You have not typed a number. Kindly try again...")
            userAnswer = input("Enter your answer :")


        
        


        
        
            
            

        

            

        

        
    

