class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> mx_freq(26);
        for (auto &w : words2) {
            vector<int> freq(26);
            for (auto c : w) freq[c - 'a']++;
            for (int i = 0; i < 26; i++) mx_freq[i] = max(mx_freq[i], freq[i]);
        } 
        vector<string> ans;
        for (auto &w : words1) {
            vector<int> freq(26);
            for (auto c : w) freq[c - 'a']++;
            bool ok = true;
            for (int i = 0; i < 26; i++) if (freq[i] < mx_freq[i]) {
                ok = false;
                break;
            }
            if (ok) ans.push_back(w);
        }
        return ans;
    }
};