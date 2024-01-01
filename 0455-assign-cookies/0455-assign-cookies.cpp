class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());

        int cnt = 0;
        int k = 0;
        for(int i=0;i<g.size();i++)
        {
            if(k>=s.size())
                break;
            if(g[i] <= s[k])
            {
                cnt++;
                k++;
            }
            else
            {
                while(k < s.size() && g[i] > s[k])
                    k++;
                if(k == s.size())
                    break;
                else
                {
                    k++;
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};