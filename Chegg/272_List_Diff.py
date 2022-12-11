# Function which return the diffent elements in both lists
def diff(list1, list2):
    # get final answer
    to_return = []
    # Iterate list1
    for elt1 in list1:
        # if element is not in list2
        # parallely check it is already in return list or not
        # if not then append it into final list
        if elt1 not in list2 and elt1 not in to_return:
            to_return.append(elt1)

     # Iterate list2
    for elt2 in list2:
        # if element is not in list1
        # parallely check it is already in return list or not
        # if not then append it into final list
        if elt2 not in list1 and elt2 not in to_return:
            to_return.append(elt2)

    # return list
    return to_return


def main():
    # Read list1
    list1 = list(input("Please enter a list: ").split(' '))
    # Read list2
    list2 = list(input("Please enter another list: ").split(' '))
    # get difference of list1 and list2
    diff_list = diff(list1, list2)
    # print difference
    print(f'The difference between {list1} and {list2} is: {diff_list}')


main()
