class Solution {
    // static bool pvt(pair<string,int> &pa, pair<string,int> &pb)
    // {
    //     string a = pa.first;
    //     string b = pb.first;
    //     int n = a.size();
        
    //     for(int i=0;i<n;i++)
    //     {
    //         int aa = a[i]-'0';
    //         int bb = b[i]-'0';
            
    //         if(aa == bb)    continue;
    //         return (aa<=bb); 
    //     }
    //     return (pa.second < pb.second);
    // }
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& q) {
       vector<int> res;
        for(auto x:q)
        {
            priority_queue<pair<string,int>> v;
            for(int i=0;i<nums.size();i++)
            {
                int t=nums[i].length()-x[1];
                string p=nums[i].substr(t,x[1]);
                if(v.size()<x[0])
                    v.push({p,i});
                else
                {
                    if(v.top().first > p)
                    {
                        v.pop();
                        v.push({p,i});
                    }
                }
            }
            int val=v.top().second;
            res.push_back(val);
        }
        return res;
    }
        
        // for(auto x:q)
        // {
        //     int trim = x[1];
        //     int k = x[0]-1;
            
        //     ans.push_back(mpp[trim][k].second);
        // }

        // return ans;
        
};