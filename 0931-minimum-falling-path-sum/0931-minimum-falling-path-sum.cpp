class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        //We'll run a loop starting from each pt on the 1st row
        // Down left, down, Down right
        //We'll run till we reach the bottom most row
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,1e9));
        
        for(int i=0;i<n;i++)
            dp[0][i] = matrix[0][i];

        //for upleft ele -> j>0
        //for up ele -> all j
        //for upright el -> j<n-1

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int temp = matrix[i][j];
                int uplt = 1e9, up=1e9, uprt = 1e9;
                
                if(j>0)
                    uplt = dp[i-1][j-1];
                up = dp[i-1][j];
                if(j<n-1)
                    uprt = dp[i-1][j+1];

                int minn = min(uplt,uprt);
                minn = min(minn,up);
                minn +=temp;
                dp[i][j] = minn;    
            }
        }
        int ans = 1e9;
        for(int i=0;i<n;i++)
        {
            ans = min(ans,dp[n-1][i]);
        }
        return ans;
        
    }
};