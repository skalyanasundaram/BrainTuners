import sys


while True:
    try:
        inp = input()
    except EOFError:
        break
    
    maxCount = 0
    charMap = {}
    for x in inp:
        if x.isalpha():
            val = charMap.get(x, 0)
            val = val + 1
            charMap[x] = val

            if maxCount < val:
                maxCount = val

    smallLetters = ""
    capsLetters = ""
    for x in charMap.keys():
        if charMap[x] == maxCount:
            if x.islower():
                smallLetters = smallLetters + x
            else:
                capsLetters = capsLetters + x

    print("{}{} {}".format(''.join(sorted(capsLetters)), ''.join(sorted(smallLetters)), maxCount))
