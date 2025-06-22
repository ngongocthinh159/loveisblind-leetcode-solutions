class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        int g = (n + k - 1) / k;
        vector<string> res(g);
        for (int i = 0, j = 0; i < g; i++) {
            int cnt = 0;
            while (j < n && cnt < k) res[i] += s[j], cnt++, j++;
            while (cnt < k) res[i] += fill, cnt++;
        }
        return res;
    }
};