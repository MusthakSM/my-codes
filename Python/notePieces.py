# GENERATE EVEN NUMBERS BETWEEN 4 AND 30 USING FUNCTIONS...
'''
def even_numbers(a, b):
    list = []
    for num in range(a, b):
        if num % 2 == 0:
            list.append(num)

    return list



print(even_numbers(4,30))
'''

# FIND THE GREATEST NUMBER IN A GIVEN LIST...
'''
x = [4, 6, 8, 24, 12, 50]

def great_num(List):
    great = 0
    for num in List:
        if num > great:
            great = num
        else:
            pass
    return great

print(great_num(x)) 
                    '''

# CALLING A FUNCTION USING A DIFFERENT CALL NAME...

'''def display_student(name, age):
    print(name, age)

# TO CALL THIS FUNCTION USING A DIFFERENT CALL WHICH IS SIMILAR TO display_student("Emma", 23), WE HAVE TO ASSIGN THE FUNCTION TO A NEW VARIABLE NAME....
show_student = display_student

show_student("Emma", 23)'''

# ARANGE STRING CHARACTERS SUCH TAHT LOWERCASE CHARACTERS SHOULD COME FIRST

'''str1 = 'PyNaTive'
# Expected Output: yaivePNT

new = ''
for j in str1:
  if j != j.upper():
    new += j
    str1 = str1.replace(j,'')


for i in str1:
  new += i

print(new) '''

# islower(), isupper(), uppper(), lower()...

'''print("Musthak".upper())
print("MUSThak".lower())
print("MUSTHAK".isupper())
print("MUSTHAK".islower())
print('musthak'.islower()) '''

'''
islower(), isupper() are boolean values..
if a string contains totally uppercase letters than .isupper() is a true value.
likewise 'false', if the string contains atleast one lowercase character.
.islower() similar to the .isupper() in the same opposite way....
'''

# we can remove characters from a string using " ".replace(), " ".translate()...
'''
name = "Musthakq"
# Remove 'q' from the string 
print(name.replace('q','')) ''' # a string letter can be removed by replacing it by a ''


# SOME PROPERTIES OF LIST...

'''nameList = []

nameList.append(21)
nameList.append(25)
nameList.append(50)
nameList.append(134)
nameList.append(220)

print(nameList)
nameList.remove(25)
print(nameList)

second = nameList.pop(1) # pop takes the index of the object as parameter. There is no use of square bracket with pop
print(second) # pop removes the particular object with the index and stores the object. 
# particular object can be assigned to a identifier.
print(nameList)

del nameList[0]
print(nameList)

nameList.append(21)
nameList.append(25)
nameList.append(50)
print(nameList)

nameList.sort()
print(nameList)

print(nameList.index(21))'''

# Largest product in a series
# LPS

'''def LPS(n):
  num = 7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450
  num = str(num)
  digit_string = ""
  prod = 1
  multiple = 1
  for index, char in enumerate(num) :
    try:
      digit_string = ""
      for turns in range(1,n): 
        char += num[index + turns]
        digit_string = char
      #print(digit_string)
      
      multiple = 1
      for turn in range(n):
        multiple *= int(digit_string[turn])
      #print(multiple)
      digit_string = ""
      if multiple > prod:
        prod = multiple

    except:
      pass  
  
  print(prod)

LPS(4)
LPS(13)'''


# Regular expression < re > in python...      
  
'''
import re

txt1 = "red flag blue flag"
txt2 = "yellow flag red flag blue flag green flag"
txt3 = "pink flag red flag black flag blue flag green flag red flag"



pattern = "red flag|blue flag"


print(re.findall(pattern, txt1)) # ➞ ["red flag", "blue flag"]
re.findall(pattern, txt2) # ➞ ["red flag", "blue flag"]
re.findall(pattern, txt3) # ➞ ["red flag", "blue flag", "red flag"]
    

'''

for i in range(5, 1, -1):
  print(i)
        
        
    
    
    
  
