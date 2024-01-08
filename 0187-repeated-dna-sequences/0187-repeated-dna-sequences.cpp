class Solution {
public:
    vector<string> findRepeatedDnaSequences(string str) {
        unordered_map<string,int> stt;
        vector<string> ans;
        int k=0;
        
        int n = str.size();
        int strt = 0, endd = 10;
        // cout<<str.substr(0,10);
        
        while(strt + k <= n-10)
        {
            string temp = str.substr(strt+k,10);
            // cout<<temp<<"\n";
            
            // if(stt.count(temp)) ans.push_back(temp);
            if(stt[temp] == 1)  ans.push_back(temp);
            stt[temp]++;
            k++;
        }
            
        return ans;
    }
};