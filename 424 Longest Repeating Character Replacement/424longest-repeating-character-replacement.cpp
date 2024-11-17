class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int n = s.size();
        vector<int> freq(26);
        set<pair<int,int>,greater<pair<int,int>>> S;
        int ans = 0;
        for (int r = 0; r < n; r++) {
            S.erase({freq[s[r] - 'A'], s[r]});
            freq[s[r] - 'A']++;
            S.insert({freq[s[r] - 'A'], s[r]});

            while (l <= r && (r - l + 1) - (*S.begin()).first > k) {
                S.erase({freq[s[r] - 'A'], s[r]});
                freq[s[l] - 'A']--;
                S.insert({freq[s[r] - 'A'], s[r]});
                l++;
            }

            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};