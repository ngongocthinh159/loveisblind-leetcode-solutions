class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int cnt[26] = {0};
        for (auto word : words) {
            for (auto c : word) {
                cnt[c - 'a']++;
            }
        }
        for (auto num : cnt) {
            if (num != 0 && (num < words.size() || num%words.size() != 0)) return false;
        }
        return true;
    }
};