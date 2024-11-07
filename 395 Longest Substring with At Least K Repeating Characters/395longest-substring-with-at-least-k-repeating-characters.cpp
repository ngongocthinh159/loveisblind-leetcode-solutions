class Solution {
public:
    int find(string &s, int k, int unique) {
        int l = 0, r = 0;
        unordered_map<char,int> M;
        int ans = 0;
        int atLeastK = 0;
        while (r < s.size()) {
            int &cnt = M[s[r]];
            cnt++;
            if (cnt == k) atLeastK++;

            while (M.size() > unique) {
                int &cnt2 = M[s[l]];
                cnt2--;
                if (cnt2 == k - 1) atLeastK--;
                if (cnt2 == 0) M.erase(s[l]);
                
                l++;
            }
            
            if (atLeastK == unique) ans = max(ans, r - l + 1);

            r++;
        }

        return ans;
    }
    int longestSubstring(string s, int k) {
        int n = s.size();
        int ans = 0;
        for (int i = 1; i <= 26; i++) {
            ans = max(ans, find(s, k, i));
        }
        return ans;
    }
};