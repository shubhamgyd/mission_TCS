from datetime import datetime

# Clock Class
class Clock:
    # setting default values
    def __init__(self, hour=0, minute=0,second=0):
        self.hour=hour
        self.minute=minute
        self.second=second

    # Utility Functiuon which prints the current time
    def currentTime(self):
        now = datetime.now()
        current_time = now.strftime("%H:%M:%S")
        print("Current Time =", current_time)

    # Utility function which change the current time
    def changeTime(self):
        hr=int(input("Enter hours between 0 to 23: "))
        while hr<0 or hr>23:
            print("Please Enter valid hours format(0-23)..!!")
            hr=int(input("Enter hours: "))
        
        min=int(input("Enter minutes between 0 to 59: "))
        while min<0 or min>59:
            print("Please Enter valid minutes format(0-59)..!!")
            min=int(input("Enter minutes: "))

        sec=int(input("Enter seconds between 0 to 59: "))
        while sec<0 or sec>59:
            print("Please Enter valid seconds format(0-59)..!!")
            sec=int(input("Enter seconds: "))

        # getting current time
        current_time = datetime.now()

        # printing Current Time
        current_time1 = current_time.strftime("%H:%M:%S")
        print("Current Time =", current_time1)

        # getting current hours
        current_hour = current_time.hour
        # getting current minutes
        current_minute= current_time.minute
        # getting current seconds
        current_second= current_time.second


        # Now, we have to check the validations
        #  i.e minute is less than 60 or not
        #  second is less than 60 or not
        #  hours is less than 23 or not

        #  validating second
        total_second=current_second+sec
        extra_minute=0
        new_seconds=total_second
        if total_second>=60:
            extra_minute+=(total_second//60)
            new_seconds=(total_second%60)

        # validating minute
        # first add the user input miutes and extraMinute into the toal minute
        # i.e in previous step we have extracted extraSecond add them into our minute
        # to finding the newMinute and extraMinute
        total_minute=current_minute+min+extra_minute
        extra_hours=0
        new_minute=total_minute
        if total_minute>=60:
            extra_hours+=(total_minute//60)
            new_minute=(total_minute%60)
        
        # validating hours
        # add the user input hours and extraHours into our hours, so that we can validate it between into 0-23
        total_hours=current_hour+hr+extra_hours
        new_hours=total_hours
        if new_hours>=24:
            new_hours=(new_hours%24)

        # Printing New Time
        print(f'New Time: {new_hours}:{new_minute}:{new_seconds}')
        
        



import sys
  
  
print("User Current Version:-", sys.version)
# Clock Object
# setting values of hours,miinutes,seconds
obj1=Clock(2,34,45)      
# printing currentTime
obj1.currentTime()
# Changing CurrentTime
obj1.changeTime()
