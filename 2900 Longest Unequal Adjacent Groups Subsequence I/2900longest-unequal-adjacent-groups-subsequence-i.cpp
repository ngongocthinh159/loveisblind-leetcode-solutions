class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        int prev = -1;
        vector<string> res;
        for (int i = 0; i < n; i++) {
            if (groups[i] != prev) {
                res.emplace_back(move(words[i]));
                prev = groups[i];
            }
        }
        return move(res);
    }
};