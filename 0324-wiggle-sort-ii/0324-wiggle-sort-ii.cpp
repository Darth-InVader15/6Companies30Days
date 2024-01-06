class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        auto temp = nums;
        sort(temp.begin(),temp.end());
        
        int n = nums.size();
        int k = n-1;
        
        for(int i=1;i<n;i+=2)
        {
            nums[i] = temp[k]; 
            k--;
        }
        
        for(int i=0;i<n;i+=2)
        {
            nums[i] = temp[k];
            k--;
        }
        
    }
};