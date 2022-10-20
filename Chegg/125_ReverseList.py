# Class to make LikedList
# members data and next reference
class ListNode:
    def __init__(self, data):
        self.val = data
        self.next = None


# Push newNode at the front of linked list
def pushNode(head, data):
    # allocate memory to node
    node = ListNode(data)
    # assign data
    node.val = data
    # assign next node
    node.next = head
    # set head to the node
    head = node
    # return head
    return head


def printNext(node):
    # Stops the condition
    if node == None:
        return

    # Recurse
    printNext(node.next)

    # Print to the console
    print(node.val, end='->')


def reverseList(node):
    # Stops the condition
    if node == None:
        return node

    # if node of next is none then return node as it is
    # it will be a new head
    if node.next == None:
        return node

    # store the prevNode
    preNode = reverseList(node.next)
    # revese the link between nodes
    node.next.next = node
    # set None
    node.next = None
    return preNode


if __name__ == '__main__':
    head = None
    head = pushNode(head, 1)
    head = pushNode(head, 2)
    head = pushNode(head, 3)
    head = pushNode(head, 4)
    head = pushNode(head, 5)

    # Print list of nodes using recursion
    print("LinkedList Without Reversing: ", end=" ")
    printNext(head)
    print("None\n")

    # Revese List
    head = reverseList(head)

    # Print reverse list
    print("LinkedList With Reversing: ", end=" ")
    printNext(head)
    print("None\n")
