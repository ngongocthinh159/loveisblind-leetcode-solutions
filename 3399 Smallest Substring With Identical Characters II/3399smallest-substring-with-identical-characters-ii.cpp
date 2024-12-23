class Solution {
public:
    bool check(int len, string s, int opers) {
        int i = 0;
        int n = s.size();
        while (i < n) {
            char c = s[i];
            int cur_cnt = 0;
            while (i < n && s[i] == c) {
                cur_cnt++;
                i++;
            }
            opers -= cur_cnt/(len + 1);
            if (opers < 0) return false; 
        }
        return true;
    }
    bool check1(string s, int numOps) {
        int n = s.size();
        string org = s;
        int cnt1 = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                s[i] = s[i]^'0'^'1';
                cnt1++;
            }
        }
        s = org;
        s[0] = s[0]^'0'^'1';
        int cnt2 = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                s[i] = s[i]^'0'^'1';
                cnt2++;
            }
        }
        return min(cnt1, cnt2) <= numOps;
    }
    int minLength(string s, int numOps) {
        int n = s.size();
        int l = 0, r = n + 1;
        while (r - l > 1) {
            int m = l + (r - l)/2;
            bool res = m != 1 ? check(m, s, numOps) : check1(s, numOps);
            if (res)
                r = m;
            else
                l = m;
        }
        return r;
    }
};