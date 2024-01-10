class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
      int n = nums.size();
        int pref = 0;
        int cnt =0;
        unordered_map<int,int> mpp;

        for(int i=0;i<n;i++)
        {
            if(nums[i] &1)
                pref++;
            
            if(pref == k)
                cnt++;
            
            if(pref >= k)
            {
                cnt+= mpp[pref-k];
            }
            mpp[pref]++;
        }
        return cnt;
    }
};