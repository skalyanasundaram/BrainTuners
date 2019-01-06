import sys

#sum of long sequence
def getMaxSequenceValue(sequence):
    maxsum = 0
    currentsum = 0
    for x in sequence:
        currentsum = currentsum + x
        if currentsum < 0:
            currentsum = 0
        if maxsum < currentsum:
            maxsum = currentsum
    return maxsum

result = []
while True:
    inp = input().strip()

    if (not inp):
        continue

    sequenceCount = int(inp)
    
    if sequenceCount == 0:
        break

    sequence = []
    while sequenceCount > 0:
        inp = input()
        currentInput = list(map(int, inp.split()))
        sequenceCount = sequenceCount - len(currentInput)
        sequence.extend(currentInput)

    value = getMaxSequenceValue(sequence)
    if value > 0 :
        result.append("The maximum winning streak is {}.".format(value))
    else:
        result.append("Losing streak.")

for value in result:
    print (value)
print ("")