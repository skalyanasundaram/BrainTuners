import sys

wordMap = {}
readingDictionary = True

def GetCharMap(word):
    charMap = {}
    for x in word:
        if x.isalpha():
            val = charMap.get(x, 0)
            charMap[x] = val + 1

    return charMap

def AddWord(word):
    wordMap[word] = GetCharMap(word)

def FindCount(inputCharMap):
    wordCount = 0
    for word in wordMap.keys():
        wordCharMap = wordMap[word]
        for letter in wordCharMap:
            if wordCharMap[letter] > inputCharMap.get(letter, 0):
                break
        else:
            wordCount = wordCount + 1

    return wordCount
while True:
    inp = sys.stdin.readline().strip()

    if readingDictionary == True:
        if inp == '#':
            readingDictionary = False
        else:
            AddWord(inp)
    else:
        if inp == '#':
            break
        else:
            charMap = GetCharMap(inp)
            print (FindCount(charMap))