class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        int n = startWords.size();
        int count = 0;
        std::unordered_set<std::string> set;

        // 1. store lexicographically sorted letters of startword in set
        for (const auto& start : startWords) {
            std::string sortedStart = start;
            std::sort(sortedStart.begin(), sortedStart.end());
            set.insert(sortedStart);
        }

        int m = targetWords.size();
        bool ans = false;
        for (int i = 0; i < m; i++) {
            // 2. sort lexicographically letters of targetword and store in new
            // string s
            std::string sortedTarget = targetWords[i];
            std::sort(sortedTarget.begin(), sortedTarget.end());

            int k = sortedTarget.length();

            ans = false;
            for (int j = 0; j < k; j++) {
                // 3. make a new string by omitting one letter from word and
                // check if it is present in set than increase count value
                string str =
                    sortedTarget.substr(0, j) + sortedTarget.substr(j + 1);
                if (set.find(str) != set.end()) {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};