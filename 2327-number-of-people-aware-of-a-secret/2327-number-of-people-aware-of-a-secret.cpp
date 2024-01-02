class Solution {
public:
    int mod = 1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> q(n+1,0);
        long long cnt = 0;

        if(1+forget > n)cnt++;

        q[1] = 1;
        
        for(int i=1;i<n+1;i++)
        {
            if(q[i] == 0)   continue; //No one is told on tis day

            int currNum = q[i];
            int curr = i;

            int lt = min(n+1,curr+forget);

            for(int j = curr+delay;j<lt;j++)
            {
                if(j+forget > n)    cnt = (cnt + currNum)%mod;
                if(j<n+1) q[j]= (q[j] +  currNum)%mod;
            }
        }
        
        return cnt;
        
    }
};


// while(!q.empty())
//         {
//             auto curr = q.front();
//             q.pop();

//             int lt = min(n+1,curr+forget); //either our mate will forget, or we will reach the end date;

//             for(int i=curr+delay;i<lt;i++)
//             {
//                 if(i+forget > n)
//                 cnt++;
//                 q.push(i);
//             }
//         }