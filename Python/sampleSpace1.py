'''
def number_checking():
    num = input("Enter the number :")

    while True:
        try:
            if int(num) == 5:
                print("Number is correct...")
                return 1
                
            else:
                print("You have given a wrong number...\nunathorized reach...")
                return 0
            
        except: 
            for turns in range(3):
                print("You have not typed a number... Kindly try again....")
                num = input("Enter the number :")
            print("Security Breach.... Turn on security protocols...")
            return 0
print(number_checking()) '''


# IN ABOVE CODE WE HAVE NOT USED A break STATEMENT. FOR A WHILE TRUE LOOP IN A PYTHON FUNCTION, WE CAN EITHER USE
#....A break OR A return TO BREAK THE LOOP. DIFFERENCE IS break WILL BREAK THE LOOP AS WELL AS DISPLAY A 'NONE' WHEN
#.. WE PRINT THE PARTICULAR FUNCTION. ON THE OTHER HAND return WILL BREAK THE LOOP BY DISPLAYING THE PARTICULAR
#.. STATEMENT WHICH WAS IN UNDER THE return STATEMENT....



from numpy import binary_repr



for i in range(10,0,-1):
    print(i)