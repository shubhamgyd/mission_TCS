import random

# utility function which take the input as a sentence and checks the rules of sentence
# also fixex the errors in sentences
def fixer():
    # sentence input
    sentence=input()

    # converting string into list
    wordList=sentence.split(" ")

    # flag which keep trak on erros in sentence
    erroInSentence=False


    # punctions makrs list
    pMakrs=['!', '"' ,'#', '$','%','&' ,"'",'(',')','*','+',',',' ','-','.','/',':',';','<','=','>','?','@','[','"\"',"]",'^','_','`','{','|','}','~']

    
    # if first word is not in upper case
    if not wordList[0].isupper():
        # mark error
        erroInSentence=True

        # print the error
        print("Error: First word is not capitalize")

        # Fix error
        # convert it into upper case
        wordList[0]=wordList[0].upper()

    # is punctuation marks is absent
    if wordList[-1][-1] not in pMakrs:
        # mark as error
        erroInSentence=True

        # print error
        print("Error: Missing ending punctuation mark")

        # fix error
        # add any pnctuation marks
        # here we are taking any random punctuation mark
        wordList[-1]=wordList[-1]+ random.choice(tuple(pMakrs))

    # if no error occur in sentence
    # then simply print and return the Rules are confirmed
    if erroInSentence==False:
        print("RULES CONFIRMED")
        return "RULES CONFIRMED"
    
    # else convert list to string and return it
    translatedSentence=' '.join(wordList)
    return translatedSentence



# callling a function to check the rules
def main():
    # ans stores the string returned by fixer after fixing sentence
    ans=fixer()
    # printing ans
    print(ans)


# main function invoked
if __name__=="__main__":
    main()