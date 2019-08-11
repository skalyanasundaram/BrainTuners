import sys

valuetonum = {  int(0b111101101101111) : 0,
            int(0b010010010010010) : 1, 
            int(0b111001111100111) : 2,
            int(0b111001111001111) : 3, 
            int(0b101101111001001) : 4, 
            int(0b111100111001111) : 5, 
            int(0b100100111101101) : 6,
            int(0b111001001001001) : 7,
            int(0b111101111101111) : 8,
            int(0b111101111001001) : 9
}

valuetoop = { int(0b101101010101101) : '*',
            int(0b010010111010010) : '+',
            int(0b000000111000000) : '-',
            int(0b010000111000010) : '/' }

numtovalue = {  0 : int(0b111101101101111),
            1 : int(0b010010010010010), 
            2 : int(0b111001111100111),
            3 : int(0b111001111001111), 
            4 : int(0b101101111001001), 
            5 : int(0b111100111001111), 
            6 : int(0b100100111101101),
            7 : int(0b111001001001001),
            8 : int(0b111101111101111),
            9 : int(0b111101111001001),
            '*' : int(0b101101010101101),
            '+' : int(0b010010111010010),
            '-' : int(0b000000111000000),
            '/' : int(0b010000111000010) }

# value would be like list of numbers like this [['.', '0', '.'], ['.', '0', '.'], ['.', '0', '.'], ['.', '0', '.'], ['.', '0', '.']]
def printnum(value):
    prefixSpace = False
    result = ['' for x in range(0, 5)]
    for x in range(0, 5):
        for y in range(0, len(value)):
            result[x] = result[x] + (''.join(value[y][x])).rjust(4 if y > 0 else 0)
    #result = [''.join(value[y][x]).ljust(1 if y > 0 else 0) for x in range(0, 5) for y in range(0, len(value))]
    for x in result:
        print (x)
        

def printnumtodots(v):
    result = []
    while v > 0:
        value = numtovalue[v % 10]
        v = int(v/10)
        result.insert(0, [[ '0' if value & (1 << (15 - x -1 - (3 * y))) else '.' for x in range(3)] for y in range(5)])
    printnum(result)        

def convertdottonum(inputset):
    maxlen = len(inputset[0])
    x = 0
    left = right = -1
    op = ''

    while x < maxlen:
        value = 0
        for row in range(0, 5):
            for col in range(0, 3):
                value = value | (1 << ((row * 3) + col) if inputset[row][x+col] == '0' else 0)
                m = (( (row * 3) + col))
                #print ("index", m, "inp:", inputset[row][x+col], "value ", value, "bin:", bin(value), "shidt", bin(1 << m))
        x = x + 4

        num = valuetonum.get(value, -1)
        print ("value ", value, " num ", num)
        if (num != -1 and left == -1):
            left = num
        elif (num != -1 and left != -1):
            right = num
        else:
            op = valuetoop[value]

    result = 0
    if op = '*':
        result = left * right
    elif op = '+'
#printnumtodots(1234567890)

resultnum = []
inputset = []
while True:
    inp = sys.stdin.readline().strip()
    if (len(inp) == 0):
        #empty string convert input to num
        num = convertdottonum(inputset)
        if (num == 0):
            break
        else:
            resultnum.append(num)
    else:
        inputset.append(inp)

# print final result
for x in resultnum:
    #printnumtodots(x)
    print (x)
    print ("")
    