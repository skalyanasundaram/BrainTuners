import sys

wordList = []
result = []

def AddWord(word):
    wordList.append(word)

def GetWord(inputString, startIndex):
    index = startIndex
    while index < len(inputString):
        if (inputString[index].isalpha()):
            index = index + 1
        else:
            break

    return inputString[startIndex:index]

def AccessWord(num):
    pos = len(wordList) - num

    if pos >= 0 and pos < len(wordList):
        word = wordList[pos]
        del wordList[pos]
        wordList.append(word)
        return word

    return ""

def GetNumber(inputString, startIndex):
    index = startIndex
    num = 0
    while index < len(inputString):
        if (inputString[index].isdigit()):
            num = (num *10) + int(inputString[index])
            index = index + 1
        else:
            break
    return num, index - startIndex # also returns the number of character

while True:
    inp = sys.stdin.readline()
    if (inp.strip() == "0"):
        break
    
    index = 0
    resultString = ""
    while index < len(inp):
        if inp[index].isalpha():
            word = GetWord(inp, index)
            AddWord(word)
            resultString = resultString + word
            print(word, end='')
            index = index + len(word)
        elif inp[index].isdigit():
            values = GetNumber(inp, index)
            
            num = values[0]
            index = index + values[1]

            word = AccessWord(num)
            resultString = resultString + word
            print(word, end='')
        else:
            resultString = resultString + inp[index]
            print(inp[index], end='')
            index = index + 1
    result.append(resultString)
#accumulating result to a string and printing didn't work. You have to print string as you find.