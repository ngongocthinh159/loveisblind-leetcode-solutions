class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string res(n + 1, ' ');
        res[0] = '1';
        int j = 1;
        int last = 0;
        for (int i = 0; i < n;) {
            if (pattern[i] == 'I') {
                res[last + 1] = ++j + '0';
                last++;
                i++;
            } else {
                int cnt = 0;
                while (i < n && pattern[i] == 'D') {
                    cnt++;
                    i++;
                }
                j--;
                for (int k = last + cnt; k >= last; k--) res[k] = ++j + '0';
                last = last + cnt;
            }
            // cout << res << " " << last << "\n";
        }
        return res;
    }
};