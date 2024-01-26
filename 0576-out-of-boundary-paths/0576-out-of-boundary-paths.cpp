class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int mod = 1e9+7;
    int solve(int x, int y, int move, int m, int n, vector<vector<vector<int>>> &vis)
    {
        if(x<0 || y<0 || x>= m || y>= n)    return 1;
        if(move == 0)   return move;
        int ans = 0;

        if(vis[move][x][y] != -1)   return vis[move][x][y];
        
        for(int i=0;i<4;i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];

            ans = (ans + solve(tx,ty,move-1,m,n,vis))%mod;
        }
        return vis[move][x][y] = ans%mod;
    }
    int findPaths(int m, int n, int move, int r, int c) {
        vector<vector<vector<int>>> vis(move+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(r,c,move,m,n,vis);
        
    }
};