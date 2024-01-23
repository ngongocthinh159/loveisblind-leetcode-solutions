class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<pair<int,int>> v;
        for (auto &s : arr) {
            bool ok = true;
            int cur = 0;
            for (int i = 0; i < s.size(); i++) {
                int bit = s[i] - 'a';
                if (cur & (1 << bit)) {ok = false; break;}
                cur = cur | (1 << bit);
            }
            if (ok) v.push_back({cur, s.size()});
        }
        int ans = INT_MIN;
        for (int counter = 0; counter <= pow(2, v.size()) - 1; counter++) {
            int combination = counter; int bit = 0;
            bool ok = true;
            int len = 0;
            int cur = 0;
            while (combination != 0) {
                if (combination&1) {
                    if (cur & v[bit].first) {ok = false; break;}
                    else {
                        cur |= v[bit].first;
                        len += v[bit].second;
                    }
                }

                combination >>= 1;
                bit++;
            }
            if (ok) ans = max(ans, len);
        }
        return ans;
    }
};