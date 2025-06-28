class Solution {
public:
    vector<vector<int>> cToIdx;
    vector<int> cList;
    string path = "";
    string res = "";
    bool found = false;
    int freq[26]{};
    bool repeatKFrom(int k, int idx, string &cur, string &s) {
        int i = idx;
        for (int cnt = 0; cnt < k; cnt++) {
            int j = 0;
            while (i < s.size() && j < cur.size()) {
                if (s[i] != cur[j]) i++;
                else {
                    i++; j++;
                }
            }
            if (j != cur.size()) return false;
            int remainLen = (int) s.size() - i;
            if ((k - cnt - 1) * ((int) path.size()) > remainLen) return false;
        }

        return true;
    }
    void dfs(int len, int lastIdx, int k, string &s) {
        if ((int) path.size() == len) {
            if (repeatKFrom(k - 1, lastIdx + 1, path, s)) {
                found = true;
                res = path;
            }
            return;
        }
        for (int i = 0; i < (int) cList.size(); i++) {
            int c = cList[i];
            auto it = upper_bound(cToIdx[c].begin(), cToIdx[c].end(), lastIdx);
            if (it != cToIdx[c].end()) {
                int idx = it - cToIdx[c].begin();

                if ((int) cToIdx[c].size() - idx - 1 < (k - 1) * (freq[c] + 1)) continue;
                path += c + 'a';
                freq[c]++;
                dfs(len, *it, k, s);
                path.pop_back();
                freq[c]--;

                if (found) break;
            }
        }
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.size();
        cToIdx.resize(26);
        for (int i = 0; i < n; i++) {
            cToIdx[s[i] - 'a'].push_back(i);
        }
        for (int i = 0; i < 26; i++) if ((int) cToIdx[i].size() >= k) {
            cList.push_back(i);
        }
        if (cList.empty()) return "";
        reverse(cList.begin(), cList.end());
        int mxLen = n / k;
        for (int i = mxLen; i >= 1; i--) {
            dfs(i, -1, k, s);
            if (found) break;
        }
        return res;
    }
};