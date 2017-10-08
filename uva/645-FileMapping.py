#import pprint
import sys
import os

def printstrcture(level, structure):
    if (bool(structure) == False):
        return

    prefix = ""
    for x in range(0, level):
        prefix = prefix + "|".ljust(6)

    print("{0}{1}".format(prefix, structure["name"]))

    for x in structure["dirs"]:
        printstrcture(level + 1, x)
    
    for x in sorted(structure["files"]):
        print("{0}{1}".format(prefix, x))

def printresult(dataset, result):
    #pp = pprint.PrettyPrinter()
    #pp.pprint(result)
    if (dataset > 1):
        print("")
    print ("DATA SET {}:".format(dataset))
    printstrcture(0, result)

inputs = []
while True:
    inp  = sys.stdin.readline().strip()
    if inp == '#':
        break
    inputs.append(inp)

dataset = 1
result = { "name":"ROOT", "files" : [], "dirs": []}
currentitems = []
currentitems.append(result)

for cinput in inputs:
    if (cinput[0] == 'f'):
        currentitems[-1]["files"].append(cinput)
    elif (cinput[0] == 'd'):
        newdirectory = { "name": cinput, "files": [], "dirs": []}
        currentitems[-1]["dirs"].append(newdirectory)
        currentitems.append(newdirectory)
    elif (cinput[0] == ']'):
        currentitems.pop()
    elif (cinput[0] == '*'):
        printresult(dataset, result)
        result = { "name":"ROOT", "files" : [], "dirs": []}
        currentitems = []
        currentitems.append(result)
        dataset = dataset + 1
