class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() <= 10) return {};
        unordered_map<string,int> map;
        for (int l = 0, r = 0; r < s.size(); r++) {
            if (r - l + 1 == 10) {
                string cur = s.substr(l, 10);
                int& cnt = map[cur];
                cnt++;
                l++;
            }
        }
        vector<string> res;
        for (auto& [key, value] : map) {
            if (value >= 2) res.push_back(key);
        }
        return res;
    }
};