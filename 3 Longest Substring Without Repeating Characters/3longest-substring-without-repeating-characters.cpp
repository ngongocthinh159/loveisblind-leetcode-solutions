class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> cnt;
        int repeat = 0;
        int l = 0, r = 0;
        int ans = 0;
        while (r < s.size()) {
            cnt[s[r]]++;
            if (cnt[s[r]]==2) repeat++;

            while (l < r && repeat > 0) {
                cnt[s[l]]--;
                if (cnt[s[l]]==1) repeat--;
                l++;
            }

            ans = max(ans,r-l+1);

            r++;
        }
        return ans;
    }
};