/*
Design a parking system for a parking lot. The parking lot has three kinds of parking spaces: big, medium, and small, with a fixed number of slots for each size.

Implement the ParkingSystem class:

ParkingSystem(int big, int medium, int small) Initializes object of the ParkingSystem class. The number of slots for each parking space are given as part of the constructor.
bool addCar(int carType) Checks whether there is a parking space of carType for the car that wants to get into the parking lot. carType can be of three kinds: big, medium, or small, which are represented by 1, 2, and 3 respectively. A car can only park in a parking space of its carType. If there is no space available, return false, else park the car in that size space and return true.
 

Example 1:

Input
["ParkingSystem", "addCar", "addCar", "addCar", "addCar"]
[[1, 1, 0], [1], [2], [3], [1]]
Output
[null, true, true, false, false]

Explanation
ParkingSystem parkingSystem = new ParkingSystem(1, 1, 0);
parkingSystem.addCar(1); // return true because there is 1 available slot for a big car
parkingSystem.addCar(2); // return true because there is 1 available slot for a medium car
parkingSystem.addCar(3); // return false because there is no available slot for a small car
parkingSystem.addCar(1); // return false because there is no available slot for a big car. It is already occupied.
*/

#include<bits/stdc++.h>
using namespace std;

class ParkingSystem {
    int large,mid,smal;
    int largeCnt,midCnt,smalCnt;
public:
    // Initialize all variables
    ParkingSystem(int big, int medium, int small) {
        large=big;
        mid=medium;
        smal=small;
        largeCnt=0;
        midCnt=0;
        smalCnt=0;
    }
    
    // check space is available or not in respective carType
    bool addCar(int carType) {
        if(carType==1)
        {
            // if space available then allot space to car
            if(largeCnt<large and large>0)
            {
                largeCnt++;
                return true;
            }
            // else return false
            else return false;
        }
        // if space available then allot space to car
        else if(carType==2)
        {
            if(midCnt<mid and mid>0)
            {
                midCnt++;
                return true;
            }
            // else return false
            else return false;
        }
        // if space available then allot space to car
        if(smalCnt<smal and smal>0)
        {
            smalCnt++;
            return true;
        }
        // else return false
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */