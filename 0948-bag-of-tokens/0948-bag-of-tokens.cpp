class Solution {
public:
// saw the 3rd tc, got the approach
// sort then keep moving the shorter point ahead if power permits to increase score
// if power less, increase it by using the largest token (2 pointer use hoga)
// have a real bad headache, going to sleep, so just took the first code that used my approach
    int bagOfTokensScore(vector<int>& tokens, int power) {
         if (tokens.empty()) return 0;//edge case
        sort(begin(tokens),end(tokens));
        if(power<tokens[0]) return 0;
        int l=0, r=tokens.size()-1;
        int score=0;
        while(l<=r){// If power is infinity l can be r
            while (l<=r && power>=tokens[l]){
               power-=tokens[l];
               l++;
               score++;
            }
        //    maxScore=max(maxScore, score);
            if (l<r && score>0) { 
                power+= tokens[r--];
                score--;
            }
            else break;
        }
        return score; 
    }
};