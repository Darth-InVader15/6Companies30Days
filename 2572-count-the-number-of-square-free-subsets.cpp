#define ll long long
//bit mask solution
class Solution {
public:
    int memo[1001][1024];
    vector<int>vec={2,3,5,7,11,13,17,19,23,29}; //prime nums before 30
    ll mod=1e9+7;
    ll dp(vector<int>&nums,int i,int mask)
    {
        if(i==nums.size()) return 1;
        if(memo[i][mask]!=-1) return memo[i][mask];
        int temp=mask,flag=1;
        for(int j=0;j<10;j++)
        {
            int num=nums[i],count=0;
            while(num%vec[j]==0)  num/=vec[j], count++; //we find the prime factors
            if(count>=2 or ((count==1) and ((mask>>j)&1)))  // mask has 10 bits, representing the 10 factors
            {                                        // so if anyone of the bit is > 1, we know not to take it            
                flag=0;
                break;
            }
            if(count) temp=temp|(1<<j);
        }
        int take = 0, dont = 0;
        if(flag)
            take = dp(nums,i+1,temp)%mod;
        
        dont =dp(nums,i+1,mask) %mod;
        
        return memo[i][mask] = (take + dont)%mod;
        
    }
    
    int squareFreeSubsets(vector<int>& nums) 
    {
        memset(memo,-1,sizeof(memo));
        return 1LL*(dp(nums,0,0)-1+mod)%mod;  
    }
};