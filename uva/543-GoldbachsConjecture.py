import sys
import math

primes = [3, 5]
primesdict = { 3: True, 5: True }

def getNextPrime(currentPrime):
    next_value = currentPrime
    next_prime = 0
    while next_prime == 0:
        next_value = next_value + 2
        #print ("next value {}".format(next_value))
        for i in range(3, int(math.sqrt(next_value)) + 1, 2):
            if (next_value % i == 0):
                break
        else:
            next_prime = next_value
    #print ("next prime {}".format(next_prime))
    return next_prime

def findPrimeTill(target):
    #print ("Find prime till {}".format(target))
    while primes[-1] <= target:
        nextPrime = getNextPrime(primes[-1])
        primes.append(nextPrime)
        primesdict[nextPrime] = True

def findPrimeSum(value):
    findPrimeTill(value)
    index = 0
    while primes[index] <= int(value/2):
        if primesdict.get(value - primes[index], False) != False:
            print ("{} = {} + {}".format(value, primes[index], value - primes[index]))
            break
        index = index + 1

    else:
        print ("Goldbach's conjecture is wrong.")


inp = []
while True:
    value = int(sys.stdin.readline().strip())
    if (value == 0):
        break
    inp.append(value)

for value in inp:
    findPrimeSum(value)