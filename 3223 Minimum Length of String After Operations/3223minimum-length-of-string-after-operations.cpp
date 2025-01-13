class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26);
        for (auto c : s) freq[c - 'a']++;
        int ans = 0;
        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] >= 3) {
                freq[i] -= freq[i]/2 *2;
                if (freq[i] == 0) freq[i] += 2;
            }
            ans += freq[i];
        }
        return ans;
    }
};