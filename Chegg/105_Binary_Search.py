
# Recursive Binary Search
# Time Complexity :O(logn)
# Space Complexity: O(logn) i.e. for recursive calls
def Ordered_binary_Search(nums,start,end,key):
    if end>=start:
        midPos=(end+start)//2;

        # if key is present at midPos
        if nums[midPos]==key:
            return midPos
        
        # if key is smaller than midPos element
        # then search it left half of array
        elif nums[midPos]>key:
            return Ordered_binary_Search(nums,start,midPos-1,key)
        
        # else search it in right half if array
        else:
            return Ordered_binary_Search(nums,midPos+1,end,key)
    # if element is not present in array
    else:
        return -1;





# Itertive Binary Search
# Time Complexity:O(logn)
# Space Complexity:O(1)
# We are not calling any kind of funciton and
# not using any container space so space is constant
def Iterative_Ordered_binary_search(nums,start,end,key):
    while start<=end:
        # get the middle position
        mid=(end+start)//2
         # if key is present at midPos
        if nums[mid]==key:
            return mid

        # if key is smaller than midPos element
        # then search it left half of array
        elif nums[mid]>key:
            end=mid-1

        # else search it in right half if array
        else:
            start=mid+1
    return -1;


# list of elements
list1=[0,1,3,8,14,18,19,34,52]
key=3
# get index of key from list
index=Ordered_binary_Search(list1,0,len(list1)-1,key)
print("list1: "+str(list1))
print("key: "+str(key))
# if key is present and index is not -1
if index!=-1:
    print("True")
# else print false
else:
    print("False")




print("\n")

# list2
list2=[0,1,3,8,14,18,19,34,52]
key=17
index=Ordered_binary_Search(list1,0,len(list1)-1,key)
print("list1: "+str(list2))
print("key: "+str(key))
# if key is present and index is not -1
if index!=-1:
    print("True")
# else print false
else:
    print("False")