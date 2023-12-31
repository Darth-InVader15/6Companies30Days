class Solution {
private:
    void solve(int ind,string str,vector<string> &ans, string anss, unordered_map<int,string> &dataB)
    {
        if(ind >= str.size())
        {
            ans.push_back(anss);
            return;
        }

        for(char x : dataB[str[ind] - '0'])
        {
            // cout<<x<<"\n";
            anss.push_back(x);
            solve(ind+1,str,ans,anss,dataB);
            anss.pop_back();
        }

    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        //Edge Case 1
        if(digits.size() == 0)
        return ans;

        //Database of all the key mappings
        unordered_map<int, string> dataB;
        dataB[2] = "abc";
        dataB[3] = "def";
        dataB[4] = "ghi";
        dataB[5] = "jkl";
        dataB[6] = "mno";
        dataB[7] = "pqrs";
        dataB[8] = "tuv";
        dataB[9] = "wxyz";

        //To store temporary strings
        string anss="";

        solve(0,digits,ans,anss,dataB);
        return ans;        
        
    }
};