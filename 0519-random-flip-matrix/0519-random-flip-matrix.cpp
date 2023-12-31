class Solution {
    int r,c;
    set<pair<int,int>> stt;
public:
    Solution(int m, int n) {
        r = m, c = n;
        
    }
    
    vector<int> flip() {
        
        while(1)
        { 
            int i = rand()%r;
            int j = rand()%c;

            if(!stt.count({i,j}))
            {
                stt.insert({i,j});
                return {i,j};
            }
        }
        return {0,0};
        
    }
    
    void reset() {
        stt.clear();
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */