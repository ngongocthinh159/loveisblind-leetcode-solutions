class Solution {
public:
    int mxCC1, mxCC2;
    bool isValid(vector<int> &freq) {
        int mx = -1, mxC;
        for (int i = 0; i < 26; i++) {
            if (mx < freq[i]) {
                mx = freq[i];
                mxC = i;
                mxCC1 = mxC;
            } else if (mx == freq[i]) {
                mxCC2 = i;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (i != mxC && freq[i] >= 2) return false;
        }
        return true;
    }
    int maxRepOpt1(string text) {
        int l = 0;
        int n = text.size();
        vector<int> freq(26);
        vector<int> mxFreq(26);
        for (auto c : text) mxFreq[c - 'a']++;
        int diff = 0;
        int ans = INT_MIN;
        for (int r = 0; r < n; r++) {
            freq[text[r] - 'a']++;
            if (freq[text[r] - 'a'] == 1) diff++;
            mxCC2 = -1;

            while (l <= r && (!isValid(freq) || diff > 2)) {
                freq[text[l] - 'a']--;
                if (freq[text[l] - 'a'] == 0) diff--;
                l++;
            }
            
            int res = INT_MAX;
            res = min(res, min(mxFreq[mxCC1], r - l + 1));
            if (mxCC2 != -1) res = max(res, min(mxFreq[mxCC2], r - l + 1));
            ans = max(ans, res);
        }
        return ans;
    }
};