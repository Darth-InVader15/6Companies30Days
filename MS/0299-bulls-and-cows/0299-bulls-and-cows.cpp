class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cow = 0;
        int n = secret.size();
        
        for(int i=0;i<n;i++)
        {
            if(secret[i] == guess[i])   bulls++;
        }
        
        vector<int> a(10),b(10);
        
        for(auto x:secret)  a[x-'0']++;
        for(auto x:guess)   b[x-'0']++;
        
        for(int i=0;i<10;i++)
            cow += min(a[i],b[i]);
        
        cow-= bulls;
        
        string ans = to_string(bulls);
        ans += "A";
        ans += to_string(cow) + "B";
        return ans;
        
    }
};