import sys
import math

def readInputs():
    inp = []
    while True:
        inpstr = sys.stdin.readline().strip()
        try:
            values = inpstr.split()
            for x in values:
                value = int(x)
                if (value == 0):
                    return inp
                inp.append(value)
        except ValueError:
            value = int(values)
            if (value == 0):
                return inp
            inp.append(value)

def getDivisors(value):
    if (value == 1):
        return [0]
    
    result = [1]
    for x in range(2, int(math.sqrt(value) + 1)):
        if (value % x == 0):
            a, b = x, int(value / x)

            result.append(a)
            if (a != b):
                result.append(b)

    return result

inputs = readInputs()
print("PERFECTION OUTPUT")
for x in inputs:
    divisors = getDivisors(x)
    divsum = sum(divisors)
    result = ""
    if divsum == x:
        result = "PERFECT"
    elif divsum > x:
        result = "ABUNDANT"
    else:
        result = "DEFICIENT"

    print("{:>5}  {}".format(x, result))
print("END OF OUTPUT")