class DataStream {
public:
    deque<int> dq;
    unordered_map<int,int> mpp;
    int val=0, t=0;
    DataStream(int value, int k) {
        val = value;
        t = k;        
    }
    
    bool consec(int num) {
        
        while(dq.size() >= t)
        {
            mpp[dq.front()]--;
            dq.pop_front();
        }
        
        dq.push_back(num);
        mpp[num]++;
        
        if(dq.size() == t)
        {
            if(mpp[val] == t)   return 1;
        }
        return 0;       
        
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */