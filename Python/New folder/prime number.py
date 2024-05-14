'''num =   int(input("Enter a number:"))


if num == 1 :
    print("it's not a prime number")

elif num > 1 :
    n = 0
    for i in range(2,num):
        if num % i == 0 :
            n +=1

    if n == 0:
        print("It's prime number")
    else:
        print("it's not a prime number") '''

# GETTING NTH PRIME NUMBER. (METHOD FROM THE INTERNET)
'''
def get_nth_prime(nth):
  """ Returns the n-th prime number
  """
  total_primes = 0
  size_factor = 2
  s = (nth * size_factor)
  while total_primes < nth:
    primes = get_primes(s)
    total_primes = sum(primes[2:])
    size_factor += 1
    s = (nth * size_factor)
  nth_prime = count_primes(primes, nth)
  print (nth_prime)

def get_primes(s):
  """ Generates primes using the Sieve of Eratosthenes
      Includes the optimization where for every prime p, only factors p >= p^2
      are verified.
      The list of primes is represented with a bytearray. Each index corresponds
      to an integer in the list. A value of "1" at the index location indicates
      the integer is a prime.
  """
  primes = bytearray([1]*s)
  for i in range(2, s):
      if primes[i] == 1:
        for j in range(i, s):
          if i*j < s:
            primes[i*j] = 0
          else:
            break
  return primes


def count_primes(primes, nth):
  """ Returns the n-th prime represented by the index of the n-th "1" in the
      bytearray.
  """
  count = 0
  for k in range(2, len(primes)):
    count += primes[k]
    if count == nth:
      return k


def main():
    # Get the 20,000th prime number
    N_TH = 20000
    nth_prime = get_nth_prime(N_TH)
    print("The {}-th prime is: {}".format(N_TH, nth_prime))


if __name__ == "__main__":
    main()


get_nth_prime(100)
get_nth_prime(10000) '''

# GETTING NTH PRIME NUMBER (MY METHOD)

# CALCULATING THE NTH PRIME NUMBER...... (EX: 10001th prime number is 104743)
'''
def nthPrime(nth):
  primeList = [2]
  num = 1
  while True:
    num += 2
    turn = 1
    for p in primeList:
      if num >= p**2 and num % p == 0 : # dividing odd numbers by prime numbers which are already exist in primelist
        turn = 0                    # to make this dividng process easy, dividing a number by a prime when number is greater than or equal to the square of the prime.
        break
    if turn == 1:
      primeList.append(num)

    if len(primeList) == nth:
      print(primeList[-1])
      break

nthPrime(10001)'''


   
        
    
    
    
  