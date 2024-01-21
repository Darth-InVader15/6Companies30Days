class Solution {
    int solve(int ind, vector<int> &arr, vector<int> &dp)
    {
        if(ind >= arr.size())   return 0;

        if(dp[ind] != -1) return dp[ind];
        int take = 0, dont = 0;

        take = arr[ind] + solve(ind+2,arr,dp);
        dont = solve(ind+1,arr,dp);

        return dp[ind] =  max(take,dont);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);

        return solve(0,nums,dp);
        
    }
};