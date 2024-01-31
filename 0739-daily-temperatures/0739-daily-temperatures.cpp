class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        stack<pair<int,int>> stk;
        int n = temps.size();
        vector<int> ans(n,0);

        for(int i=0;i<n;i++)
        {
            if(!stk.empty())
            {
                while(!stk.empty() && stk.top().first < temps[i])
                {
                    auto pr = stk.top();
                    ans[pr.second] = i-pr.second;
                    stk.pop();
                }
            }
            stk.push({temps[i],i});
        }
        return ans;
    }
};