class Solution{
public:

static bool comp(const vector<int> &v1,const vector<int> &v2)
    {
        if(v1[0] == v2[0])
        {
            return v1[1] > v2[1];
        }
        //this is to ease our search by just working on the second ele
    //as we need LIS, but both length and width should be increased, so 
    //we sort by keeping one in ascending order and other in descending
    //so if we select a ht, for same ht, the elements ahead of it will have less width
    //thus wont affect our LIS.
        else
        return v2[0] > v1[0];
    }

    //Lis with bin search method
    // We basically sort the arr and then search for ele larger than curr ele
    // using bin search(lower bound)

    int maxEnvelopes(vector<vector<int>>& envelopes) {
    int n = envelopes.size();
        sort(envelopes.begin(),envelopes.end(),comp);
        vector<int>arr;
        for(int i =0;i<n;i++)
        {
            if(arr.empty() || arr.back()<envelopes[i][1])
                arr.push_back(envelopes[i][1]);
            else
            {
                int index = lower_bound(arr.begin(),arr.end(),envelopes[i][1])
                        -   arr.begin();
                arr[index] = envelopes[i][1];
            }
        }
        
        return arr.size();
    }
};