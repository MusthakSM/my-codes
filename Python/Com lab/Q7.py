
# 5. GCD
num1 = int(input("Enter the num1:"))
num2 = int(input("Enter the num2:"))

gcd=1

smallest= min(num1,num2)

for i in range(2,smallest+1):
    if num1 % i == 0 and num2 % i == 0 :
        gcd = i
    elif num1 % num2 == 0 :
        gcd = 1

print(gcd)