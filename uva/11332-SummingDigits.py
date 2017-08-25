import sys

def getsum(value):
    sum = 0
    while value > 0: 
        sum = sum + (value % 10)
        value = int(value / 10)

        #print (sum, value)
        #avoiding recursion
        if (value == 0 and sum > 9):
            value = sum #start the loop with new value
            sum = 0

    return sum

inp = []
while True:
    value = int(sys.stdin.readline().strip())
    if (value == 0):
        break
    inp.append(value)

for value in inp:
    print(getsum(value))
