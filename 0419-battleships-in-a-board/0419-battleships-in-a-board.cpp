class Solution {
    void chk(int i, int j, vector<vector<char>> &arr, vector<vector<int>> &vis)
    {
        int m = arr.size();
        int n = arr[0].size();

        if((j > 0 && arr[i][j-1] == 'X') || (j<n-1 && arr[i][j+1] == 'X'))
        {
            for(int k = j-1;k>=0;k--)
            {
                if(arr[i][k] == 'X')    vis[i][k] = 1;
                else break;
            }
            for(int k=j+1;k<n;k++)
            {
                if(arr[i][k] == 'X')    vis[i][k] = 1;
                else break;
            }
        }
        else if((i > 0 && arr[i-1][j] == 'X') || (i<m-1 && arr[i+1][j] == 'X'))
        {
            for(int k = i-1;k>=0;k--)
            {
                if(arr[k][j] == 'X')    vis[k][j] = 1;
                else break;
            }
            for(int k=i+1;k<m;k++)
            {
                if(arr[k][j] == 'X')    vis[k][j] = 1;
                else break;
            }
        }
    }
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int cnt = 0;
        vector<vector<int>> vis(m,vector<int>(n,0));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[i][j]) continue;
                
                if(board[i][j] == 'X')
                {
                    chk(i,j,board,vis);
                    cnt++;
                }
                vis[i][j] = 1;
            }
        }
        return cnt;
        
    }
};