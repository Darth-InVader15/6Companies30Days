/**
 * @param {number[]} nums
 * @return {number}
 */
var maxRotateFunction = function(nums) {

    let n = nums.length;
    let s = 0;
    let sum = 0;
    
    for(var i=0;i<n;i++)
        {
            sum += nums[i];
        }
        
    
        
    for(var i=0;i<n;i++)
        {
            s += (i*nums[i]);
        }

    let maxx = s;
    for(var k=1;k<n;k++)
        {
            let curr = sum - (n*nums[(n-k)%n]);
            curr += s;
            maxx = Math.max(maxx,curr);
            s = curr;
        }
    return maxx;
        
    
};