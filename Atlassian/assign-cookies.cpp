class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (s.empty())  return 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int cnt = 0;
        int j = 0;
        int n = g.size();
        int m = s.size();

        for(int i=0;i<n;i++)
        {
            if(g[i] <= s[j])    cnt++;
            else
            {
                while(j < m && g[i] > s[j])  j++;

                if(j < m) cnt++;
            }

            j++;
            if(j >= m) break;
        }

        return cnt;
        
    }
};