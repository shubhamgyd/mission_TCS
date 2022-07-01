// Utility Function which check wheather every element have unique count or not
function solution(arr){

    // Declare frequency map for count the freuency of every element
    const freqMap=new Map();

    // Iterate array and count the frequency of each element and store it into hashMap
    for(var i=0;i<arr.length;i++)
    {
        freqMap.set(arr[i], (freqMap.get(arr[i]) ?? 0) + 1)
    }

    // Another hashMap to map the count the each element
    const occuranceValues=new Map();

    // Now put the freqency of each element into new hashMap
    for(const [key,value] of freqMap.entries())
    {
        occuranceValues.set(value,(occuranceValues.get(value) ?? 0) + 1)
    }

    // Now it will help us to decide, every element have unique count or not
    // if we found the count of any frequency greater than equal to 2, then reutrn false
    // else return true
    for(const [key,value] of occuranceValues.entries())
    {
        if(value>=2)
        {
            return false;
        }
    }
    return true;
}


// Initial array
// Example :1 
var arr=[1,3,5,4,3,1,1];

// Function call to check every element have unique count or not
ans=solution(arr);

// print answer
console.log(arr);
console.log(ans)



console.log("\n");
// Example :2 
var arr=[1,3,5,3,1,1];

// Function call to check every element have unique count or not
ans=solution(arr);

// print answer
console.log(arr)
console.log(ans)


