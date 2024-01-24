class Solution {
    void chk(vector<int> &arri, vector<int> &arrj, int k, vector<int> &ans)
    {
        for(auto x: arri)
        {
            auto lower = lower_bound(arrj.begin(), arrj.end(), x - k);
            if(lower != arrj.end()) // 
            {
                int ele = *lower;
                if(abs(ele-x) > k) continue;

                ans.push_back(x);
                continue;
            }
            auto upper = upper_bound(arrj.begin(), arrj.end(), x + k);

            if(upper != arrj.end())
            {
                int ele = *upper;
                if(abs(ele-x) > k) continue;

                ans.push_back(x);
                continue;
            }
        }
    }
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int ns = s.size();
        int na = a.size();
        int nb = b.size();

        vector<int> arri;
        vector<int> arrj;

        

        for(int i=0;i<ns-na+1;i++)
        {
            if(s.substr(i,na) == a) arri.push_back(i);
        }
        for(int j=0;j<ns-nb+1;j++)
        {
            if(s.substr(j,nb) == b) arrj.push_back(j);
        }
        // for(auto x: arri)
        // {
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // for(auto x: arrj)
        // {
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // we have i and j in sorted order now
        vector<int> ans;
        chk(arri, arrj, k, ans);


        //     // if(x == 33)
        //     // {
        //     //     for(auto x:arrj)    cout<<x<<" ";
        //     //     cout<<endl;
        //     // }
        // }
        return ans;
        
    }
};