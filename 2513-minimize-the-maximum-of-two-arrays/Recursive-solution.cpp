class Solution {
    int minn = 1e9;
    void solve(int i,int d1,int d2, int cnt1,int cnt2, set<pair<pair<int,int>,int>> &mem)
    {
        if(cnt1 == 0 && cnt2 == 0)  return;
        
        // int take1 = 1e9, take2 = 1e9, skip = 1e9;
        int s=0;
        
        // if(dp[i][cnt1][cnt2] != -1) return dp[i][cnt1][cnt2];
        //sort of memoization
        if(mem.count({{cnt1,cnt2},i}))  return;
        mem.insert({{cnt1,cnt2},i});
        
        if(i%d2 != 0 && cnt2 > 0)
        {
            s=1;
            if(cnt1 == 0 && cnt2 == 1)
            {
                minn = min(minn,i);
                return;
            }
            solve(i+1,d1,d2,cnt1,cnt2-1,mem);
        }
            
        
        if(i%d1 != 0 && cnt1 > 0)
        {
            s=1;
            if(cnt2 == 0 && cnt1 == 1)
            {
                minn = min(minn,i);
                return;
            }
            solve(i+1,d1,d2,cnt1-1,cnt2,mem);
        }
        
        if(!s)    solve(i+1,d1,d2,cnt1,cnt2,mem);
        
    }
public:
    int minimizeSet(int div1, int div2, int cnt1, int cnt2) {
        //i am thinking dp
        // vector<vector<vector<int>>> dp(1e9,vector<vector<int>>(cnt1+1,vector<int>(cnt2+1,-1)));
        set<pair<pair<int,int>,int>> mem;
        solve(1,div1,div2,cnt1,cnt2,mem);
        return minn;
        
        
    }
};