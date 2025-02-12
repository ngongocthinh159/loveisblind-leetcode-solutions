class Solution {
public:
    long long appealSum(string s) {
        int n = s.size();
        s += '#';
        vector<int> last(26, n);
        long long ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            int r = (s[i + 1] == s[i] ? i + 1 : last[s[i] - 'a']) - 1;
            int len1 = (r - i + 1);
            int len2 = i + 1;
            ans += 1LL*len1*len2;

            last[s[i] - 'a'] = i;
        }
        return ans;
    }
};