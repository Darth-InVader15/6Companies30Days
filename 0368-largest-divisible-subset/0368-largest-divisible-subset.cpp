class Solution {
            //Similar to print all LIS
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        // Initial lenght of all subseq as 1
        vector<int> dp(n+2,1);
        // For storing the prev ele
        unordered_map<int,int> last;

        int maxx = 0;
        int maxi = 0;
        sort(nums.begin(), nums.end());
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0)
                {
                    //If the subseq with j has more ele, we will adopt that subseq
                    if(dp[i] < dp[j]+1)
                    {
                        last[i] = j;
                        dp[i] = dp[j]+1;  
                    }
                }
            }
            // maxx dp[i] will be that of the LIS
            if(dp[i] > maxx)
            {
                maxx = dp[i];
                maxi = i;
            }
        }

        vector<int> ans;
        ans.push_back(nums[maxi]);
        while(last.find(maxi) != last.end())
        {
            int ind = last[maxi];
            ans.push_back(nums[ind]);
            maxi = last[maxi];
        }
        return ans; 
    }
};