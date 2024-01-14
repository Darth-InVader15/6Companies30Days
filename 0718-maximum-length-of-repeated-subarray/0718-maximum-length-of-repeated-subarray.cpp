class Solution {
    // int ans = -1;
    int solve(int ind1, int ind2,int &cnt, vector<int> &arr1, vector<int> &arr2, vector<vector<int>> &dp)
    {
        if(ind1 == arr1.size() || ind2 == arr2.size())  return 0;

        if(dp[ind1][ind2] != -1)    return dp[ind1][ind2];

        int take = 0;

        if(arr1[ind1] == arr2[ind2])
           take = 1 + solve(ind1+1,ind2+1,cnt,arr1,arr2,dp);
        
        //skip1 
        solve(ind1+1,ind2,cnt,arr1,arr2,dp);
        solve(ind1,ind2+1,cnt,arr1,arr2,dp);

        cnt = max(cnt,take);

        return dp[ind1][ind2] = take;


    }
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        int ans = 0;

        vector<vector<int>> dp(n,vector<int>(m,-1));
        solve(0,0,ans,nums1,nums2,dp);
        return ans;
        
    }
};