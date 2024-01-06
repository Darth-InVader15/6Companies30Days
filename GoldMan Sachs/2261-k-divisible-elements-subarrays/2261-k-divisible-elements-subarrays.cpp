class Solution {
    int genSubs(vector<int> &nums, int t, int p)
    {
        // 1 2 3 4 -> 1 2 3 4 12 13 14 123 124 
        int n = nums.size();
        set<vector<int>> stt;

        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                vector<int> sub;
                int cnt = 0;
                for(int k=i;k<=j;k++)
                {
                    sub.push_back(nums[k]);
                    if(nums[k] % p == 0)    cnt++;
                }
                if(cnt <= t)
                stt.insert(sub);
            }
        }
        return stt.size();
    }
public:
    int countDistinct(vector<int>& nums, int k, int p) { 
        
        return genSubs(nums,k,p);

        //--------------Bruting my way to the AC----------------------------------
        
        // deque<int> dq; 
        // int cnt = 0;
        // int ans = 0;
        // set<vector<int>> stt;

        // for(int i=0;i<nums.size();i++)
        // {
        //     int x = nums[i];
        //     dq.push_back(x);
        //     if(x == p)  cnt++;

        //     if(cnt == k || i == nums.size()-1)
        //     {
        //         int s = dq.size();
        //         int sum = (s*(s+1))/2;

        //         cout<<s<<" "<<sum<<endl;

        //         ans += sum;

        //         while(dq.front() != p)  dq.pop_front();
        //         dq.pop_front();
        //     }
        // }
        // return ans;


    }
};