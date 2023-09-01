import tokenize
text = '"Oh no,no,","said the little Fly","to ask me is in vain."'
newList = []
i = 0
while i < len(text):
    if text[i] == '"':
        j = i+1
        newStr = ""
        while j < len(text) and text[j] != '"':
            newStr += text[j]
            j = j+1
        newStr.lower()
        newList.append(newStr)
