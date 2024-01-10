class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) 
    {
        int n = nums.size();
        set<vector<int>> stt;

        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                int prev = -1;
                for(int k=0;k<=n;k++)
                {
                    if(k>=i && k<=j)    continue;

                    if(k == n)
                    {
                        vector<int> anss;
                        for(int a=i;a<=j;a++)   anss.push_back(a);
                        stt.insert(anss);
                        break;
                    }
                    if(prev == -1 || nums[k] > prev)
                    {
                        prev = nums[k];
                    }
                    else    break;
                }
            }
        }
        return stt.size();
    
        
        
    }
};