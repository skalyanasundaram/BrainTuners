import sys

fibs = [1, 2]
maxfib = 2
fibsmap = {1 : 1, 2 : 2}

def getfib(fibvalue):
    global maxfib
    while maxfib < fibvalue:
        length = len(fibs)
        maxfib = val = fibs[length - 1] + fibs[length - 2]
        fibs.append(val)
        fibsmap[val] = length + 1

    return fibsmap[fibvalue]

results = []
testcases = int(sys.stdin.readline().strip())
while testcases > 0:
    size  = int(sys.stdin.readline().strip())
    inpfib = sys.stdin.readline().strip().split()
    inpstr = sys.stdin.readline().strip()

    result = [' ' for x in range(len(inpstr) * 2)]
    strindex = -1
    for inpfibindex in range(size):
        while strindex < len(inpstr):
            strindex = strindex + 1
            #print(inpstr[strindex], inpstr[strindex].isalpha(), inpstr[strindex].isupper())
            if (inpstr[strindex].isalpha() and inpstr[strindex].isupper()):
                index = getfib(int(inpfib[inpfibindex]))
                #print(inpfib[inpfibindex], index, inpstr[strindex])
                result[index - 1] = inpstr[strindex]
                inpfibindex = inpfibindex + 1
                break

    results.append(''.join(result).rstrip())
    testcases = testcases - 1

for x in results:
    print (x)