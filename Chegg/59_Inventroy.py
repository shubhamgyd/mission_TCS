# Utility function which display inventory
def displayInventory(inventory):
    print("Inventory:")
    # total count of items
    item_total = 0
    for key,value in inventory.items():
        print(str(value) + " "+ str(key))
        item_total=item_total+value

    # printing total items count
    print("Total number of items: " + str(item_total))



# Utility function which add items into the inventory
def addToInventory(inventory,addedItems):

    # Iterate list of items
    for item in addedItems:
        # if items is already present, then just increment the count 
        # else put it with a count of 1
        inventory[item] = inventory.get(item, 0) + 1
    print('Inventory updated!')

    # return updated inventory
    return inventory


def main():
    # Initial inventory list
    stuff = {'rope': 1, 'gold coin': 42, 'dagger': 1}

    # list of items added into the inventory
    dragonLoot = ['gold coin', 'dagger', 'gold coin', 'gold coin', 'ruby']

    # call to display inventory
    displayInventory(stuff)
    print('The dragon has been vanquished! Looting...')

    # Update the inventory and store it
    stuff = addToInventory(stuff, dragonLoot)

    # call to display inventory
    displayInventory(stuff)


# calling main function and start the processing
if __name__=="__main__":
    main()