class ThroneInheritance {
public:
    map<string,vector<string>> mpp;
    string king = "";
    unordered_set<string> ded;
    ThroneInheritance(string kingName) {
        king = kingName;        
    }
    
    void birth(string parentName, string childName) {
        mpp[parentName].push_back(childName);
        
    }
    
    void death(string name) {
        ded.insert(name);        
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        solve(king,ans);
        return ans;
    }
    void solve(string &parent, vector<string> &ans)
    {
        int n = mpp[parent].size();
        if(!ded.count(parent))
        ans.push_back(parent);
        
        for(int i=0;i<n;i++)
        {
            string temp = mpp[parent][i];
            // ans.push_back(temp);
            // if(mpp[temp].size() != 0)   
            solve(temp,ans);
        }

    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */