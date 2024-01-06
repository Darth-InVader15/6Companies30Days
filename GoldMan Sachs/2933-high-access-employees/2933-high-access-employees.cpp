class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& att) {
        unordered_map<string,vector<int>> mpp;
        
        for(auto x: att)
        {
            mpp[x[0]].push_back(stoi(x[1]));
        }
        
        for(auto& itr: mpp)  // Use a reference to modify the values in the map
        {
            sort(itr.second.begin(), itr.second.end());
        }
        vector<string> ans;
        
        for(auto& itr: mpp)  // Use a reference to access the values in the map
        {
            int n = itr.second.size();
            auto& str = itr.second;  // Use a reference to the vector of integers
            string s = itr.first;
            
            if(n < 3) continue;
            
            deque<int> dq;
            
            for(int i = 0; i < n; ++i)
            {
                dq.push_back(str[i]);
                
                while(dq.size() > 3)   dq.pop_front();
                
                if(dq.size() == 3)
                {
                    int a = dq.front();
                    int b = dq.back();
                    
                    if(b - a < 100)
                    {
                        ans.push_back(s);
                        break;
                    }
                }        
            }
        }
        return ans;
    }
};
