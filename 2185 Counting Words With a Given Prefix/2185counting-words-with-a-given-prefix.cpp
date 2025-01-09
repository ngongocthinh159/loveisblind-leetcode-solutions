class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for (auto &w : words) {
            int i = 0, j = 0;
            while (i < w.size() && j < pref.size()) {
                if (w[i] == pref[j]) i++, j++;
                else break;
            }
            if (j == pref.size()) ans++;
        }
        return ans;
    }
};