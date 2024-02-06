class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // we will travel every str, sort and increment the mpp
        // for the ans, we will travel the map and store them in a array

        unordered_map<string,vector<string>> mpp;
        for(auto x:strs)
        {
            auto temp = x;
            sort(x.begin(),x.end());
            mpp[x].push_back(temp);
        }
        vector<vector<string>> ans;
        for(auto itr:mpp)
        {
            ans.push_back(itr.second);
        }
        return ans;


        
        
    }
};