class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> S;
        int n = nums.size();
        for (auto &s : nums) {
            int cur = 0;
            for (int bit = n - 1; bit >= 0; bit--) {
                if (s[n - 1 - bit] == '1') cur |= (1 << bit);
            }
            S.insert(cur);
        }
        string res(n, '0');
        for (int i = 0; i <= n; i++) if (!S.count(i)) {
            for (int bit = n - 1; bit >= 0; bit--) if ((i >> bit) & 1) res[n - bit - 1] = '1';
            break;
        }
        return res;
    }
};