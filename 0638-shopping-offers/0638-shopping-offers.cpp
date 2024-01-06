class Solution {
    int solve(int ind, vector<int> &cost, vector<int> &req, vector<vector<int>> &sp, map<vector<int>,int> &dp)
    {   
        int n = cost.size();
        if(ind >= n) return 0;
        
        // if(dp[ind][req[ind]] != -1)  return dp[ind][req[ind]];
        if(dp.count(req)) return dp[req];
        
        int take = 1e9, skip = 0;
        
        for(auto &x: sp)
        {
            int temp =-1;
            int s = 0;
           for(int i=0;i<n;i++)
           {
               if(req[i] < x[i])    s=1;   
           }
            
            if(!s)
            {
                for(int i=0;i<n;i++)    req[i] -= x[i];
                
                if(req[ind] == 0)
                temp = x[n] + solve(ind+1,cost,req,sp,dp);
                else
                temp = x[n] + solve(ind,cost,req,sp,dp);
                
                for(int i=0;i<n;i++)    req[i] += x[i];
            }
            
            if(temp != -1)
            take = min(take,temp);
        }
        
        //if not taking the sp price
        long long price = cost[ind] * req[ind];
        skip = price + solve(ind+1,cost,req,sp,dp);
        
        return dp[req] = min(skip,take);
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();
        
        // vector<vector<int>> dp(n,vector<int>(11,-1));
        map<vector<int>, int> dp;
        return solve(0,price,needs,special,dp);
        
    }
};