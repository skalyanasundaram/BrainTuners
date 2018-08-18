import sys

def sort(values):
    result = []
    for value in values:
        index = 0
        while index < len(result):
            if (result[index] > value):
                break
            index = index + 1
        result.insert(index, value)
    
    return result


testCases = int(sys.stdin.readline().strip())
result = {}
for testCase in range(testCases):
    inputs = sys.stdin.readline().strip().split()
    values = [int(x) for x in inputs]
    sortedValues = sort(values)
    result[testCase] = sortedValues[int(len(sortedValues) / 2)]

for testCase in range(testCases):
    print ("Case {}: {}".format(testCase + 1, result[testCase]))
   
