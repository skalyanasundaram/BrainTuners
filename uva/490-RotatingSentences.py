import sys

inputs = []
maxlen = 0
while True:
    try:
        inp = input()
    except EOFError:
        break
    if (len(inp) > maxlen):
        maxlen = len(inp)
    inputs.append(inp)

for i in range(0, maxlen):
    out = ""
    for j in range(len(inputs)-1, -1, -1):
        if (i < len(inputs[j])):
            out = out + inputs[j][i]
        else:
            out = out + " "
    print (out)