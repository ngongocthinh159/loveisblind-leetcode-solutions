class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        vector<int> cnt(10e5 + 1, 0);
        for (auto x :nums) cnt[x]++;
        int ok = 0, start, ans = 0;
        for (int i = 0; i < cnt.size(); i++) {
            if (cnt[i] == 0) continue;
            start = max(ok, i);
            
            ans += (start - i)*cnt[i] + (cnt[i] - 1)*cnt[i]/2;

            ok = start + cnt[i];
        }
        return ans;
    }
};