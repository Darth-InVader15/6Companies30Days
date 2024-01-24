class KthLargest {
public:
    multiset<int> stt;
    int x = 0;
    KthLargest(int k, vector<int>& nums) {
        stt.insert(nums.begin(),nums.end());
        x = k;        
    }
    
    int add(int val) {
        stt.insert(val);

        auto itr = stt.rbegin();
        int k = x-1;

        while(k--)
            itr = next(itr);

        return *itr;
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */