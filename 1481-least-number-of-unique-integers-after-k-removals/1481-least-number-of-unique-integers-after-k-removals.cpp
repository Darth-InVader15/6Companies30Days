class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& ar, int k) {
        unordered_map<int,int> mpp;

        for(auto x: ar)    mpp[x]++;
        vector<int> arr;

        for(auto itr:mpp)
        {
            arr.push_back(itr.second);
        }
        sort(arr.begin(),arr.end());
        int i = 0;
        
        while(k)
        {
            if(arr[i] <= k)
            {
                k -= arr[i];
                i++;
            }
            // else if(arr[i] == k)    k-= arr[i];
            else break;
        }
        return arr.size() - (i);
    }
};