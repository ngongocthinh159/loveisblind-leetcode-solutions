class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for (auto c : s) {
            mp[c]++;
        }
        vector<vector<char>> v(s.size() + 1);
        for (auto &[key,val] : mp) {
            v[val].push_back(key);
        }
        string res = "";
        for (int i = v.size() - 1; i >= 1; i--) {
            if (v[i].size() != 0) {
                for (int j = 0; j < v[i].size(); j++) {
                    char cur = v[i][j];
                    for (int k = 0; k < i; k++) {
                        res += cur;
                    }
                }
            }

        }
        return res;
    }
};