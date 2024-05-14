# Multiples of 3 or 5, Problem 1
# If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
# Find the sum of all the multiples of 3 or 5 below 1000.
'''
num = int(input("Enter the number:"))

def sum(number):
    sum = 0
    for i in range(number):
        if i % 3 == 0 or i % 5 == 0 :
            sum += i
    
    print(sum)


sum(num) '''

# Even fibonacci Numbers, Problem 2
'''
Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
'''

'''
def fibonacci(Num1, Num2):
    fibonacci_List = [Num1, Num2]

    for index, num in enumerate(fibonacci_List):
        if index > 0:
            newElement = fibonacci_List[index] + fibonacci_List[index-1]
            if newElement > 4000000:
                break
            fibonacci_List.append(newElement)

    sumOfTerms = 0
    for char in fibonacci_List: 
        if char % 2 == 0:
            sumOfTerms += char
    print(sumOfTerms)

fibonacci(1,2) '''

# Largest Prime factor.., Problem 3
'''
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
'''
'''
def LPF(num): # LARGEST PRIME FACTOR
    max_prime = 0
    while num % 2 == 0:
        max_prime = 2
        num = num / 2
    
    for i in range(3, int(num**(1/2)) + 1, 2):
        while num % i == 0:
            max_prime = i
            num = num / i
    
    if num > 1:
        max_prime = num

    print(max_prime)


LPF(13195)
LPF(600851475143)
'''
