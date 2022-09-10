sentence=input("Enter sentence: ")
print(sentence)

words=len(sentence.split());
firstSpaceInd=0
for i in range(len(sentence)):
    if sentence[i]==' ':
        firstSpaceInd=i
        break
newString=sentence
newString.replace(' ','+')
stringLen=len(sentence)
upperCase=sentence.upper()
word1="pyT"

