import sys

output = []
while True:
    try:
        inp = input()

        bookCount = int(inp)
        prices = []
        pricesMap = {}

        inp = input()
        prices = list(map(int, inp.split()))
        prices.sort()

        for price in prices:
            pricesMap[price] = pricesMap.get(price, 0) + 1
        #for priceX in inp.split():
        #    index = 0
        #    price = int(priceX)
        #    #print("Current price", price, "  ", index, "  ", len(prices))
        #    while index < len(prices):
        #        #print("index {}, value {}, actual price {}".format(index, prices[index], price))
        #        if prices[index] < price:
        #            index = index + 1
        #        else:
        #            break

        #    #print("index {}, length {}".format(index, len(prices)))
        #    if index >= len(prices):
        #        prices.append(price)
        #    else:
        #        prices.insert(index, price)

        #    pricesMap[price] = pricesMap.get(price, 0) + 1

        #print("Array", prices)
        money = int(input())
        
        start = 0
        end = bookCount - 1
        mid= int(end / 2)
        expectedMoney = int(money / 2)
        while start < end:
            median = int((end - start) / 2)
            # we are only searching nearest. Not exact match. 1,2,3,5,6. When we search for 4, we may have start end pointers in 3 and 5 and it may never break
            #We can't make furhter progress

            if median == 0:
                if prices[start] - expectedMoney > prices[end] - expectedMoney:
                    mid = end
                else:
                    mid = start
                break 

            mid = start + median
            #print("start {}, end {}, Mid {}, mid Value {}, money {}".format(start, end, mid, prices[mid], money))
            if (prices[mid] < expectedMoney):
                start = mid
            elif prices[mid] > expectedMoney:
                end = mid
            else:
                break
        
        while mid >= 0:
            #print("mid {}".format(mid))
            priceB = money - prices[mid]
            expectedCount = 0
            if priceB == prices[mid]:
                expectedCount = 1

            # multiple books with same price can exists
            if (pricesMap.get(priceB, 0) > expectedCount):
                output.append("Peter should buy books whose prices are {} and {}.\n".format(prices[mid], priceB))
                break

            mid = mid - 1

        input()
    except EOFError:
        break
    
x = 0
while x < len(output):
    print (output[x])
    #if x < len(output) - 1:
    #    print ("")
    x = x + 1