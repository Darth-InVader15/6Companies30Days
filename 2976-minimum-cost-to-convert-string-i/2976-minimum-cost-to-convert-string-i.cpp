class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        //         int n = tar.size();
        
//         unordered_map<char,vector<pair<int,char>>> mpp;
//         long long ans = 0;
        
//         for(int i=0;i<ori.size();i++)
//         {
//             mpp[ori[i]].push_back({cost[i],chan[i]});
//         }
//         // i am thinking Djikstra for each char///
        
//         for(int i=0;i<src.size();i++)
//         {
//             if(src[i] == tar[i]) continue;
            
//             priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>> pq;
//             pq.push({0,src[i]});
//             // unordered_set<char> stt;
//             // char curr = "";
//             vector<long long> vis(26,1e9);
//             while(!pq.empty())
//             {
//                 char curr = pq.top().second;
//                 int dist = pq.top().first;
//                 pq.pop();
                
//                 if(vis[curr-'a'] > dist)    vis[curr-'a'] = dist;
//                 else continue;
                
//                 if(curr == tar[i])
//                 {
//                     ans += dist;
//                     break;
//                 }
                
//                 for(auto x: mpp[curr])
//                 {
//                     // if(stt.count(curr)) continue;
//                     pq.push({x.first+dist,x.second});
//                 }
//             }
//             if(vis[tar[i] - 'a'] == 1e9) return -1;
//         }
//         return ans;
        //////////////////////////////////////////////
        //FLOYD WARSHAL
        vector<vector<int>> A(26, vector<int>(26, 1e8));
        for(int i = 0; i < 26; i++) A[i][i] = 0;
        for(int i = 0; i < original.size(); i++) {
            A[original[i] - 'a'][changed[i] - 'a'] = min(A[original[i] - 'a'][changed[i] - 'a'], cost[i]);
        }
        for(int k = 0; k < 26; k++) {
            for(int i = 0; i < 26; i++) {
                for(int j = 0; j < 26; j++) {
                    A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
                }
            }
        }
        long long ans = 0;
        for(int i = 0; i < source.size(); i++) {
            if(A[source[i] - 'a'][target[i] - 'a'] >= 1e8) return -1;
            ans += A[source[i] - 'a'][target[i] - 'a'];
        }
        return ans;

        
    }
};