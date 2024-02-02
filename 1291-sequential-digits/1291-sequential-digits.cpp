class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        auto teml = to_string(low);
        auto temh = to_string(high);
        
        int lo = teml.size();
        int hi = temh.size();

       
        vector<int> ans;

        //varying the number of digits
        for(int i=lo;i<=hi;i++)
        {
            for(int j=1;j<=(10-i);j++)
            {
                string anss = "";
                for(int k=0;k<i;k++)
                {
                    anss += ((j+k) + '0');
                }
                int temp = stoi(anss);
                // int temp = 0;
                if(temp >= low && temp <= high) ans.push_back(temp);

            }
        }
        return ans;
        
    }
};