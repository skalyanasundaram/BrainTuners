import sys

inputs = []
length = -1

while True:
    try:
        inp = input()
    except EOFError:
        break

    try:
        for x in inp.split():
            if (length == -1):
                length = int(x)
            else:
                inputs.append((length, x))
                length = -1
    except ValueError:
        if (length == -1):
            length = int(inp)
        else:
            inputs.append((length, x))
            length = -1


for x in inputs:
    length = x[0]
    word = x[1]
    map = {}

    for x in range(len(word) - length + 1):
        substr = word[x:x+length]
        map[substr] = map.get(substr, 0) + 1
    
    maxvalue, password = 0, ""
    for key, value in map.items():
        #print("key=", key, "value=",value)
        if (value > maxvalue):
            maxvalue = value
            password = key

    print(password)