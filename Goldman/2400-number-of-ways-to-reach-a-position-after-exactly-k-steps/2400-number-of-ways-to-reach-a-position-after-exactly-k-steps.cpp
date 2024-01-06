class Solution {
    int mod = 1e9 + 7;
    int solve(int strt,int endd, int k, vector<vector<int>> &dp,int c)
    {
        if(k == 0)
        {
            if(strt == endd)    return 1;
            return 0;            
        }
        
        if(dp[strt+c][k] != -1) return dp[strt+c][k];
        
        int movlt = 0, movrt = 0;
        
        movlt = solve(strt-1,endd,k-1,dp,c)%mod;
        movrt = solve(strt+1,endd,k-1,dp,c)%mod;
        
        return dp[strt+c][k] = (movlt+movrt)%mod;
    }
public:
    int numberOfWays(int startPos, int endPos, int k) {
        int l = 2*k;
        int r = 2002 + l;
        // vector<vector<vector<int>>> dp(r ,vector<vector<int>>(r,vector<int>(k+1,-1)));
        vector<vector<int>> dp(r,vector<int>(k+1,-1));
        
        return solve(startPos,endPos,k, dp,r/2);
        
    }
};