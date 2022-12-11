# Class Counter
class Counter:
    # Intance variables counter and limit
    def __init__(self, counter, limit):
        # set values at the time of object creating
        self.counter = counter
        self.limit = limit

    # Function which increments the counter value of counter is less than limit
    def increment(self):
        if self.counter < self.limit:
            self.counter = self.counter+1

    # Function which decrements the counter value if it is greater than 0
    def decrement(self):
        if self.counter > 0:
            self.counter = self.counter-1

    # Function which returns the counter value(current)
    def getValue(self):
        return self.counter


# Object 
obj = Counter(4, 5)
# call increment function
obj.increment()
# call decrement function
obj.decrement()
# get caounter value
print(obj.getValue())
