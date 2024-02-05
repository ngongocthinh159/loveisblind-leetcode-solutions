class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>cnt(26,0);
        for (auto c : s) {
            cnt[c-'a']++;
        }
        int i = 0;
        for (auto c : s) {
            if (cnt[c-'a']==1) return i;
            i++;
        }
        return -1;
    }
};