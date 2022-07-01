
function romanToInt(s) {
    var n = s.length(), value = 0;
    const romanTInt= new Map();
    romanTInt['I']=1;
    romanTInt['V']=5;
    romanTInt['X']=10;
    romanTInt['L']=50;
    romanTInt['C']=100;
    romanTInt['D']=500;
    romanTInt['M']=1000;
    
    for(var i = 0; i < n - 1; i++) {
        if(romanTInt[s[i]] >= romanTInt[s[i + 1]])
        {
            value += romanTInt[s[i]];
        } 
        else 
        {
            value -= romanTInt[s[i]];
        }
    }
    value += romanTInt[s[n - 1]];
    return value;
}

function sortRoman(names)
{
    const decimalStore=new Map();
    for(var i=0;i<names.length;i++)
    {
        console.log(names[i])
    }
    return names;
}

var names=["Steven XL", "Steven XVI", "David IX", "Mary XV", "Mary XIII", "Mary XX"];
names=sortRoman(names);
// console.log(names);