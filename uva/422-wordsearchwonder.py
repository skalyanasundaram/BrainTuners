import sys
from enum import Enum 

size = int(sys.stdin.readline())
inp = [['' for x in range(size)] for y in range(size)]
for x in range(size):
    str = sys.stdin.readline()
    for y in range(size):
        inp[x][y] = str[y]

get = lambda x, y: ' ' if (x < 0 or y < 0 or x >= size or y >= size) else inp[x][y]

map = {}
for x in range(size):
    for y in range(size):
        map[inp[x][y]] = map.get(inp[x][y], []) + [(x, y)]

words = []
for word in sys.stdin:
    if word.strip() == "0":
        break
    words.append(word.strip())

directions = Enum("directions", "left, lefttop, top, righttop, right, rightbottom, bottom, leftbottom")

def searchByDirection(inp, word, x, y, direction):
    a = b = -1
    for ch in list(word):
        if (direction == directions.left):
            a,b = x, y - 1
        elif (direction == directions.lefttop):
            a,b = x - 1, y - 1
        elif (direction == directions.top):
            a,b = x - 1, y
        elif (direction == directions.righttop):
            a,b = x - 1, y + 1
        elif (direction == directions.right):
            a,b = x, y + 1
        elif (direction == directions.rightbottom):
            a,b = x + 1, y + 1
        elif (direction == directions.bottom):
            a,b = x + 1, y
        else:
            a,b = x + 1, y - 1

        if (a < 0 or b < 0 or a >= size or b >= size):
            return (-1, -1)

        if (inp[a][b] == ch):
            x,y = a,b
        else:
            return (-1, -1)
        # found = False
        # for nextPoint in map.get(ch, []):
        #     if (nextPoint[0] == a and nextPoint[1] == b):
        #         x,y = a,b
        #         found = True
        
        # if not found:
        #     return (-1, -1)

    return (a,b)

def search(map, word):
    for start in map[word[0]]:
        # search in each direction
        for direction in directions:
            result = searchByDirection(inp, word[1:], start[0], start[1], direction)
            if (result[0] != -1 and result[1] != -1):
                print ("{},{} {},{}".format(start[0] + 1, start[1] + 1, result[0] + 1, result[1] + 1))
                return

    print ("Not found") 
         
for word in words:
    search(map, word)