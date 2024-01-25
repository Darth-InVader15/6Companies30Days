class Solution {
    int solve(int i, int j,string &str1, string &str2, vector<vector<int>> &dp)
    {
        if(i >= str1.size() || j >= str2.size())    return 0;

        if(dp[i][j] != -1)  return dp[i][j];

        int take = 0, dont = 0, skip= 0;

        if(str1[i] == str2[j])  take = 1 + solve(i+1,j+1, str1,str2,dp);
        
        dont = solve(i+1,j,str1,str2,dp);
        skip = solve(i,j+1,str1,str2,dp);

        return dp[i][j] = max({take,skip,dont}) ;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n,vector<int>(m,-1));

        return solve(0,0,text1,text2,dp);
        
    }
};