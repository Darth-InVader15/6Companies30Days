class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int>stt;
        unordered_map<int,int>mpp;
        for(auto x:arr)
        mpp[x]++;

        for(auto x:mpp)
            stt.insert(x.second);

        if(mpp.size() == stt.size())
        return true;
        
        return false;

        //return (arr.size() == stt.size() ? 0:1);
        
    }
};