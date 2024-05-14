
testString = "Oranges and lemons, Say the bells of St.Clement's. You owe me three farthings, Say the bells os St.Martin's."

wordList = testString.split()

print(wordList)

count = 0
for words in wordList:
    if "l" in words:
        count+=1

print(count)