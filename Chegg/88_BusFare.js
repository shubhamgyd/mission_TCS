
function publicBusFare(passengers)
{
    // First of all we need to find how many total buses required
    // According to criteria we need to divide passengers by 50(size of bus), so that it will give
    // us totalNumber of buses and remaining passenges
    let totalBuses=passengers/50;

    // It store the remaining passengers
    passengers=passengers%50;

    // Now we need to find how many total micro buses required by dividing by 11
    // beause capacity of micro bus is 11 passengers

    let microBuses=passengers/11;

    //Here is remaining people, which will go via public bus
    remainingPassengers=passengers%11;


    // According to the questions public fare of each passenger is 250 TK
    // so just return the remainingPassengers*250

    return remainingPassengers*250;
}

let totalFare1=publicBusFare(117)
console.log("Total Public Fare of 117 people are: "+totalFare1 +" TK");

let totalFare2=publicBusFare(234)
console.log("Total Public Fare of 234 people are: "+totalFare2+" TK");


let totalFare3=publicBusFare(460)
console.log("Total Public Fare of 460 people are: "+totalFare3+" TK");