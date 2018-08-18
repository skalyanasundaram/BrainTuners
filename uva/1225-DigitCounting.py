import sys

result = []
testCases = int(sys.stdin.readline().strip())
for testCase in range(testCases):
    value = int(sys.stdin.readline().strip())
    digitMap = {el:0 for el in range(10)}
    for x in range(1, value + 1):
        while x > 0:
            digitMap[int(x % 10)] = digitMap[int(x % 10)] + 1
            x = int(x / 10)
    
    strresult = ""
    for x in range(10):
        strresult = strresult + str(digitMap[x]) + " "
    result.append(strresult.strip())

for val in result:
    print (val)