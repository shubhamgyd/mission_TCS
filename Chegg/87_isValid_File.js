
var isJavaScriptFile = (function () {
    // This regex1 for the any forbidden character prsent or not
    // i.e must not contins this characters
    var regex1 = /^[^\\/:\*\?"<>\|]+$/;

    // This regex2 is used for to check wherather it start with . or not
    // i.e. must not contian this chracters
    var regex2 = /^\./;
    // This regex3 is used for to check wherather it is file name or not
    // i.e. must not be 
    var regex3 = /^(nul|prn|con|lpt[0-9]|com[0-9])(\.|$)/i;

    // Utility function which validate the the fileNAme
    return function isJavaScriptFile(fileName) {
        // Regex1
        let var1=regex1.test(fileName);
        //Regex2
        let var2=regex2.test(fileName);
        //Regex3
        let var3=regex3.test(fileName);
        
        // if all condition are satisfied then return true
        if(var1 && !var2 && !var3) return true;
        // else return false
        return false
    }
})();


console.log("File name index.js: "+isJavaScriptFile("index.js"));
console.log("File name .indexjs: "+isJavaScriptFile(".indexjs"));
console.log("File name i/ndex.js: "+isJavaScriptFile("i/ndex.js"));
console.log("File name index*js: "+isJavaScriptFile("index*js"));
console.log("File name indexjs: "+isJavaScriptFile("indexjs"));


