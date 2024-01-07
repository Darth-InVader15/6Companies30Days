class Solution {
public:
    int findTheWinner(int n, int k) {
        int curr = 0;
        k--;
        unordered_set<int> stt;
        
        while(stt.size() != n-1)
        {
            int temp = k;
            
            while(temp > 0)
            {
                if(!stt.count(curr)) temp--;
                curr = (curr+1)%n;
                while(stt.count(curr)) curr = (curr+1)%n;
            }
                
            stt.insert(curr);
            curr = (curr+1)%n;
            
            while(stt.count(curr)) 
                curr = (curr+1)%n;
            
        }
        return curr+1;
        
    }
};