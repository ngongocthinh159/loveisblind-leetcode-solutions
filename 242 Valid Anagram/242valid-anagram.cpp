class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cnt(26, 0);
        for (char& c : s) {
            cnt[c - 'a']++;
        }
        for (char& c : t) {
            --cnt[c - 'a'];
        }
        for (int _cnt : cnt) {
            if (_cnt!=0) return false;
        }
        return true;
    }
};