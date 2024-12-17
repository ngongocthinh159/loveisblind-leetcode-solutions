class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string res = "";
        vector<int> freq(26);
        for (auto c : s) freq[c - 'a']++;
        int i = -1, j = -1;
        for (int k = 26 - 1; k >= 0; k--) {
            if (freq[k] && i == -1) i = k;
            else if (freq[k] && j == -1) {
                j = k; break;
            }
        }
        while (i >= 0) {
            int cnt = freq[i];
            bool stop = false;
            while (cnt > 0) {
                int will = min(cnt, repeatLimit);
                cnt -= will;
                res += string(will, i + 'a');
                if (cnt > 0) {
                    while (j >= 0 && (freq[j] == 0 || j == i)) j--;

                    if (j == -1) {
                        stop = true;
                        break;
                    } else {
                        res += j + 'a';
                        freq[j]--;
                    }
                }
            }
            if (stop) break;
            freq[i] = 0;
            while (i >= 0 && freq[i] == 0) i--;
        }
        return res;
    }
};