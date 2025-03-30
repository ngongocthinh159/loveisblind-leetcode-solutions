class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size(), l = 0, r = 0;
        vector<int> last(26);
        for (int i = 0; i< n; i++) last[s[i] - 'a'] = i;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            r = max(r, last[s[i] - 'a']);
            if (i == r) {
                res.push_back(r - l + 1);
                l = i + 1;
            }
        }
        return res;
    }
};