class Solution {
public:
    string minWindow(string s, string t) {
        int diff = 0;
        vector<int> cnt1(52, 0);
        vector<int> cnt2(52, 0);
        for (auto c : t) {
            int idx;
            if ('a' <= c) idx = c - 'a' + 26;
            else idx = c - 'A';
            cnt1[idx]++;
            if (cnt1[idx] == 1) diff++;
        }
        int matched = 0;
        int l = 0, r = 0;
        int len = INT_MAX, _l, _r;
        while (r < s.size()) {
            int idx;
            if ('a' <= s[r]) idx = s[r] - 'a' + 26;
            else idx = s[r] - 'A';
            cnt2[idx]++;
            
            if (cnt1[idx] != 0 && cnt2[idx] == cnt1[idx]) matched++;
            
            while (matched >= diff) {
                if (len > (r - l + 1)) {
                    len = r - l + 1;
                    _l = l; _r = r;
                }
                
                int lidx;
                if ('a' <= s[l]) lidx = s[l] - 'a' + 26;
                else lidx = s[l] - 'A';
                cnt2[lidx]--;
                if (cnt1[lidx] != 0 && cnt2[lidx] == cnt1[lidx] - 1) matched--;
                l++;
            }
            
            r++;
        }
        if (len == INT_MAX) return "";
        else return s.substr(_l, _r - _l + 1);
    }
};