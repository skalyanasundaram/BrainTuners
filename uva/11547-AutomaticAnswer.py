import sys

testcase = int(sys.stdin.readline().strip())
inp = []
while testcase > 0:
    testcase = testcase - 1
    inp.append(int(sys.stdin.readline().strip()))

for n in inp:
    n  = (n*315) + 36962
    if (n < 0):
        n = n * -1
    x = int((n % 100) / 10)
    print (x)
