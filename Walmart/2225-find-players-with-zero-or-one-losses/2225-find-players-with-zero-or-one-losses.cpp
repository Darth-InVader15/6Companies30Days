class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> wins(1e5+1,0);
        vector<int> loss(1e5+1,0);
        vector<vector<int>> ans(2);
        for(auto x: matches)
        {
            wins[x[0]]++;
            loss[x[1]]++;
        }

        for(int i=1;i<=1e5;i++)
        {
            if(wins[i] > 0 && loss[i] == 0)   ans[0].push_back(i);
            else if(loss[i] == 1) ans[1].push_back(i);
        }

        return ans;
        
    }
};