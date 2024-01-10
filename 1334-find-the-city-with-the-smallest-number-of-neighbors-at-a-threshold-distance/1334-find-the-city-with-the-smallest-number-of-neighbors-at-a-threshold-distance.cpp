class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dist) {
        //vector<int>adj(n,0);

        vector<vector<int>> grid(n,vector<int>(n,1e9));
        int m = edges.size();

        for(int i=0;i<n;i++)
            grid[i][i] = 0;

        //creating adj mtx
        for(int i=0;i<m;i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            int r = edges[i][2];

            grid[a][b] = r;
            grid[b][a] = r;

            //grid[i][i] = 0;
        }

        //FLOYD WARSHALL
        for(int a=0;a<n;a++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(grid[i][a] == 1e9 || grid[a][j] == 1e9) continue;

                    grid[i][j] = min(grid[i][j], grid[i][a] + grid[a][j]);
                }
            }
        }
        int minm = INT_MAX;
        int t=0;
        for(int i=0;i<n;i++)
        {
            int cnt =0;
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] <= dist)
                cnt++;
            }
            if(cnt<=minm)
            {
                minm = cnt;
                t = i;
            }
        }
        
        return t;
        
    }
};