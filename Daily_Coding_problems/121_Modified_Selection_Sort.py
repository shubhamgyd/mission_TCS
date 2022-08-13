# Helper function which sort array
def selection_sort(numbers1):
    # list to stor the comparasitions and swaps
    swapsAndComparisitions=[]
    # Iterate from start to end 
    for i in range(0,len(numbers1)-1):
        # list to store oprations
        operations=[]
        # count the swaps to sort ith number
        swaps=0
        # count comparasition to sort the ith number
        comparisons=0
        # Index of current Element
        minInd=i
        # Iterate from i+1 to the end of array
        for j in range(i+1,len(numbers1)):
            # if jth element is less than mnInd th element
            if numbers1[j]<numbers1[minInd]:
                # set index if minimum element
                minInd=j
            # Increment the comparasitions
            comparisons=comparisons+1
        
        # Increment the swaps
        swaps=swaps+1

        # Swap ith element and minInde th element
        temp=numbers1[i];
        numbers1[i]=numbers1[minInd];
        numbers1[minInd]=temp;

        # Append comparations and swaps in operation list
        operations.append(comparisons)
        operations.append(swaps)
        # append operation list in final swapsAndComparasition list
        swapsAndComparisitions.append(operations)
    return swapsAndComparisitions


# Helper function which sort array fast
def selection_sort_fast(numbers2):
    swapsAndComparisions=[]
    n=len(numbers2)
    # Start from the end of list
    # it says that element in range i to end of list are sorted
    for i in range(n-1,0,-1):
        # set current element as maximumNumber
        mxNumber=numbers2[i]
        # get index numer
        mxInd=i
        # count of swaps
        swaps=0
        # count of comparasitions
        comparisons=0

        operations=[]
        # Iterate in non sorted array
        for j in range(0,i):
            # if jth element is greater than mxNumber
            if numbers2[j]>mxNumber:
                # update mxNumber
                mxNumber=numbers2[j]
                # set mxIndex
                mxInd=j
            # Increment the comparasitions
            comparisons=comparisons+1
        
        # if we get the bigger number than the ith number
        if mxNumber>numbers2[i]:
            # Then swap them
            tmp=numbers2[i]
            numbers2[i]=numbers2[mxInd]
            numbers2[mxInd]=tmp
            # Increment the swaps
            swaps=swaps+1
        # Append comparsitions and swaps in list
        operations.append(comparisons)
        operations.append(swaps)
        # append operations list in swapsAndComparasitions list
        swapsAndComparisions.append(operations)
    # return list
    return swapsAndComparisions
        
        

    


# List1
numbers1=[76,53,48,24,12]

# List2
numbers2=[76,53,48,24,12]

# getResult1
result1=selection_sort(numbers1)

# getResult2
result2=selection_sort_fast(numbers2)

# PrintResult1
print()
print()
print(result1)

# PrintResult2
print(result2)
print()
print()