class Solution {
    vector<vector<int>> ans;
    void solve(int i, int k,int n, vector<int> &anss)
    {
        if(k == 0)
        {
            if(n==0)    ans.push_back(anss);
            return;
        }
        if(i>9) return;
        
        // if(dp[i][k][n] != -1)   return;
        // dp[i][k][n] = 1;
        
        
        if(n-i >= 0)
        {  
            anss.push_back(i);
            solve(i+1,k-1,n-i,anss,dp);
            anss.pop_back();
        }
        solve(i+1,k,n,anss);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> anss;
        // vector<vector<vector<int>>> dp(10,vector<vector<int>>(k+1,vector<int>(n+1,-1)));
        
        solve(1,k,n,anss);
        return ans;
        
        
    }
};
