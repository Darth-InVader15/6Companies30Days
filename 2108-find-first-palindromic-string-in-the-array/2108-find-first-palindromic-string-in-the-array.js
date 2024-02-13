/**
 * @param {string[]} words
 * @return {string}
 */
var isPal = function(str)
{
    var n = str.length;

    for(var i=0;i<n;i++)
    {
        if(n-i-1 < i)   break;
        if(str[i] != str[n-i-1])    return 0;
    }
    return 1;
}
var firstPalindrome = function(words) {
    var n = words.length;

    for(var i=0; i<n;i++)
    {
        let str = words[i];

        if(isPal(str) == 1) return str;

    }
    let em = "";
    return em;
    
};