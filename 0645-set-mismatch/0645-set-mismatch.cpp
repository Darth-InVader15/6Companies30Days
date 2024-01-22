class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2);
        int n = nums.size();
        vector<int> arr(n+1,0);

        for(auto x:nums)
        {
            arr[x]++;
        }

        for(int i =1;i<n+1;i++)
        {
            if(arr[i] == 2) ans[0] = i;
            else if(!arr[i])    ans[1] = i;
        }
        return ans;
        
    }
};