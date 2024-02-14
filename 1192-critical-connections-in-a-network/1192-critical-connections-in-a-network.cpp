class Solution {
    int timer = 0;
    void dfs(int node, int par, vector<vector<int>> &adj, vector<int> &low,
             vector<int> &curr, vector<int> &vis, vector<vector<int>> &ans)
    {
        vis[node] = 1;
        low[node] = timer;
        curr[node] = timer;
        timer++;

        for(auto x:adj[node])
        {
            if(x == par)    continue;
            if(!vis[x])
            {
                dfs(x,node,adj,low,curr,vis,ans);
                low[node] = min(low[node],low[x]);

                if(curr[node] < low[x])
                {
                    ans.push_back({min(node,x),max(node,x)});

                }
            }
            else low[node] = min(low[node],curr[x]);
        }


    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //apparently this is done using tarjan's algo
        // we maintain a timer, and start dfs from a starting node,
        // maintain the time at we reached each node
        // also maintain the lowest time at which we can reach that node
        // striver has a better explanation video
        vector<vector<int>> adj(n);

        for(auto x: connections)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> low(n),curr(n),vis(n,0);
        vector<vector<int>> ans;

        dfs(0,-1,adj,low,curr,vis,ans);
        return ans;
    }
};