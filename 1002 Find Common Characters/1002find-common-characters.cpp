class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> mn_cnt(26, INT_MAX);
        for (int i = 0; i < words.size(); i++) {
            vector<int> cnt(26,0);
            for (auto c : words[i]) {
                cnt[c - 'a']++;
            }
            for (int j = 0; j < mn_cnt.size(); j++) {
                mn_cnt[j] = min(mn_cnt[j], cnt[j]);
            }
        }
        vector<string> res;
        for (int i = 0; i < mn_cnt.size(); i++) {
            for (int j = 0; j < mn_cnt[i]; j++) {
                char c = i + 'a';
                string s = "";
                s += c;
                res.push_back(s);
            }
        }
        return res;
    }
};